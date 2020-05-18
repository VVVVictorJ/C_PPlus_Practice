#include "foo.h"

Foo::Foo(int para)
{
    this->HP = para;
    std::cout << "HP initilized is " + std::to_string(para) << std::endl;
}

int Foo::getHP()
{
    return HP;
}

void Foo::setHP(int para){
    this->HP = para;
}