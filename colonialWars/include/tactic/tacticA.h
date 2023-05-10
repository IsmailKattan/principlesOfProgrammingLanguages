#ifndef TACTICA_H
#define TACTICA_H
 
#include <tactic.h>
#include <time.h>

struct TACTICA
{
    /*properties*/
    Tactic inherited; // base
    /*methods*/ 
    Tactic (*getTactic)(struct TACTICA*); // get base address (function pointer)
    int (*war)(struct TACTICA*); // war function for A tactic
    /***********overriding from base***********/
    int (*getID)(struct TACTICA*);
    char* (*getName)(struct TACTICA*);
    /*******************************************/
    void (*delete)(struct TACTICA*);  // destructor (function pointer)
};

typedef struct TACTICA* TacticA;

// conctructor
TacticA new_TacticA(int);
// get base tactic;
Tactic getTacticA(const TacticA);
// war function for A tactic
int warA(const TacticA);
// (@overriding) get function for ID
int getIDA(const TacticA);
// (@overriding) get function for name 
char* getNameA(const TacticA);
// destructor 
void delete_TacticA(const TacticA);

#endif 