#include <iostream>
#include <fstream>
#include "BMP.hpp"

int main()
{
    BMP IMAGE;
    IMAGE.READ();
    IMAGE.FILTER();
    IMAGE.WRITE();
}