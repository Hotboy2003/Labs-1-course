#include <iostream>


int main()
{
    int Q1, P1, Q2, P2, A, Amin;
    std::cin >> Q1 >> P1 >> Q2 >> P2 >> A;
    Amin = INT_MAX;
    if (Q1 < Q2)
    {
        std::swap(Q1, Q2);
        std::swap(P1, P2);
    }

    int k = 0, A1 = A;
    while (A1 > 0)
    {
        k++;
        A1 -= Q1;
    }

    int C = k, D = 0;
    int S = 0;
    while (C != 0)
    {
        S = C * P1 + D * P2;
        Amin = std::min(S, Amin);
        C--;
        while (C * Q1 + D * Q2 < A)
            D++;
    }
    int x = 0;
    while (x * Q2 < A)
        x++;
    Amin = std::min(Amin, x * Q2);
    std::cout << Amin;
}