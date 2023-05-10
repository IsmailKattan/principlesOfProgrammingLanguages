#include <tacticC.h>

// conctructor
TacticC new_TacticC(int ID)
{
    TacticC this = (TacticC)malloc(sizeof(struct TACTICC)); // allocate memory for new object (TACTICC)
    this->inherited = new_Tactic(ID,"C taktiği"); // create object from base struct
    /*pointer of overriding function*/
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
    int ID = this->getID(this);
    srand(time(NULL) + (ID*ID));
    return rand() % 1000; // producing a number between 0 and 1000
}
// (@overriding) get function for ID;
int getIDC(const TacticC this)
{
    return this->inherited->getID(this->inherited);
}
// (@overriding) get function for name 
char* getNameC(const TacticC this)
{
    return this->inherited->getName(this->inherited);
}
// disconstructor 
void delete_TacticC(const TacticC this)
{
    if (this != NULL) {
        this->inherited->delete(this->inherited);
        free(this);
    }
}
