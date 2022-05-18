#include <iostream>
#include "bmp.hpp"

int main() 
{
    BMP image;
    image.READBMP("CIN.bmp");

    std::string word;
    std::cin >> word;
    image.SHIFR(word);

    image.WRITEBMP("COUT.bmp");

    return 0;
}