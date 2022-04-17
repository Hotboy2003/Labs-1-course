#include <iostream>
#include <cassert>
#include "Matrix.hpp"
using my::math::Mat22d;
using my::math::Vec2d;

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

        auto B = A.determinant();
        assert(B == -2);
    }
    std::cout << "Done!" << std::endl;

    std::cout << "=== Test 6 : A^-1 ===" << std::endl;
    {
        Mat22d A({ {
                           {1,2},
                           {5,4}
                   } });

        auto B = A.inverse();
        //std::cout << std::fixed << B.get(0, 0) << std::endl;
        assert(abs(B.get(0, 0) - static_cast<double>(-2) / 3) < 1e-6);
        //assert(B.get(0, 1) == 1);
    }
    std::cout << "Done!" << std::endl;
    return 0;
}