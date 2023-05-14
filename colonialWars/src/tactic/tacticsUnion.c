#include "tacticsUnion.h"

// constructor 
Tactics new_Tactics(int ID)
{
    Tactics this = (Tactics)malloc(sizeof(struct TACTICS));
    if(ID<0)
        ID = ID*(-1);
    this->ID = ID % 3;
    switch (this->ID)
    {
    case 0:
        this->_tactic_A_ = new_TacticA(ID);
        break;
    case 1:
        this->_tactic_B_ = new_TacticB(ID);
        break;
    case 2: 
        this->_tactic_C_ = new_TacticC(ID);
        break;
    default:
        printf("ERROR src/tactic/tacticsunion.h>new_Tactics(int,char)\n");
        break;
    }
    this->getID = &getIDAll;
    this->getName = &getNameAll;
    this->war = &warAll;
    this->delete = &delete_tactics;

    return this;
}
// (@overriding) war function for C tactic
int warAll(const Tactics this)
{
    switch (this->ID)
    {
    case 0:
        return this->_tactic_A_->war(this->_tactic_A_);
        break;
    case 1:
        return this->_tactic_B_->war(this->_tactic_B_);
        break;
    case 2: 
        return this->_tactic_C_->war(this->_tactic_C_);
        break;
    default:
        printf("ERROR src/tactic/tacticsunion.h>warAll(const Tactics)\n");
        return 0;
        break;
    } 
}
// (@overriding) get function for ID;
int getIDAll(const Tactics this)
{
    switch (this->ID)
    {
    case 0:
        return this->_tactic_A_->getID(this->_tactic_A_);
        break;
    case 1:
        return this->_tactic_B_->getID(this->_tactic_B_);
        break;
    case 2: 
        return this->_tactic_C_->getID(this->_tactic_C_);
        break;
    default:
        printf("ERROR src/tactic/tacticsunion.h>getIDAll(const Tactics)\n");
        return 0;
        break;
    }   
}
// (@overriding) get function for name 
char* getNameAll(const Tactics this)
{
    switch (this->ID)
    {
    case 0:
        return this->_tactic_A_->getName(this->_tactic_A_);
        break;
    case 1:
        return this->_tactic_B_->getName(this->_tactic_B_);
        break;
    case 2: 
        return this->_tactic_C_->getName(this->_tactic_C_);
        break;
    default:
        printf("ERROR src/tactic/tacticsunion.h>getNameAll(const Tactics)\n");
        return "";
        break;
    }   
}
// destructor
void delete_tactics(const Tactics this)
{
    switch (this->ID)
    {
    case 0:
        this->_tactic_A_->delete(this->_tactic_A_);
        break;
    case 1:
        this->_tactic_B_->delete(this->_tactic_B_);
        break;
    case 2: 
        this->_tactic_C_->delete(this->_tactic_C_);
        break;
    default:
        printf("ERROR src/tactic/tacticsunion.h>delete_tactics(const Tactics)\n");
        break;
    }   
}