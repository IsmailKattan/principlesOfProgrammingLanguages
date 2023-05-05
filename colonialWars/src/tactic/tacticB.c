#include <tacticB.h>

// conctructor
TacticB new_TacticB(int ID, char* name) 
{
    TacticB this = (TacticB)malloc(sizeof(struct TACTICB)); // allocate memory for new object (TACTICB)
    this->inherited = new_Tactic(ID,name); // create object from base struct
    /*pointer of overloading function*/
    this->getID = &getIDB;
    this->getName = &getNameB;
    /*other methods*/
    this->getTactic = &getTacticB; // get address of base struct (function pointer)
    this->war = &warB; // war function for B tactic
    this->delete = &delete_TacticB; // destructor (function pointer)

    return this;
}
// get base tactic;
Tactic getTacticB(const TacticB this)
{
    return this->inherited;
}
// war function for B tactic
int warB(const TacticB this)
{
    int ID = (this->getID(this->getTactic(this)));
    srand(time(NULL) + (15*ID*ID));
    return rand() % 1000; // producing a number between 0 and 1000
}
// (@overloading) get function for ID;
int getIDB(const Tactic this)
{
    return this->getID(this);
}
// (@overloading) get function for name 
char* getNameB(const Tactic this)
{
    return this->getName(this);
}
// destructor 
void delete_TacticB(const TacticB this)
{
    if (this != NULL) {
        delete_Tactic(this->inherited);
        free(this);
    }
}
