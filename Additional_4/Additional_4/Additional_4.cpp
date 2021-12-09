#include <iostream>

int main()
{
    int s = 0;
    for (int i = 0; i <= 999; i++)
        for (int j = 0; j <= 999; j++)
            if (i / 100 + i / 10 % 10 + i % 10 ==
                j / 100 + j / 10 % 10 + j % 10) {
                s++;
                //std::cout << i << " " << j << std::endl;
            }
    std::cout << s;
    return 0;
}