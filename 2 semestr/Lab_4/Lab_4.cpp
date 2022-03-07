#include <iostream>
#include <chrono>
#define N 10
#define M 5

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

struct T_List
{
	T_List* next;
	int x;
};

void PRINT(T_List* head)
{
	T_List* p = head->next;
	while (p != nullptr)
	{
		std::cout << p->x << std::endl;
		p = p->next;
	}
}

void ADD(T_List* head, int x)
{
	T_List* p = new T_List;
	p->x = x;

	p->next = head->next;
	head->next = p;
}

void CLEAR(T_List* head)
{
	T_List* tmp;
	T_List* p = head->next;
	while (p != nullptr)
	{
		tmp = p;
		p = p->next;
		delete tmp;
	}
}

void ADD_END(T_List* head, int x)
{
	T_List* p = head->next;
	while (p->next != nullptr)
	{
		p = p->next;
	}
	T_List* q = new T_List;
	q->x = x;
	p->next = q;
	p->next->next = nullptr;

}

int main()
{
	srand(time(0));
	Timer t;
	int mas[N + M];
	for (int i = 0; i < N; i++)
		mas[i] = rand();

	for (int i = N; i < N + M; i++)
		mas[i] = rand();

	T_List* head = new T_List;
	head->next = nullptr;

	for (int i = 0; i < N; i++)
		ADD(head, 1);

	for (int i = 0; i < M; i++)
		ADD_END(head, 3);

	PRINT(head);

	CLEAR(head);

	delete head;

	std::cout << "Time elapsed: " << t.elapsed() << '\n';
	return 0;
}

//List - 0.107027
//Massive - 0.0017147