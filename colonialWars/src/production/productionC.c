#include <productionC.h>

// constructor
ProductionC new_ProducionC(int stock)
{
    ProductionC this = (ProductionC)malloc(sizeof(struct PRODUCTIONC));
    this->inherited = new_Producion(stock);
    this->name = "C tekniği";
    /*overriding methods*/
    this->getStock = &getStockC;
    this->setStock = &setStockC;
    /*other methods*/
    this->produce = &produceC;
    this->getProduction = &getProductionC;
    this->getName = &getNamePC;
    this->delete = &delete_ProductionC;

    return this;
}
// produce function
int produceC(const ProductionC this)
{
    int num = this->getStock(this);
    srand(time(NULL) + 17*num);

    return rand() % 10; // producing a number between 0 and 10
}
// get base function
Production getProductionC(const ProductionC this)
{ 
    return this->inherited;
}
// returns the name of production technic
char* getNamePC(const ProductionC this)
{
    return this->name;
}
// (@overriding) get function for stock value
int getStockC(const ProductionC this)
{
    return this->inherited->getStock(this->inherited);
}
// (@overriding) set function for stock value
void setStockC(const ProductionC this,int stock)
{
    this->inherited->setStock(this->inherited,stock);

}
// destructor
void delete_ProductionC(const ProductionC this)
{
    if(this!=NULL)
    {
        this->inherited->delete(this->inherited);
        free(this);
    }
}