#include <SomeFunctions.hpp>

namespace mt
{
    // заголовок, сигнатура
    // тип данных, название, аргументы (может не быть)
    // передача по значению
    bool isPrime(int x)
    {
        // тело
        if (x < 2)
            // возврат результата
            return false;
        for (int d = 2; d <= sqrt(x); d++)
            if (x % d == 0)
                return false;
        return true;
    }

    // Обмен двух переменных
    // & - передача по ссылке
    // void - функция ничего не возвращает (процедура)
    void swap(int& a, int& b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }

    // Поиск суммы цифр числа
    int sumOfDigits(int x)
    {
        int sum = 0;
        while (x > 0)
        {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }

    // Сортировка
    // массив передан по ссылке
    void sort(int n, int mas[N_Max])
    {
        for (int i = 0; i < n - 1; i++)
            for (int j = i + 1; j < n; j++)
                if (mas[i] < mas[j])
                    swap(mas[i], mas[j]);
    }

}
