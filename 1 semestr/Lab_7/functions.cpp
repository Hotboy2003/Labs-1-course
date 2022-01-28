#include <iostream>
#include <string>
#include <SomeFunctions.hpp>

void Read(int& n, int mas[1000])
{
    std::cin >> n;
    for (int i = 0; i < n; i++)
        std::cin >> mas[i];
}

bool ConsistsPrime(int n, int mas[1000])
{
    for (int i = 0; i < n; i++)
        if (mt::isPrime(mas[i]))
            return true;
    return false;
}

void Write(int n, int mas[1000])
{
    std::cout << n << std::endl;
    for (int i = 0; i < n; i++)
        std::cout << mas[i] << " ";
}

int main(/*int argc, char** argv*/)
{
    // Дана последовательность, если есть простое число, то упорядочить по возр
    int n;
    int mas[1000];
    Read(n, mas);
    if (ConsistsPrime(n, mas))
        mt::sort(n, mas);
    Write(n, mas);

    return 0;


    /*std::cout << "argc " << argc << std::endl;

    for (int i = 0; i < argc; i++)
        std::cout << argv[i] << std::endl;
        std::stoi(argv[1])*/

    /*int n = 37;
    std::cout << mt::sumOfDigits(n) << " " << n << std::endl;*/

    /*int n = 5;
    int arr[N_Max] = { 5, 3, 1, -20, 0 };
    sort(n, arr);
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << " " << std::endl;*/

    /*int a, b;
    std::cin >> a >> b;

    swap(a, b);

    std::cout << a << " " << b << std::endl;*/

    /*int x;
    std::cin >> x;

    // Определение простоты числа
    std::cout << isPrime(x) << std::endl;*/

    return 0;
}
