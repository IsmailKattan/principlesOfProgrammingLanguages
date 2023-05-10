#include "flag.h"

//constructor
Flag new_Flag(char chr)
{
    Flag this = (Flag) malloc(sizeof(struct FLAG));
    this->flg = chr;
    this->getCH = &getFlg;
    this->setCH = &setFlg;
    this->delete = &delete_Flag;
    return this;
}
//get function for flg value
char getFlg(const Flag this) // this is a pointer 
{
    return this->flg;
}
//set function for flg value
void setFlg(const Flag this, char flg)
{
    this->flg = flg;
}
//disconstructor
void delete_Flag(const Flag this) // this is a pointer
{
    if(this == NULL)
        return;
    free(this);
}