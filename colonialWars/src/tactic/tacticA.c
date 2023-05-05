#include <tacticA.h>

// conctructor
TacticA new_TacticA(int ID, char* name)
{
    TacticA this = (TacticA)malloc(sizeof(struct TACTICA)); // allocate memory for new object (TACTICA)
    this->inherited = new_Tactic(ID,name); // create object from base struct
    /*pointer of overloading function*/
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
    int ID = (this->getID(this->getTactic(this)));
    srand(time(NULL) + ((ID+10)*(ID+10)));
    return rand() % 1000; // producing a number between 0 and 1000
}
// (@overloading) get function for ID;
int getIDA(const Tactic this)
{
    return this->getID(this);
}
// (@overloading) get function for name 
char* getNameA(const Tactic this)
{
    return this->getName(this);
}
// destructor 
void delete_TacticA(const TacticA this)
{
    if (this != NULL) {
        delete_Tactic(this->inherited);
        free(this);
    }
}
