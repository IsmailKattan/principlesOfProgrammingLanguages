#ifndef FLAG_H
#define FLAG_H

#include <stdlib.h>
#include <stdio.h>

//our struct
struct FLAG
{
    char flg;
    //get function for flg value
    char (*getCH)(struct FLAG*);
    //set function for flg value 
    void (*setCH)(struct FLAG*, char);
    //disconstructor
    void (*delete)(struct FLAG*);
};

typedef struct FLAG* Flag;

//constructor
Flag new_Flag(char);
//get function for flg value
char getFlg(const Flag);
//set function for flg value
void setFlg(const Flag, char);
//disconstructor
void delete_Flag(const Flag);

#endif