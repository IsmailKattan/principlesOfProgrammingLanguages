#ifndef COLONY_H
#define COLONY_H

#include <flag.h>
#include <tactic/tacticsUnion.h>
#include <production/productionsUnion.h>

struct COLONY
{
    /*properties*/
    int population;
    int wins;
    int defeats;
    Flag flag;
    Productions production;
    Tactics tactic;
    
    /*methods*/
    int (*getPopulation)(struct COLONY*);
    int (*getWins)(struct COLONY*);
    int (*getDefeats)(struct COLONY*);
    Productions (*getProduction)(struct COLONY*);
    Tactics (*getTactic)(struct COLONY*);
    void (*setPopulation)(struct COLONY*,int);
    void (*setWins)(struct COLONY*,int);
    void (*setDefeats)(struct COLONY*,int);
    void (*setProduction)(struct COLONY*,Productions);
    void (*setTactic) (struct COLONY*,Tactics);
    /*overiding methods*/
    char (*getflag)(struct COLONY*);
    void (*setflag)(struct COLONY*, char);
    int  (*getStock)(struct COLONY*);
    void (*setStock)(struct COLONY*, int);
    int (*produce)(struct COLONY*);
    int (*war)(struct COLONY*);

    // destructor
    void (*delete)(struct COLONY*);
};

typedef struct COLONY* Colony;

// constructor
Colony new_Colony(int,Flag,Tactics,Productions);
/****************get functions****************/
// returns the population of colony 
int getPopulation(const Colony);
// returns the number of wins 
int getWins(const Colony);
// returns the number of defeats
int getDefeats(const Colony);
// returns the flag of colony
Productions getProduction(const Colony);
// return Union of Tactics
Tactics getTactic(const Colony);
/****************set functions****************/
// sets the population of colony 
void setPopulation(const Colony,int);
// sets the number of wins 
void setWins(const Colony,int);
// sets the number of defeats
void setDefeats(const Colony,int);
// sets the flag of colony
void setProduction(const Colony,Productions);
// sets the tactic of colony 
void setTactic(const Colony,Tactics);
// destructor
void delete_Colony(const Colony);
/*overriding methods*/
/*FLAG**/
// (@overriding) get function for flg value
char getFlg_forColony(const Colony);
// (@overriding) set function for flg value
void setFlg_forColony(const Colony, char);
/*Productions*/
// (@overriding) get function for stock value
int getStock_forColony(const Colony);
// (@overriding) set function for stock value
void setStock_forColony(const Colony,int);
// (@overriding) produce function
int produce_forColony(const Colony);
// (@overriding) war function 
int war_forColony(const Colony);
#endif 