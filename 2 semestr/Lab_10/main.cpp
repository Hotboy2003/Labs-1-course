#include <iostream>
#include "lib/BMP.hpp"


int main()
{
    try
    {
        images::BMP test_bmp(1166, 592);

        test_bmp.OPEN("IMAGE.bmp");
        test_bmp.ROTATE(acos(-1) / 2);
        test_bmp.ERRORDELETE();
        test_bmp.SAVE("IMAGE_out.bmp");
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}