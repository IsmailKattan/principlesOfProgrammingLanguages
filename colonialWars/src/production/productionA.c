#include <productionA.h>

// constructor
ProductionA new_ProducionA(int stock)
{
    ProductionA this = (ProductionA)malloc(sizeof(struct PRODUCTIONA));
    this->inherited = new_Producion(stock);
    this->name = "A tekniği";
    /*overriding methods*/
    this->getStock = &getStockA;
    this->setStock = &setStockA;
    /*other methods*/
    this->produce = &produceA;
    this->getProduction = &getProductionA;
    this->getName = &getNamePA;
    this->delete = &delete_ProductionA;

    return this;
}
// produce function
int produceA(const ProductionA this)
{
    int num = this->getStock(this);
    srand(time(NULL) + num);
    return rand() % 10; // producing a number between 0 and 10
}
// get base function
Production getProductionA(const ProductionA this)
{ 
    return this->inherited;
}
// returns the name of production technic
char* getNamePA(const ProductionA this)
{
    return this->name;
}
// (@overriding) get function for stock value
int getStockA(const ProductionA this)
{
    return this->getProduction(this)->getStock(this->getProduction(this));
}
// (@overriding) set function for stock value
void setStockA(const ProductionA this,int stock)
{
    this->getProduction(this)->setStock(this->getProduction(this),stock);
}
// destructor
void delete_ProductionA(const ProductionA this)
{
    if(this!=NULL)
    {
        this->inherited->delete(this->inherited);
        free(this);
    }
}