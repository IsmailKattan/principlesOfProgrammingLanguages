#include <productionB.h>

// constructor
ProductionB new_ProducionB(int stock)
{
    ProductionB this = (ProductionB)malloc(sizeof(struct PRODUCTIONB));
    this->inherited = new_Producion(stock);
    this->name = "B tekniğ";
    /*oveerriding methods*/
    this->getStock = &getStockB;
    this->setStock = &setStockB;
    /*other methods*/
    this->produce = &produceB;
    this->getProduction = &getProductionB;
    this->getName = &getNamePB;
    this->delete = &delete_ProductionB;
    return this;
}
// produce function
int produceB(const ProductionB this)
{
    int num = this->getStock(this);
    srand(time(NULL) + num+1);
    return rand() % 10; // producing a number between 0 and 10
}
// get base function
Production getProductionB(const ProductionB this)
{ 
    return this->inherited;
}
// returns the name of production technic
char* getNamePB(const ProductionB this)
{
    return this->name;
}
// (@overriding) get function for stock value
int getStockB(const ProductionB this)
{
    return this->inherited->getStock(this->inherited);
}
// (@overriding) set function for stock value
void setStockB(const ProductionB this,int stock)
{
    this->inherited->setStock(this->inherited,stock);

}
// destructor
void delete_ProductionB(const ProductionB this)
{
    if(this!=NULL)
    {
        if(this->inherited != NULL)
        {
            this->inherited->delete(this->inherited);
        }
        free(this);
    }
}