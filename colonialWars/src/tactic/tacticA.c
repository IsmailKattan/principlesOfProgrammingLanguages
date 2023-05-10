#include <tacticA.h>

// conctructor
TacticA new_TacticA(int ID)
{
    TacticA this = (TacticA)malloc(sizeof(struct TACTICA)); // allocate memory for new object (TACTICA)
    this->inherited = new_Tactic(ID,"A taktiği"); // create object from base struct
    /*pointer of overriding function*/
    this->getID = &getIDA;
    this->getName = &getNameA;
    /*other methods*/
    this->getTactic = &getTacticA; // get address of base struct (function pointer)
    this->war = &warA; // war function for A tactic
    this->delete = &delete_TacticA; // destructor (function pointer)
    
    return this;
}
// get base tactic;
Tactic getTacticA(const TacticA this)
{
    return this->inherited;
}
// war function for A tactic
int warA(const TacticA this)
{
    int ID = this->getID(this);
    srand(time(NULL) + ((ID+10)*(ID+10)));
    return rand() % 1000; // producing a number between 0 and 1000
}
// (@overriding) get function for ID;
int getIDA(const TacticA this)
{
    return this->inherited->getID(this->inherited);
}
// (@overriding) get function for name 
char* getNameA(const TacticA this)
{
    return this->inherited->getName(this->inherited);
}
// destructor 
void delete_TacticA(const TacticA this)
{
    if (this != NULL) {
        this->inherited->delete(this->inherited);
        free(this);
    }
}
