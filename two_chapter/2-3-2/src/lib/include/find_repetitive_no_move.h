#ifndef FIND_NO_MOVE
#define FIND_NO_MOVE

#include<iostream>

class find_repetitive_no_move
{
private:
    int *numbers;
    std::size_t length;//length of numbers

public:
    find_repetitive_no_move(int a[], std::size_t length);
    ~find_repetitive_no_move();
    void find_no_move();
    std::size_t range_find(int *a, int start, int end, std::size_t length);
};

#endif