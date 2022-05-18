#include <iostream>
#include "bmp.hpp"

int main() {
    BMP image;
    image.readBMP("CIN.bmp");

    std::string word;
    std::cin >> word;
    image.shifr(word);
    //image.ashifr();

    image.writeBMP("COUT.bmp");

    return 0;
}