#ifndef TACTICSUNION_H
#define TACTICSUNION_H

#include "tacticA.h"
#include "tacticB.h"
#include "tacticC.h"

struct TACTICS
{
    TacticA _tactic_A_;
    TacticB _tactic_B_;
    TacticC _tactic_C_;
    int ID;
    int (*war)(struct TACTICS*);
    int (*getID)(struct TACTICS*);
    char* (*getName)(struct TACTICS*);
    void (*delete)(struct TACTICS*);
};

typedef struct TACTICS* Tactics;

// constructor 
Tactics new_Tactics(int);
// (@overriding) war function for C tactic
int warAll(const Tactics);
// (@overriding) get function for ID;
int getIDAll(const Tactics);
// (@overriding) get function for name 
char* getNameAll(const Tactics);
// destructor
void delete_tactics(const Tactics);


#endif