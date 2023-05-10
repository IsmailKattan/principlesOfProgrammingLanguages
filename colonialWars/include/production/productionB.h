#ifndef PRODUCTIONB_H
#define PRODUCTIONB_H

#include <production.h>

struct PRODUCTIONB
{
    /*properties*/
    Production inherited;
    char* name;
    /*overriding methods*/
    int (*getStock)(struct PRODUCTIONB*);
    void (*setStock)(struct PRODUCTIONB*,int);
    /*other methods*/
    int (*produce)(struct PRODUCTIONB*);
    Production (*getProduction)(struct PRODUCTIONB*);
    char* (*getName)(struct PRODUCTIONB*);
    void (*delete)(struct PRODUCTIONB*);
};

typedef struct PRODUCTIONB* ProductionB;

// constructor
ProductionB new_ProducionB(int);
// produce function
int produceB(const ProductionB);
// get base function
Production getProductionB(const ProductionB);
// returns the name of production technic
char* getNamePB(const ProductionB);
// (@overriding) get function for stock value
int getStockB(const ProductionB);
// (@overriding) set function for stock value
void setStockB(const ProductionB,int);
// destructor
void delete_ProductionB(const ProductionB); 

#endif