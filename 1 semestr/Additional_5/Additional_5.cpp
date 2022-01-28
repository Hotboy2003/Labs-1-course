#include <iostream>
#include <algorithm>

#define N 20000
int mas[N];

bool Cifra8(int n)
{
    while (n != 0)
    {
        if (n % 10 == 8)
        {
            return true;
        }
        n = n / 10;
    }
    return false;
}

long int ProizCifr(int n) {
    long int ans = 1;
    while (n != 0) {
        ans *= n % 10;
        n /= 10;
    }
    return ans;
}

int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n * 2; i += 2) {
        std::cin >> mas[i];
    }
    for (int i = 0; i < n * 2; i += 2) {
        if (ProizCifr(mas[i]) == 144) {
            mas[i] = -1;
            mas[i + 1] = mas[i];
        }
        else {
            if (Cifra8(mas[i]) == true) {
                mas[i + 1] = mas[i];
            }
        }
    }
    for (int i = 0; i < n * 2; i += 2) {
        if (mas[i] != -1) {
            std::cout << mas[i] << " ";
            if (mas[i + 1] != 0)
                std::cout << mas[i + 1] << " ";
        }
    }
}
