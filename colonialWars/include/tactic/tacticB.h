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
    /***********overloading from base***********/
    int (*getID)(struct TACTIC*); 
    char* (*getName)(struct TACTIC*);
    /******************************************/
    void (*delete)(struct TACTICB*); // destructor (function pointer)
};

typedef struct TACTICB* TacticB;

// conctructor
TacticB new_TacticB(int,char*);
// get base tactic;
Tactic getTacticB(const TacticB);
// war function for B tactic
int warB(const TacticB);
// (@overloading) get function for ID
int getIDB(const Tactic);
// (@overloading) get function for name 
char* getNameB(const Tactic);
// destructor 
void delete_TacticB(const TacticB);

#endif 