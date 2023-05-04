#include <flag.h>

//constructor
Flag new_Flag(char chr)
{
    FLag this = malloc(sizeof(FLAG));
    this->flg = chr;
}
//get function for flg value
char getFlg(const Flag);
//disconstructor
void delete_Flag(const Flag);