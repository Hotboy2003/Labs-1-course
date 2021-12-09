#include <iostream>
#include <fstream>

int main()
{
    int** matrix = new int*[100];
    for (int i = 0; i < 100; i++)
        matrix[i] = new int[100];
    int n, m, summa;
    int mini_summa = INT_MAX;
    int number_str = 0;
    std::fstream in("numbers_in3.txt");
    std::ofstream out("numbers_out3.txt");

    in >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            in >> matrix[i][j];

    for (int i = 0; i < n; i++)
    {
        summa = 0;
        for (int j = 0; j < m; j++)
            summa = summa + matrix[i][j];

        if (summa < mini_summa)
        {
            number_str = i;
            mini_summa = summa;
        }
    }

    for (int i = 0; i < m; i++)
        matrix[number_str][i] = mini_summa;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            out << matrix[i][j] << " ";
        out << std::endl;
    }

    for (int i = 0; i < n; i++)
        delete[] matrix[i];
    delete matrix;

    return 0;
}