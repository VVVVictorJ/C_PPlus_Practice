#include "find_repetitive_no_move.h"

find_repetitive_no_move::find_repetitive_no_move(int *a, std::size_t length)
{
    numbers = a;
    this->length = length;
}

find_repetitive_no_move::~find_repetitive_no_move()
{
}

void find_repetitive_no_move::find_no_move()
{
    if (numbers == nullptr || length <= 0)
    {
        std::cout << "null pointer." << std::endl;
    }
    int start = 1;
    int end = length - 1;
    while (end >= start)
    {
        int mid = ((end - start) >> 1) + start; //右移n位相当于除以2^n
        std::size_t count = range_find(numbers, start, mid, length);
        if (end == start)
        {
            if (count > 1)
            {
                std::cout << "duplicate number is " + std::to_string(count) << std::endl;
                break;
            }
            else
            {
                break;
            }
        }
        if (count > (mid - start + 1))
        {
            end = mid;
        }
        else
        {
            start = mid + 1;
        }
    }
    std::cout << "search done" << std ::endl;
}

std::size_t find_repetitive_no_move::range_find(int *a, int start, int end, std::size_t length)
{
    if (a == nullptr)
    {
        return 0;
    }

    std::size_t cnt = 0;

    for (size_t i = 0; i < length; i++)
    {
        if (numbers[i] >= start && numbers[i] <= end)
        {
            ++cnt;
        }
    }
    return cnt;
}
