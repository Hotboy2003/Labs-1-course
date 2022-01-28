#include <iostream>
using std::cout;
using std::cin;
#define N 1000

int main()
{
    int n;
    int x;
    x = 0;
    int* mas = new int[N];
    int* first = new int[N];
    int* mini = new int[N];
    for (int i = 0; i < N; i++)
        mini[i] = INT_MAX;
    setlocale(LC_ALL, "Rus");

    cout << "Введите кол-во чисел в последовательности" << std::endl;
    cin >> n;

    cout << "Вводите числа последовательности" << std::endl;
    for (int i = 0; i < n; i++)
        cin >> mas[i];

    for (int i = 0; i < n; i++)
    {
        x = mas[i];
        while (x > 0)
        {
            mini[i] = std::min(x % 10, mini[i]);
            first[i] = x;
            x = x / 10;
        }
    }

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            if ((first[i] > first[j]) ||
                (first[i] == first[j] && mini[i] > mini[j]) ||
                (first[i] == first[j] && mini[i] == mini[j] && mas[i] > mas[j]))
            {
                std::swap(mas[i], mas[j]);
                std::swap(first[i], first[j]);
                std::swap(mini[i], mini[j]);
            }
        }

    for (int i = 0; i < n; i++)
        cout << mas[i] << " ";

    delete[] mas;
    delete[] first;
    delete[] mini;
    return 0;
}