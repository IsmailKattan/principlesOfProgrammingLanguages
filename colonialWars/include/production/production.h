#ifndef PRODUCTION_H
#define PRODUCTION_H

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef enum Rool{true,false}boolean;

struct PRODUCTION
{
    /*properties*/
    int stock;
    /*methods (function pointers)*/
    int (*getStock)(struct PRODUCTION*);
    void (*setStock)(struct PRODUCTION*,int);
    int (*produce)(struct PRODUCTION*);
    void (*delete)(struct PRODUCTION*);

};

typedef struct PRODUCTION* Production;

// constructor
Production new_Producion(int);
// get function for stock value
int getStock(const Production);
// set function for stock value
void setStock(const Production,int);
// produce function
int produce(const Production);
// destructor 
void delete_Production(const Production);

#endif