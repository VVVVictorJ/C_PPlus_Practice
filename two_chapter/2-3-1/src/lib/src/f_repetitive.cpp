#include "f_repetitive.h"
#include <algorithm>

f_repetitive::f_repetitive(int *array, std::size_t cnt)
{
    this->numbers = array;
    this->cnt = cnt;
}

f_repetitive::~f_repetitive()
{
}

void f_repetitive::find_repeated_num()
{
    std::vector<int> duplication(cnt, -1);

    if (numbers == nullptr || cnt <= 0)
    {
        std::cout << "out of index" << std::endl;
        return;
    }

    for (size_t i = 0; i < cnt; i++)
    {
        if (numbers[i] < 0)
        {
            std::cout << "wrong value. Value of number should be positive."
                      << std::endl;
            return;
        }
        if (numbers[i] > cnt - 1)
        {
            std::cout << "wrong value. Value of number should be lower than length of array."
                      << std::endl;
            return;
        }
    }

    for (size_t i = 0; i < cnt; i++)
    {
        while (numbers[i] != i)
        {
            if (numbers[i] == numbers[numbers[i]])
            {
                if (!is_element_in_vector(duplication, numbers[i]))
                {
                    duplication.push_back(numbers[i]);
                }
                break;
            }
            else
            {
                swap(numbers[i], numbers[numbers[i]]);
            }
        }
    }
    duplication = unique_element_in_vector(duplication);
    for (auto &r : duplication)
    {
        if (r!=-1)
        {
            std::cout << "Duplicated number is " + std::to_string(r) << std::endl;
        }
        
    }
    std::cout << "Search completed." << std::endl;
    std::cout << "After change : ";
    for (size_t i = 0; i < cnt; i++)
    {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
}

void f_repetitive::swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

bool f_repetitive::is_element_in_vector(std::vector<int> v, int element)
{

    std::vector<int>::iterator it;
    it = find(v.begin(), v.end(), element);
    if (it != v.end())
    {
        //存在重复，返回第一个重复值的迭代器
        return true;
    }
    else
    {
        //不存在重复，返回尾迭代器
        return false;
    }
}

std::vector<int> f_repetitive::unique_element_in_vector(std::vector<int> v)
{
    std::vector<int>::iterator it;
    sort(v.begin(), v.end());//首先重新排序
    it = unique(v.begin(), v.end());//unique 将重复元素排至队尾，返回第一个重复值的迭代器。
    if (it != v.end())
    {
        v.erase(it, v.end());
    }
    return v;
}