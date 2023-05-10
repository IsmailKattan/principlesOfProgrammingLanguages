#ifndef PLAY_H
#define PLAY_H

#include "dynamicArray.h"

// user puts array of int (array ,size)
void getIntArray(int**, int*);
// void create colonies and puts them in linkedlist then returns the list
void createColonies();
// returns randum number (seed,mood) 
int retrand(int,int);
// picks char to be flag for colony
char pickFlag(int);

#endif