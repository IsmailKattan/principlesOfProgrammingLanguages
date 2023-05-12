#include <colony.h>

// constructor
Colony new_Colony(int population,Flag flag,Tactics tactic,Productions production)
{
    Colony this = (Colony)malloc(sizeof(struct COLONY));
    /*first value of properties*/
    this->population = population;
    this->wins = 0; 
    this->defeats = 0; 
    this->flag = flag;
    this->production = production;
    this->tactic = tactic;
    /*connect function pointers with functions*/
    this->getPopulation = &getPopulation;
    this->getWins = &getWins;
    this->getDefeats = &getDefeats;
    this->getProduction = &getProduction;
    this->getTactic = &getTactic;
    this->setPopulation = &setPopulation;
    this->setWins = &setWins;
    this->setDefeats = &setDefeats;
    this->setProduction = &setProduction;
    this->setTactic = &setTactic;
    this->delete = &delete_Colony;
    /*overriding methods */
    this->getflag = &getFlg_forColony;
    this->setflag = &setFlg_forColony;
    this->getStock = &getStock_forColony;
    this->setStock = &setStock_forColony;
    this->produce = &produce_forColony;
    this->war = &war_forColony;
    this->isViable = &isViable;
    return this;
}
/****************get functions****************/
// returns the population of colony 
int getPopulation(const Colony this)
{
    return this->population;
}
// returns the number of wins 
int getWins(const Colony this)
{
    return this->wins;
}
// returns the number of defeats
int getDefeats(const Colony this)
{
    return this->defeats;
}
// return Union of Productions
Productions getProduction(const Colony this)  // burdan hata gelebilir
{
    return this->production;
}
// return Union of Tactics
Tactics getTactic(const Colony this)  // burdan hata gelebilir
{
    return this->tactic;
}
/****************set functions****************/
// sets the population of colony 
void setPopulation(const Colony this,int population)
{
    this->population = population;
}
// sets the number of wins 
void setWins(const Colony this,int wins)
{
    this->wins = wins;
}
// sets the number of defeats
void setDefeats(const Colony this,int defeats)
{
    this->defeats = defeats;
}
// sets the Production of colony 
void setProduction(const Colony this,Productions production)
{
    this->production = production;
}
// sets the tactic of colony 
void setTactic(const Colony this,Tactics tactic)
{
    this->tactic = tactic;
}
// destructor
void delete_Colony(const Colony this)
{
    if (this != NULL)
    {
        if(this == NULL)
            return;
        if(this->flag != NULL)
            this->flag->delete(this->flag);
        if(this->tactic != NULL)
            this->tactic->delete(this->tactic);
        if(this->production != NULL)
            this->production->delete(this->production);
        free(this);
    }
    
}
// (@overriding) get function for flg value
char getFlg_forColony(const Colony this)
{
    return this->flag->getCH(this->flag);
}
// (@overriding) set function for flg value
void setFlg_forColony(const Colony this, char flg)
{
    this->flag->setCH(this->flag,flg);
}
/*Productions*/
// (@overriding) get function for stock value
int getStock_forColony(const Colony this)
{
    return this->production->getStock(this->production);
}
// (@overriding) set function for stock value
void setStock_forColony(const Colony this,int stock)
{
    this->production->setStock(this->production,stock);
}
// (@overriding) produce function
int produce_forColony(const Colony this)
{
    return this->production->produce(this->production);
}
// (@overriding) war function 
int war_forColony(const Colony this)
{
    return this->tactic->war(this->tactic);
}
/****************other functions****************/
// Returns 1 if the colony is still viable and 0 if the colony loses
int isViable(const Colony this)
{
    if(this->getPopulation(this)<=0||this->getStock(this)<=0)
        return 0;
    else 
        return 1;
}