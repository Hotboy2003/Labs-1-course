#include <iostream>
#include <chrono> // для функций из std::chrono
#define N_max 10000

class Timer
{
private:
	// Псевдонимы типов используются для удобного доступа к вложенным типам
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

int main()
{
	srand(time(0));
	int mas[N_max];
	for (int i = 0; i < N_max; i++)
		//mas[i] = rand();
		mas[i] = 2;
	mas[N_max-1] = 3;

	Timer t;

	for (int i = 0; i < N_max; i++) // n
	{
		if (mas[i] % 2 != 0) // 1
		{
			std::cout << i+1 << std::endl;
			break;
		}
	}
	
	std::cout << "Time elapsed: " << t.elapsed() << '\n';

	return 0;
}

// Лучший случай - 0 операций
// Средний случай - n снизу
// Худший случай - n сверху

// Примерное время работы в лучшем случае - мгновенно
// Примерное время работы в худшем случае (примерная скорость работы процессора - 100 млн операций в секунду)
//	2n/10^8 = 2*10^4/10^8 = 0.0002 секунды

// Реальное время работы в лучшем случае - мгновенно (сошлось)
// Реальное время работы в худшем случае - 0.002 секунды (не сошлось)
// Видимо мой компьютер слабее чем я думал