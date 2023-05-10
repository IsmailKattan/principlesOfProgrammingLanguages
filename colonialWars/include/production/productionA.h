#ifndef PRODUCTIONA_H
#define PRODUCTIONA_H

#include <production.h>

struct PRODUCTIONA
{
    /*properties*/
    Production inherited;
    char* name;
    /*overriding methods*/
    int (*getStock)(struct PRODUCTIONA*);
    void (*setStock)(struct PRODUCTIONA*,int);
    /*other methods*/
    int (*produce)(struct PRODUCTIONA*);
    Production (*getProduction)(struct PRODUCTIONA*);
    char* (*getName)(struct PRODUCTIONA*);
    void (*delete)(struct PRODUCTIONA*);
};

typedef struct PRODUCTIONA* ProductionA;

// constructor
ProductionA new_ProducionA(int);
// produce function
int produceA(const ProductionA);
// get base function
Production getProductionA(const ProductionA);
// returns the name of production technic
char* getNamePA(const ProductionA);
// (@overriding) get function for stock value
int getStockA(const ProductionA);
// (@overriding) set function for stock value
void setStockA(const ProductionA,int);
// destructor
void delete_ProductionA(const ProductionA); 

#endif