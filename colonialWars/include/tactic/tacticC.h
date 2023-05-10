#ifndef TACTICC_H
#define TACTICC_H

#include <tactic.h>
#include <time.h>

struct TACTICC
{
    /*properties*/
    Tactic inherited; // base 
    /*methods*/
    Tactic (*getTactic)(struct TACTICC*); // get base address (function pointer)
    int (*war)(struct TACTICC*); // war function for C tactic
    /***********overriding from base***********/
    int (*getID)(struct TACTICC*);
    char* (*getName)(struct TACTICC*);
    /*******************************************/
    void (*delete)(struct TACTICC*);  // destructor (function pointer)
};

typedef struct TACTICC* TacticC;

// conctructor
TacticC new_TacticC(int);
// get base tactic;
Tactic getTacticC(const TacticC);
// war function for C tactic
int warC(const TacticC);
// (@overriding) get function for ID;
int getIDC(const TacticC);
// (@overriding) get function for name 
char* getNameC(const TacticC);
// destructor
void delete_TacticC(const TacticC);

#endif 