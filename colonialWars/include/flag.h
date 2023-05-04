#ifndef FLAG_H
#define FLAG_H

#include <stdlib.h>
#include <stdio.h>

typedef enum Rool{false,true}boolean;
//our struct
struct FLAG
{
    char flg;

};

typedef struct FLAG Flag;

//constructor
Flag new_Flag(char);
//get function for flg value
char getFlg(const Flag);
//disconstructor
void delete_Flag(const Flag);

#endif