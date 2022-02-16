#include <iostream>
#define N 100

void merge(int a, int b, int mas[N]) 
{
	if (b == a)
		return;
	if (b - a == 1) {
		if (mas[b] < mas[a])
			std::swap(mas[b], mas[a]);
		return;
	}

	int m = (b + a) / 2;
	merge(a, m, mas);
	merge(m + 1, b, mas);

	int Y[N];
	int xa = a;
	int xb = m + 1;
	int cur = 0;

	while (b - a + 1 != cur) {
		if (xa > m)
			Y[cur++] = mas[xb++];
		else if (xb > b)
			Y[cur++] = mas[xa++];
		else if (mas[xa] > mas[xb])
			Y[cur++] = mas[xb++];
		else 
			Y[cur++] = mas[xa++];
	}

	for (int i = 0; i < cur; i++)
		mas[i + a] = Y[i];
}

int main()
{
	srand(0);
	int mas[N];
	for (int i = 0; i < N; i++)
		mas[i] = rand();

	merge(0, N-1, mas);

	for (int i = 0; i < N; i++)
		std::cout << mas[i] << " ";

	return 0;
}