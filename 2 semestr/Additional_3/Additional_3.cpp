#include <iostream>
#include "Header.hpp"

struct list
{
	int field; // поле данных
	struct list* next; // указатель на следующий элемент
	struct list* prev; // указатель на предыдущий элемент
};

struct list* INIT()  // а- значение первого узла
{
	struct list* list;
	// выделение памяти под корень списка
	list = (struct list*)malloc(sizeof(struct list));

	list->next = list; // указатель на следующий узел
	list->prev = list; // указатель на предыдущий узел
	return(list);
}

struct list* ADD(list* list, int number)
{
	struct list* p;
	p = (struct list*)malloc(sizeof(struct list));
	p->field = number;
	p->prev = list; 
	p->next = list->next; 
	list->next = p;
	p->next->prev = p;
	
	return(list);
}

struct list* DELETE(list* list)
{
	struct list* p = list->next;
	while (p != list)
	{
		p->prev->next = p->next;
		p->next->prev = p->prev;
		struct list* tmp = p;
		p = p->next;
		free(tmp);
	}

	return(list);
}

void PRINT(list* list)
{
	struct list* p;
	p = list->next;
	do {
		printf("%d ", p->field); // вывод значения элемента p
		p = p->next; // переход к следующему узлу
	} while (p != list); // условие окончания обхода
}

void PRINTR(list* list)
{
	struct list* p;
	p = list->prev;
	do {
		printf("%d ", p->field);
		p = p->prev;  // переход к предыдущему узлу
		 // вывод значения элемента p
	} while (p != list); // условие окончания обхода
}

int main()
{
	list* list = INIT();
	ADD(list, 15);
	ADD(list, 1);
	ADD(list, 3);
	PRINT(list);
	PRINTR(list);
	DELETE(list);

	free(list);
	return 0;
}