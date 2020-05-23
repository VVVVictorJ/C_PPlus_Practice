#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void swap(int *a, int *b);
void swap(int &a, int &b);

int main()
{
    int aa = 1;
    int bb = 2;
    cout << "-----------Before swap-----------" << endl;
    cout << "aa is " << aa << endl;
    cout << "address of aa is " << &aa << endl;
    cout << "bb is " << bb << endl;
    cout << "address of bb is " << &bb << endl;
    //swap(&aa, &bb);
    swap(aa, bb);
    cout << "-----------After swap-----------" << endl;
    cout << "aa is " << aa << endl;
    cout << "address of aa is " << &aa << endl;
    cout << "bb is " << bb << endl;
    cout << "address of bb is " << &bb << endl;
    return 0;
}

#pragma region pointer
void swap(int *a, int *b)
{
    cout << "-----------jump into swap fuction-----------" << endl;
    int c = *a;
    cout << "c is " << c << endl;
    cout << "*a is " << *a << endl;
    cout << "a is " << a << endl;
    cout << "&a is " << &a << endl; //形参地址
    cout << "b is " << b << endl;
    cout << "&b is " << &b << endl; //形参地址
    cout << "-----------begin swap-----------" << endl;
    *a = *b; // *a 为aa对象地址的值， *b 为bb对象地址的值， *加其对象地址为对象值，修改其值达到互换的目的。
    cout << "*a is " << *a << endl;
    *b = c;
    cout << "*b is " << *b << endl;
    cout << "-----------turn back to main-----------" << endl;
}
#pragma endregion

#pragma region false
void swap_false(int *a, int *b)
{
    cout << "-----------jump into swap fuction-----------" << endl;
    int *c = a;
    cout << "a is " << a << endl;
    cout << "b is " << b << endl;
    cout << "&a is " << &a << endl;
    cout << "&b is " << &b << endl;
    cout << "-----------begin swap-----------" << endl;
    a = b;
    b = c;
    cout << "a is " << a << endl;
    cout << "b is " << b << endl;
    cout << "*a is " << *a << endl;
    cout << "*b is " << *b << endl;
    cout << "-----------turn back to main-----------" << endl;
}
#pragma endregion

#pragma region reference 
void swap(int &a, int &b)
{
    cout << "---------jump in----------" << endl;
    cout << "a is " << a << endl;//a 等价 aa
    cout << "b is " << b << endl;//b 等价 bb
    cout << "&a is " << &a << endl;
    cout << "&b is " << &b << endl;
    cout << "----------begin-----------" << endl;
    int c = a;
    a = b;
    b = c;
    cout << "a is " << a << endl;
    cout << "b is " << b << endl;
    cout << "----------turn back to main-----------" << endl;
}
#pragma endregion