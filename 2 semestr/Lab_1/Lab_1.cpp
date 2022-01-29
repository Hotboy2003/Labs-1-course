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
		if (mas[i] % 2 != 0) // n
		{
			std::cout << i+1 << std::endl;
			break;
		}
	}
	
	std::cout << "Time elapsed: " << t.elapsed() << '\n';

	return 0;
}

// Лучший случай - 3 операции
// Средний случай - n^2 снизу
// Худший случай - n^2 сверху

// Примерное время работы в лучшем случае - мгновенно
// Примерное время работы в худшем случае (примем скорость работы процессора - 100 млн операций в секунду
//	n^2/10^8 = 10^8/10^8 = 1 секунда

// Реальное время работы в лучшем случае - мгновенно (сошлось)
// Реальное время работы в худшем случае - 0.002 секунды
// Видимо мой компьютер мощнее чем я думал
// Если посчитать, то он делает примерно 5*10^10 степени операций в секунду (возможно, я не разбираюсь)