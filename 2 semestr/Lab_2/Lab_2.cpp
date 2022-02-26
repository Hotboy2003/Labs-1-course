#include <iostream>
#include <chrono>
#pragma comment(linker, "/STACK:40000000")
#define N 1000000

class Timer
{
private:
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;

	std::chrono::time_point<clock_t> m_beg;

public:
	Timer() : m_beg(clock_t::now())
	{
	}

	void reset()
	{
		m_beg = clock_t::now();
	}

	double elapsed() const
	{
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};

void quicksort(int a,int b,int mas[N])
{
	if (a >= b)
		return;
	int l = a - 1;
	int r = b + 1;
	int m = (rand() * rand()) % (b - a + 1) + a;
	int k = mas[m];

	while (1)
	{
		do l = l + 1; while (mas[l] < k);
		do r = r - 1; while (mas[r] > k);
		if (l >= r)
			break;
		std::swap(mas[l], mas[r]);
	}

	r++;
	l--;
	quicksort(a, l, mas);
	quicksort(r, b, mas);
}

void bubblesort(int mas[N], int n)
{
	for (int i = 1; i < n; i++)
	{
		if (mas[i] >= mas[i - 1])
			continue;
		int j = i - 1;
		while (j >= 0 && mas[j] > mas[j + 1])
		{
			std::swap(mas[j], mas[j + 1]);
			j--;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	srand(time(0));
	int mas[N];
	for (int i = 0; i < N; i++)
		mas[i] = rand();

	int a = 0;
	int b = N-1;

	Timer t;

	quicksort(a, b, mas);

	//bubblesort(mas, N);

	std::cout << "Time elapsed: " << t.elapsed() << '\n';

	return 0;

//Быстрая сортировка
//n=10 -- 0.0011475
//n=100 -- 0.000195
//n=100000 -- 0.0329965
//n=1000000 -- 0.507899

//Сортировка пузырьком
//n=10 -- 0.0001987
//n=100 -- 0.0004001
//n=100000 -- 73.249
//n=1000000 -- 6165.9 -- 102.765 минуты

//Получается что быстрая сортировка во всех случаях работает быстрее, чем сортировка пузырьком. 
//Это происходит из за того что сложность сортировки пузырьками - O(n^2),
//а сложность быстрой сортировки - O(n*log2n) в среднем случае.
//Сортировка пузырьком много раз проходит через весь массив, а быстрая - делит массив на
//два подмассива разделяя элементы на большие рандомного числа и меньшие и так происходит до
//тех пор пока не останется один элемент. Это получается быстрее, чем по многу раз проходить через весь массив
}

