#include "play.h"

void getIntArray(int **arr, int *size)
{
    printf("Enter the size of the array: ");
    scanf("%d", size);

    *arr = malloc((*size) * sizeof(int));
    printf("Enter %d integers:\n", *size);

    for (int i = 0; i < *size; i++) {
        scanf("%d", &((*arr)[i]));
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
        printf("value inserted\n");

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
    int random_ascii = rand() % 128; 
    char random_char = (char) random_ascii; 
    return random_char;
}   
