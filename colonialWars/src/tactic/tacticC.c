#include <tacticC.h>

// conctructor
TacticC new_TacticC(int ID, char* name)
{
    TacticC this = (TacticC)malloc(sizeof(struct TACTICC)); // allocate memory for new object (TACTICC)
    this->inherited = new_Tactic(ID,name); // create object from base struct
    /*pointer of overloading function*/
    this->getID = &getIDC;
    this->getName = &getNameC;
    /*other methods*/
    this->getTactic = &getTacticC; // get address of base struct (function pointer)
    this->war = &warC; // war function for C tactic
    this->delete = &delete_TacticC; // destructor (function pointer)
    
    return this;
}
// get base tactic;
Tactic getTacticC(const TacticC this)
{
    return this->inherited;
}
// war function for C tactic
int warC(const TacticC this)
{
    int ID = (this->getID(this->getTactic(this)));
    srand(time(NULL) + (ID*ID));
    return rand() % 1000; // producing a number between 0 and 1000
}
// (@overloading) get function for ID;
int getIDC(const Tactic this)
{
    return this->getID(this);
}
// (@overloading) get function for name 
char* getNameC(const Tactic this)
{
    return this->getName(this);
}
// disconstructor 
void delete_TacticC(const TacticC this)
{
    if (this != NULL) {
        delete_Tactic(this->inherited);
        free(this);
    }
}
