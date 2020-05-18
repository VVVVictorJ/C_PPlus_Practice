#include<foo.h>
#include<iostream>

int main(){

    Foo foo(1);
    int before = foo.getHP();
    std::cout << "Before change the HP is "+std::to_string(before) << std::endl;
    foo.setHP(100);
    int after = foo.getHP();
    std::cout << "After change the HP is " + std::to_string(after) << std::endl;
    return 0;

}