#ifndef FOO_H
#define FOO_H

#include<iostream>

class Foo{
    private:
        int HP;
    public:
        int getHP();
        void setHP(int para);
        Foo(int para);
};

#endif