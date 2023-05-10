#include <tacticB.h>

// conctructor
TacticB new_TacticB(int ID) 
{
    TacticB this = (TacticB)malloc(sizeof(struct TACTICB)); // allocate memory for new object (TACTICB)
    this->inherited = new_Tactic(ID,"B taktiği"); // create object from base struct
    /*pointer of overriding function*/
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
    int ID = this->getID(this);
    srand(time(NULL) + (15*ID*ID));
    return rand() % 1000; // producing a number between 0 and 1000
}
// (@overriding) get function for ID;
int getIDB(const TacticB this)
{
    return this->inherited->getID(this->inherited);
}
// (@overriding) get function for name 
char* getNameB(const TacticB this)
{
    return this->inherited->getName(this->inherited);
}
// destructor 
void delete_TacticB(const TacticB this)
{
    if (this != NULL) {
        this->inherited->delete(this->inherited);
        free(this);
    }
}
