#include <iostream>
#include <cassert>
#include "Matrix.hpp"
using AO::Mat22d;
using AO::Vec2d;

int main()
{
    std::cout << "=== Test 1 : * ===" << std::endl;
    {
        Mat22d A({ {
                           {1,2},
                           {3,4}
                   } });

        Vec2d X({ {
                          {1},
                          {1}
                  } });

        auto B = A * X;

        assert(B.get(0, 0) == 3);
        assert(B.get(1, 0) == 7);
    }
    std::cout << "Done!" << std::endl;

    std::cout << "=== Test 2 : + ===" << std::endl;
    {
        Mat22d A({ {
                           {1,1},
                           {1,1}
                   } });

        Mat22d X({ {
                          {1, 1},
                          {1, 1}
                  } });

        auto B = A + X;
        assert(B.get(0, 0) == 2);
        assert(B.get(1, 0) == 2);
        assert(B.get(1, 1) == 2);
        assert(B.get(0, 1) == 2);
    }
    std::cout << "Done!" << std::endl;

    std::cout << "=== Test 3 : - ===" << std::endl;
    {
        Mat22d A({ {
                           {1,1},
                           {1,1}
                   } });

        Mat22d X({ {
                           {1},
                           {1}
            } });
        auto B = A - X;
        assert(B.get(0, 0) == 0);
        assert(B.get(1, 0) == 0);
    }
    std::cout << "Done!" << std::endl;

    std::cout << "=== Test 4 : T ===" << std::endl;
    {
        Mat22d A({ {
                           {1,2},
                           {3,4}
                   } });

        auto B = A.transposition();
        assert(B.get(0, 1) == 3);
        assert(B.get(1, 0) == 2);
    }
    std::cout << "Done!" << std::endl;

    std::cout << "=== Test 5 : Det ===" << std::endl;
    {
        Mat22d A({ {
                           {1,2},
                           {3,4}
                   } });

        auto B = A.det();
        assert(B == -2);
    }
    std::cout << "Done!" << std::endl;

    std::cout << "=== Test 6 : A^-1 ===" << std::endl;
    {
        try
        {
            Mat22d A({ {
                               {1,2},
                               {5,4}
                       } });

            auto B = A.inverse();
            assert(abs(B.get(0, 0) - static_cast<double>(-2) / 3) < 1e-6);
        }
        catch (const std::exception& e)
        {
            std::cerr << e.what() << std::endl;
        }
    }
    std::cout << "Done!" << std::endl;
    return 0;
}