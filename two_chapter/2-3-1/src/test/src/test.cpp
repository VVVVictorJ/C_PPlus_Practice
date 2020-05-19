#include<f_repetitive.h>
#include<iostream>

void show(int a[], std::size_t cnt){

    std::cout << "Initial serial of numbers is : ";
    for (size_t i = 0; i < cnt; i++)
    {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;
}

int main(){
    int a[9] = {0, 2, 3, 5, 1, 7, 4, 2, 8};
    std::size_t cnt = sizeof(a) / sizeof(a[0]);
    show(a, cnt);
    f_repetitive f(a, cnt);
    f.find_repeated_num();
    return 0;
}