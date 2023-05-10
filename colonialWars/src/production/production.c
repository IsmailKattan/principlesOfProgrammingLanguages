#include <production.h>

// constructor
Production new_Producion(int stock) 
{
    Production this = (Production)malloc(sizeof(struct PRODUCTION)); // mallocate memory for Production 
    this->stock = stock; // set first value for stock 
    /*set method for method pointers*/
    this->getStock = &getStock;
    this->setStock = &setStock;
    this->delete = &delete_Production; 
    this->produce = &produce;
    return this;
}
// get function for stock value
int getStock(const Production this)
{
    return this->stock;
}
// set function for stock value
void setStock(const Production this, int value)
{
    this->stock = value;
}
// produce function
int produce(const Production this)
{
    srand(time(NULL));
    return rand()%10;
}
// destructor 
void delete_Production(const Production this)
{
    if(this == NULL)
    {
        return;
    }
    free(this);
}