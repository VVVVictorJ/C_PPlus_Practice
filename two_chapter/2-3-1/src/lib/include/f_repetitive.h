#ifndef F_REPETITIVE
#define F_REPETITIVE

#include<iostream>
#include<vector>

class f_repetitive
{
private:
    int *numbers;
    std::size_t cnt;//数组长度

public:
    f_repetitive(int *array, std::size_t cnt);
    ~f_repetitive();
    void find_repeated_num();
    void swap(int &a, int &b);
    bool is_element_in_vector(std::vector<int> v, int element);
    std::vector<int> unique_element_in_vector(std::vector<int> v);
};

#endif