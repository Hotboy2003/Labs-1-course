#include <iostream>

struct T_List
{
	T_List* next;
	int age;
};

void ADD(T_List* head, int age)
{
	T_List* p = new T_List;
	p->age = age;

	p->next = head->next;
	head->next = p;
}

void PRINT(T_List* head)
{
	T_List* p = head->next;
	while (p != nullptr)
	{
		std::cout << p->age << std::endl;
		p = p->next;
	}
}

void DELETE(T_List* head)
{
	T_List* tmp;
	T_List* p = head;
	while (p->next != nullptr)
	{
		if (p->next->age % 2 == 0)
		{
			tmp = p->next;
			p->next = p->next->next;
			delete tmp;
		}
		else
			p = p->next;
	}
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

void DUPLICATE(T_List* head)
{
	T_List* p = head->next;
	while (p != nullptr)
	{
		if (p->age % 2 == 1)
		{
			T_List* q = new T_List;
			q->next = p->next;
			p->next = q;
			q->age = p->age;
			p = p->next;
		}
		p = p->next;
	}
}

void SWAPSORT(T_List* head)
{
	T_List* p = head->next;
	while (p->next->next != nullptr)
	{
		T_List* q = p->next;
		while (q->next != nullptr)
		{
			if (p->age > q->age)
				std::swap(p->age, q->age);
			q = q->next;
		}
		p = p->next;
	}
}

void SEARCH(T_List* head, int p)
{
	T_List* tmp = head;

	while (tmp != nullptr)
	{
		if (tmp->age == p)
		{
			std::cout << "Искомый элемент есть в списке " << "\n";
			break;
		}
		else
			tmp = tmp->next;
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	T_List* head = new T_List;
	head->next = nullptr;

	ADD(head, 10);
	ADD(head, 2);
	ADD(head, 3);
	ADD(head, 5);
	ADD(head, 6);

	SEARCH(head,2);

	PRINT(head);

	std::cout << "====" << std::endl;

	SWAPSORT(head);
	PRINT(head);

	std::cout << "====" << std::endl;

	DELETE(head);
	PRINT(head);

	std::cout << "====" << std::endl;

	DUPLICATE(head);
	PRINT(head);

	CLEAR(head);

	delete head;
	return 0;
}
