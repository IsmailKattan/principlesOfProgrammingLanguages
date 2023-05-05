#include <tactic.h>
#include <time.h>

// constructor
Tactic new_Tactic(int ID, char* name)
{
    Tactic this = (Tactic)malloc(sizeof(struct TACTIC)); // allocate memory for new object (TACTIC)
    this->ID = ID;
    this->name = name;
    this->getID = &getID;
    this->getName = &getName;
    this->delete = &delete_Tactic;

    return this;
} 
// get function for ID;
int getID(const Tactic this)
{
    return this->ID;
}
// get function for name 
char* getName(const Tactic this)
{
    return this->name;
}
// destructor 
void delete_Tactic(const Tactic this)
{
    if(this!=NULL)
        free(this);
}