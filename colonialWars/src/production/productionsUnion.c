#include <productionsUnion.h>

//constructor 
Productions new_productions(int stock)
{
    Productions this = (Productions)malloc(sizeof(struct PRODUCTIONS));
    this->ID = stock % 3;
    switch (this->ID)
    {
    case 0:
        this->_production_A_ = new_ProducionA(stock);
        break;
    case 1:
        this->_production_B_ = new_ProducionB(stock);
        break;
    case 2: 
        this->_production_C_ = new_ProducionC(stock);
        break;
    default:
        printf("ERROR src/production/productionsunion.h>new_Productions(int)\n");
        break;
    }
    this->getID = &getIDP;
    this->produce = &produceAll;
    this->getStock = &getStockAll;
    this->setStock = &setStockAll;
    this->getName = &getNameAllP;
    this->delete = &delete_Producctions; 
    return this;
}
// getID
int getIDP(const Productions this)
{
    return this->ID;
}
// (@overriding) produce function
int produceAll(const Productions this)
{
    switch (this->ID)
    {
    case 0:
        return this->_production_A_->produce(this->_production_A_);
        break;
    case 1:
        return this->_production_B_->produce(this->_production_B_);
        break;
    case 2: 
        return this->_production_C_->produce(this->_production_C_);
        break;
    default:
        printf("ERROR src/production/productionsunion.h>produceAll(const Productions)\n");
        return 0;
        break;
    }
}
// (@overriding) get function for stock value
int getStockAll(const Productions this)
{
    switch (this->ID)
    {
    case 0:
        return this->_production_A_->getStock(this->_production_A_);
        break;
    case 1:
        return this->_production_B_->getStock(this->_production_B_);
        break;
    case 2: 
        return this->_production_C_->getStock(this->_production_C_);
        break;
    default:
        printf("ERROR src/production/productionsunion.h>produceAll(const Productions)\n");
        return 0;
        break;
    }
}
// (@overriding) set function for stock value
void setStockAll(const Productions this,int stock)
{
    switch (this->ID)
    {
    case 0:
        this->_production_A_->setStock(this->_production_A_,stock);
        break;
    case 1:
        this->_production_B_->setStock(this->_production_B_,stock);
        break;
    case 2: 
        this->_production_C_->setStock(this->_production_C_,stock);
        break;
    default:
        printf("ERROR src/production/productionsunion.h>produceAll(const Productions)\n");
        break;
    }
}
// (@overriding) returns the name of production technic
char* getNameAllP(const Productions this)
{
        switch (this->ID)
    {
    case 0:
        return this->_production_A_->getName(this->_production_A_);
        break;
    case 1:
        return this->_production_B_->getName(this->_production_B_);
        break;
    case 2: 
        return this->_production_C_->getName(this->_production_C_);
        break;
    default:
        printf("ERROR src/production/productionsunion.h>produceAll(const Productions)\n");
        return "";
        break;
    }
}
// destructor 
void delete_Producctions(const Productions this)
{
    switch (this->ID)
    {
    case 0:
        if (this->_production_A_!= NULL)
        {
            this->_production_A_->delete(this->_production_A_);
        }
        break;
    case 1:
        if (this->_production_B_!= NULL)
        {
            this->_production_B_->delete(this->_production_B_);
        }
        break;
    case 2: 
        if (this->_production_C_!= NULL)
        {
            this->_production_C_->delete(this->_production_C_);
        }
        break;
    default:
        printf("ERROR src/production/productionsunion.h>produceAll(const Productions)\n");
        break;
    }
    free(this);
}
