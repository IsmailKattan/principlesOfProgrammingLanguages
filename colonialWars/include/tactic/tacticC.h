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
    /***********overloading from base***********/
    int (*getID)(struct TACTIC*);
    char* (*getName)(struct TACTIC*);
    /*******************************************/
    void (*delete)(struct TACTICC*);  // destructor (function pointer)
};

typedef struct TACTICC* TacticC;

// conctructor
TacticC new_TacticC(int,char*);
// get base tactic;
Tactic getTacticC(const TacticC);
// war function for C tactic
int warC(const TacticC);
// (@overloading) get function for ID;
int getIDC(const Tactic);
// (@overloading) get function for name 
char* getNameC(const Tactic);
// destructor
void delete_TacticC(const TacticC);

#endif 