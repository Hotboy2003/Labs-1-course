#include <iostream>
#include <chrono>
#define N 1000

int max_number(int *mas, int i, int k)
{
	if (mas[i] > k)
	{
		k = mas[i];
		i++;
	}
	if (i > N)
		return k;
	else
		max_number(mas, i, k);
}

int main()
{
	srand(time(0));
	int mas[N];
	for (int i = 0; i < N; i++)
		mas[i] = rand();
	int i = 0;
	int k = 0;

	int maxi = max_number(mas, i, k);

	std::cout << maxi;
	return 0;
}