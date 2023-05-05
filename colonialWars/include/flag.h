#ifndef FLAG_H
#define FLAG_H

#include <stdlib.h>
#include <stdio.h>

//our struct
struct FLAG
{
    char flg;
    //get function for flg value
    char (*getFlg)(struct FLAG*);
    //disconstructor
    void (*delete)(struct FLAG*);
};

typedef struct FLAG* Flag;

//constructor
Flag new_Flag(char);
//get function for flg value
char getFlg(const Flag);
//disconstructor
void delete_Flag(const Flag);

#endif