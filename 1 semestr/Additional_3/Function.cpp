#include "Function.hpp"
#include <iostream>
#include <Math.h>

namespace ao
{
    void Read(int &n) {
        std::cin >> n;
    }

    int MaxCifr(int &n) {
        int ans = 0, a = n;
        while (a > 0) {
            ans = std::max(ans, a % 10);
            a = a / 10;
        }
        return ans;
    }

    int ChastCifr(int &n) {
        int mas[10];
        int a = n;
        for (int i = 0; i < 10; ++i) {
            mas[i] = 0;
        }
        for (int i = 0; i < 10; ++i) {
            mas[a % 10]++;
            a = a / 10;
        }
        int ind = 0, kol = mas[0];
        for (int i = 0; i < 10; ++i) {
            if (mas[i] >= kol) {
                ind = i;
                kol = mas[i];
            }
        }
        return ind;
    }

    int Sum(int &n) {
        int ans = 0, a = n;
        while (a > 0) {
            ans += a % 10;
            a = a / 10;
        }
        return ans;
    }
}
