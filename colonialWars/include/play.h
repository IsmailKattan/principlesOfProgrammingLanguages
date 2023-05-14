#ifndef PLAY_H
#define PLAY_H

#include "dynamicArray.h"
#include <string.h>

// user puts array of int (array ,size)
void getIntArray(int**, int*);
// void create colonies and puts them in linkedlist then returns the list
void createColonies();
// returns randum number (seed,mood) 
int retrand(int,int);
// picks char to be flag for colony
char pickFlag(int);
// war breaks out between two colonies
void fighting(Colony,Colony);
// set changes after the fighting
void setFightingResults(Colony,Colony,float);
// colonial war 
void colonialWar(DynamicArray*);
// set changes after the war
void setPeaceResult(DynamicArray*);
// prints informations about colonies 
void printinfo(DynamicArray*);
#endif