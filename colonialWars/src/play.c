#include "play.h"

void getIntArray(int **array, int *capacity)
{
    int num;
    char input[1000];
    printf("savasacak kolonilerin poplasyonlari giriniz\n");
    printf("ornek giris bicimi \"10 20 145 165 8 472 1365 7 36\" :\t");
    fgets(input, 1000, stdin);
    *capacity = 0; 
    *array = NULL; 
    char* token = strtok(input, " ");
    while (token != NULL) 
    {
        // convert the token to an integer
        num = atoi(token);

        // increase the array capacity by 1
        *capacity += 1;
        *array = realloc(*array, *capacity * sizeof(int));

        // check if memory reallocation was successful
        if (*array == NULL) {
            printf("Alan belirleme hatasi ./src/play.c>getIntArray\n");
            free(*array);
            return;
        }

        // store the integer in the array
        (*array)[*capacity - 1] = num;

        // get the next token
        token = strtok(NULL, " ");
    }
}





void createColonies(DynamicArray* array)
{
    int *arr;
    int size;
    getIntArray(&arr,&size);
    initialize(array,size);
    for(size_t i = 0; i < size; i++)
    {
        //population
        int population = arr[i];
        //flag
        Flag flag = new_Flag(pickFlag(i));
        //tactic
        Tactics tactic = new_Tactics(arr[i]);
        //prodeuction & stock
        int stock = (arr[i])*(arr[i]);
        Productions production = new_productions(stock);
        //colony
        Colony colony = new_Colony(population,flag,tactic,production);
        append(array,colony);

    }
}
// returns randum number (seed,mood) 
int retrand(int seed,int mood)
{
    srand(time(NULL)+seed);
    return rand()%mood;
}
// picks char to be flag for colony
char pickFlag(int seed)
{
    srand(time(NULL) + seed); 
    int random_ascii = rand() % 93; 
    char random_char = (char) (random_ascii + '!'); 
    return random_char;
}
// war breaks out between two colonies
void fighting(Colony c1,Colony c2)
{
    int c1_point = c1->war(c1);
    int c2_point = c2->war(c2);
    // get the rate
    float rate = (float)(c1_point-c2_point)/1000;
    if (rate<0)
    {
        rate = rate * (-1);
    }
    if(c1_point>c2_point)
    {
        setFightingResults(c1,c2,rate);
    }
    else if(c1_point<c2_point)
    {
        setFightingResults(c2,c1,rate);
    }
    else
    {
        if(c1->getPopulation(c1)>c2->getPopulation(c2))
        {
            setFightingResults(c1,c2,rate);
        }
        else if(c1->getPopulation(c1)<c2->getPopulation(c2))
        {
            setFightingResults(c2,c1,rate);
        }
        else
        {
            srand(time(NULL));
            if(rand()%2)
            {
                setFightingResults(c2,c1,rate);
            }
            else
            {
                setFightingResults(c1,c2,rate);
            }
        }
    }
}
// set changes after the war
void setFightingResults(Colony winner,Colony loser,float rate)
{
    // set wins and defeats
    winner->setWins(winner,winner->getWins(winner)+1);
    loser->setDefeats(loser,loser->getDefeats(loser)+1);
    // set the population of the loser
    loser->setPopulation(loser,loser->getPopulation(loser)-loser->getPopulation(loser)*rate);
    // get losed stock 
    int losedStock = loser->getStock(loser)*rate;
    // set the stock of the colonies 
    loser->setStock(loser,loser->getStock(loser)-losedStock);
    winner->setStock(winner,winner->getStock(winner)+losedStock);
}
// colonial war 
void colonialWar(DynamicArray* array)
{
    setPeaceResult(array);
    int size = 0;
    for (size_t i = 0; i < array->size; i++)
    {
        if(get(array,i)->isViable(get(array,i)))
            size++;
    }
    DynamicArray viables;
    initialize(&viables,size);
    for (size_t i = 0; i < array->size; i++)
    {
        if(get(array,i)->isViable(get(array,i)))
        {
            append(&viables,get(array,i));
        }
    }
    for (size_t i = 0; i < viables.size; i++)
    {
        /*
        i: j j j j 
        0:
        1: 0
        2: 0 1
        3: 0 1 2
        4: 0 1 2 3
        5: 0 1 2 3 4
        */
        for (size_t j = 0; j < i; j++)
        {
            fighting(get(&viables,i),get(&viables,j));
        }
    }
    int j = 0;
    for (size_t i = 0; i < array->size; i++)
    {
        if(get(array,i)->isViable(get(array,i)))
        {
            set(array,i,get(&viables,j));
            j++;
        }
    }
    freeArray(&viables);
}
// set changes after the war
void setPeaceResult(DynamicArray* array)
{
    int size = 0;
    for (size_t i = 0; i < array->size; i++)
    {
        if(get(array,i)->isViable(get(array,i)))
            size++;
    }
    DynamicArray viables;
    initialize(&viables,size);
    for (size_t i = 0; i < array->size; i++)
    {
        if(get(array,i)->isViable(get(array,i)))
        {
            append(&viables,get(array,i));
        }
    }
    for (size_t i = 0; i < viables.size; i++)
    {
        Colony c = get(&viables,i);
        c->setPopulation(c,c->getPopulation(c)*(1.2));
        c->setStock(c,c->getStock(c)-2*c->getPopulation(c));
    }
    int j = 0;
    for (size_t i = 0; i < array->size; i++)
    {
        if(get(array,i)->isViable(get(array,i)))
        {
            set(array,i,get(&viables,j));
            j++;
        }
    }
    freeArray(&viables);
}
// prints informations about colonies 
void printinfo(DynamicArray* array)
{
    printf("| Coloni | populasyon | Savas Taktigi | yemek Stogu | Uretim Teknigi |\n");
    printf("+--------+------------+---------------+-------------+----------------+\n");
    for (size_t i = 0; i < array->size; i++)
    {
        Colony c = get(array,i);
        printf("|%-*c|%-*d|%-*s|%-*d|%-*s|\n",8,c->getflag(c),12,c->getPopulation(c),16,c->getTactic(c)->getName(c->getTactic(c)),13,c->getStock(c),17,c->getProduction(c)->getName(c->getProduction(c)));
    }
}