#ifndef TACTIC_H
#define TACTIC_H

#include <stdlib.h>
#include <stdio.h>

typedef enum Rool{true,false}boolean;

struct TACTIC
{
    /*properties*/
    int ID; // ID of Tactic
    char* name; // name of Tactic 
    /*metods (function pointer)*/
    int (*getID)(struct TACTIC*);
    char* (*getName)(struct TACTIC*);
    void (*delete)(struct TACTIC*);
};

typedef struct TACTIC* Tactic;

// constructor
Tactic new_Tactic(int, char*); 
// get function for ID;
int getID(const Tactic);
// get function for name 
char* getName(const Tactic);
// destructor 
void delete_Tactic(const Tactic); 



#endif