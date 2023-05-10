#ifndef PRODUCTIONC_H
#define PRODUCTIONC_H

#include <production.h>

struct PRODUCTIONC
{
    /*properties*/
    Production inherited;
    char* name; 
    /*overriding methods*/
    int (*getStock)(struct PRODUCTIONC*);
    void (*setStock)(struct PRODUCTIONC*,int);
    /*other methods*/
    int (*produce)(struct PRODUCTIONC*);
    Production (*getProduction)(struct PRODUCTIONC*);
    char* (*getName)(struct PRODUCTIONC*);
    void (*delete)(struct PRODUCTIONC*);
};

typedef struct PRODUCTIONC* ProductionC;

// constructor
ProductionC new_ProducionC(int);
// produce function
int produceC(const ProductionC);
// get base function
Production getProductionC(const ProductionC);
// returns the name of production technic
char* getNamePC(const ProductionC);
// (@overriding) get function for stock value
int getStockC(const ProductionC);
// (@overriding) set function for stock value
void setStockC(const ProductionC,int);
// destructor
void delete_ProductionC(const ProductionC);
 
#endif