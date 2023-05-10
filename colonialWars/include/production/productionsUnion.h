#ifndef PRODUCTIONSUNION_H
#define PRODUCTIONSUNION_H

#include <productionA.h>
#include <productionB.h>
#include <productionC.h>

struct PRODUCTIONS  
{
    ProductionA _production_A_;
    ProductionB _production_B_;
    ProductionC _production_C_;
    int ID;
    int (*getID)(struct PRODUCTIONS*);
    int (*produce)(struct PRODUCTIONS*);
    int (*getStock)(struct PRODUCTIONS*);
    void (*setStock)(struct PRODUCTIONS*,int);
    char* (*getName)(struct PRODUCTIONS*);
    void (*delete)(struct PRODUCTIONS*);
};

typedef struct PRODUCTIONS* Productions;

//constructor 
Productions new_productions(int);
// getID
int getIDP(const Productions);
// (@overriding) produce function
int produceAll(const Productions);
// (@overriding) get function for stock value
int getStockAll(const Productions);
// (@overriding) set function for stock value
void setStockAll(const Productions,int);
// (@overriding) returns the name of production technic
char* getNameAllP(const Productions);
// destructor 
void delete_Producctions(const Productions);


#endif