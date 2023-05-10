#ifndef TACTICB_H
#define TACTICB_H
 
#include <tactic.h>
#include <time.h>

struct TACTICB
{
    /*properties*/
    Tactic inherited;  // base
    /*methods*/ 
    Tactic (*getTactic)(struct TACTICB*); // get base address (function pointer)
    int (*war)(struct TACTICB*); // war function for B tactic
    /***********overriding from base***********/
    int (*getID)(struct TACTICB*); 
    char* (*getName)(struct TACTICB*);
    /******************************************/
    void (*delete)(struct TACTICB*); // destructor (function pointer)
};

typedef struct TACTICB* TacticB;

// conctructor
TacticB new_TacticB(int);
// get base tactic;
Tactic getTacticB(const TacticB);
// war function for B tactic
int warB(const TacticB);
// (@overriding) get function for ID
int getIDB(const TacticB);
// (@overriding) get function for name 
char* getNameB(const TacticB);
// destructor 
void delete_TacticB(const TacticB);

#endif 