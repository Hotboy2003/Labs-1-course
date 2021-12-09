#include <iostream>
#include "Functions.hpp"


int main()
{
    int x1 = INT_MIN;
    int number;

    ao::Read(number);
    x1 = ao::Max_number(number,x1);
    ao::Write(x1);
    return 0;
}