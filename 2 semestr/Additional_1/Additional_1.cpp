#include <iostream>
#include <chrono>
#define N_max 1000

int max_number(int* mas, int n) 
{
    static int max{};
    if (n == 1)
        max = mas[0];
    else
    {
        if (max_number(mas, n - 1) <= mas[n - 1])
            max = mas[n - 1];
    }
    return max;
}



int main() 
{
    srand(time(0));
    int mas[N_max];
    for (int i = 0; i < N_max; i++)
        mas[i] = rand();


    std::cout << max_number(mas, N_max) << std::endl;

    return 0;
}