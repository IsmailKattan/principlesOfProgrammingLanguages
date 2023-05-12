#include "play.h"

int main()
{   
    system("cls");
    DynamicArray array;
    createColonies(&array);
    system("cls");
    printf("coloniler hakkinda:\n");
    printinfo(&array);
    system("pause");
    system("cls");
    printArray(&array);
    system("pause");
    int tour = 0;
    while (1)
    {
        tour++;
        system("cls");
        colonialWar(&array);
        int counter = 0;
        for (size_t i = 0; i < array.size; i++)
        {
            if(get(&array,i)->isViable(get(&array,i)))
                counter++;
        }
        if(counter<=1)
        {
            printf("oyun bitmistir artik program sonlandirilacak\n");
            system("pause");
            printf("tur:\t%d\n",tour);
            printArray(&array);
            break;
        }
        printf("tur:\t%d\n",tour);
        printArray(&array);
        system("pause");
    }
    freeArray(&array);
    
    return 0;
}
    // Flag flag = new_Flag('@');
    // printf("Flag : %c\n",flag->getCH(flag));
    // flag->setCH(flag,'$');
    // printf("New flag : %c\n",flag->getCH(flag));
    // flag->delete(flag);
    // printf("------------------------------------------------01------------------------------------------------\n");
    // Production pro1 = new_Producion(105);
    // printf("food stock in production %d\n",pro1->getStock(pro1));
    // pro1->setStock(pro1,pro1->getStock(pro1)+pro1->produce(pro1));
    // printf("new food stock in Production %d\n",pro1->getStock(pro1));
    // pro1->delete(pro1);
    // printf("------------------------------------------------02------------------------------------------------\n");
    // ProductionA pro2 = new_ProducionA(105);
    // printf("food stock in productionA %d\n",pro2->getStock(pro2));
    // pro2->setStock(pro2,pro2->getStock(pro2)+pro2->produce(pro2));
    // printf("new food stock in ProductionA %d\n",pro2->getStock(pro2));
    // pro2->delete(pro2);
    // printf("------------------------------------------------03------------------------------------------------\n");
    // ProductionB pro3 = new_ProducionB(105);
    // printf("food stock in productionB %d\n",pro3->getStock(pro3));
    // pro3->setStock(pro3,pro3->getStock(pro3)+pro3->produce(pro3));
    // printf("new food stock in ProductionB %d\n",pro3->getStock(pro3));
    // pro3->delete(pro3);
    // printf("------------------------------------------------04------------------------------------------------\n");
    // ProductionC pro4 = new_ProducionC(105);
    // printf("food stock in productionC %d\n",pro4->getStock(pro4));
    // pro4->setStock(pro4,pro4->getStock(pro4)+pro4->produce(pro4));
    // printf("new food stock in ProductionC %d\n",pro4->getStock(pro4));
    // pro4->delete(pro4);
    // printf("------------------------------------------------05------------------------------------------------\n");
    // Productions pro5 = new_productions(100);
    // printf("the ID is %d\n",pro5->ID);
    // printf("food stock in productions %d\n",pro5->getStock(pro5));
    // pro5->setStock(pro5,pro5->getStock(pro5)+pro5->produce(pro5));
    // printf("new food stock in productions %d\n",pro5->getStock(pro5));
    // pro5->delete(pro5);
    // printf("------------------------------------------------06------------------------------------------------\n");
    // Productions pro6 = new_productions(101);
    // printf("the ID is %d\n",pro5->ID);
    // printf("food stock in productions %d\n",pro6->getStock(pro6));
    // pro6->setStock(pro6,pro6->getStock(pro6)+pro6->produce(pro6));
    // printf("new food stock in productions %d\n",pro6->getStock(pro6));
    // pro6->delete(pro6);
    // printf("------------------------------------------------07------------------------------------------------\n");
    // Productions pro7 = new_productions(102);
    // printf("the ID is %d\n",pro5->ID);
    // printf("food stock in productions %d\n",pro7->getStock(pro7));
    // pro7->setStock(pro7,pro7->getStock(pro7)+pro7->produce(pro7));
    // printf("new food stock in productions %d\n",pro7->getStock(pro7));
    // pro7->delete(pro7);
    // printf("------------------------------------------------08------------------------------------------------\n");
    // TacticA T1 = new_TacticA(123,"A taktiği");
    // printf("ID   :%d\n",T1->getID(T1));
    // printf("Name :%s\n",T1->getName(T1));
    // printf("savaş!!! : %d\n", T1->war(T1));
    // T1->delete(T1);
    // printf("------------------------------------------------09------------------------------------------------\n");
    // TacticB T2 = new_TacticB(123,"B taktiği");
    // printf("ID   :%d\n",T2->getID(T2));
    // printf("Name :%s\n",T2->getName(T2));
    // printf("savaş!!! : %d\n", T2->war(T2));
    // T2->delete(T2);
    // printf("------------------------------------------------10-----------------------------------------------\n");
    // TacticC T3 = new_TacticC(123,"C taktiği");
    // printf("ID   :%d\n",T3->getID(T3));
    // printf("Name :%s\n",T3->getName(T3));
    // printf("savaş!!! : %d\n", T3->war(T3));
    // T3->delete(T3);
    // printf("------------------------------------------------11-----------------------------------------------\n");
    // Tactics T4 = new_Tactics(100,"A taktiği");
    // printf("ID   :%d\n",T4->getID(T4));
    // printf("Name :%s\n",T4->getName(T4));
    // printf("savaş!!! : %d\n", T4->war(T4));
    // T4->delete(T4);
    // printf("------------------------------------------------12-----------------------------------------------\n");
    // Tactics T5 = new_Tactics(101,"B taktiği");
    // printf("ID   :%d\n",T5->getID(T5));
    // printf("Name :%s\n",T5->getName(T5));
    // printf("savaş!!! : %d\n", T5->war(T5));
    // T5->delete(T5);
    // printf("------------------------------------------------13-----------------------------------------------\n");
    // Tactics T6 = new_Tactics(102,"C taktiği");
    // printf("ID   :%d\n",T6->getID(T6));
    // printf("Name :%s\n",T6->getName(T6));
    // printf("savaş!!! : %d\n", T6->war(T6));
    // T6->delete(T6);
    // printf("------------------------------------------------14-----------------------------------------------\n");



    // Flag flag = new_Flag('%');
    // Tactics tactic = new_Tactics(100,"B taktiği");
    // Productions production = new_productions(10000);
    // Colony c = new_Colony(100,flag,tactic,production);
    // printf("testing colony methods\n");
    // printf("current population : %d\t",c->getPopulation(c));
    // c->setPopulation(c,150);
    // printf("new population     : %d\n",c->getPopulation(c));
    // printf("current Wins       : %d\t",c->getWins(c));
    // c->setWins(c,5);
    // printf("new population     : %d\n",c->getWins(c));
    // printf("current Defeats    : %d\t",c->getDefeats(c));
    // c->setDefeats(c,3);
    // printf("new Defeats        : %d\n",c->getDefeats(c));
    // printf("current flag       : %c\t",c->getflag(c));
    // c->setflag(c,'#');
    // printf("new flag           : %c\n",c->getflag(c));
    // printf("WAR!!!             : %d\n",c->war(c));
    // printf("current food stock : %d\t",c->getStock(c));
    // c->setStock(c,c->getStock(c)+c->produce(c));
    // printf("new food stock     : %d\n",c->getStock(c));
    // c->delete(c);