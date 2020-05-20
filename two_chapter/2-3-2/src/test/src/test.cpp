#include<find_repetitive_no_move.h>
#include<iostream>

void show(int a[], std::size_t cnt);

int main()
{
    int a[8] = {2, 3, 5, 4, 3, 2, 6, 7};
    std::size_t len = sizeof(a) / sizeof(a[0]);
    show(a, len);
    find_repetitive_no_move f(a, len);
    f.find_no_move();
    return 0;
}

void show(int a[], std::size_t cnt)
{

    std::cout << "Initial serial of numbers is : ";
    for (size_t i = 0; i < cnt; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}