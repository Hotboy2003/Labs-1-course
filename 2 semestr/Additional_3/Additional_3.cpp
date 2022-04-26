#include <iostream>
#include "Header.hpp"

struct list
{
	int field; // поле данных
	struct list* next; // указатель на следующий элемент
	struct list* prev; // указатель на предыдущий элемент
};

struct list* INIT(int a)  // а- значение первого узла
{
	struct list* list;
	// выделение памяти под корень списка
	list = (struct list*)malloc(sizeof(struct list));
	list->field = a;
	list->next = list; // указатель на следующий узел
	list->prev = list; // указатель на предыдущий узел
	return(list);
}

struct list* ADD(list* list, int number)
{
	struct list* temp, * p;
	temp = (struct list*)malloc(sizeof(list));

	p = list->next; // сохранение указателя на следующий узел
	list->next = temp; // предыдущий узел указывает на создаваемый

	temp->field = number; // сохранение поля данных добавляемого узла

	temp->next = p; // созданный узел указывает на следующий узел
	temp->prev = list; // созданный узел указывает на предыдущий узел
	p->prev = temp;
	return(temp);
}

struct list* DELETE(list* list)
{
	struct list* prev, * next;
	prev = list->prev; // узел, предшествующий lst
	next = list->next; // узел, следующий за lst
	prev->next = list->next; // переставляем указатель
	next->prev = list->prev; // переставляем указатель
	free(list); // освобождаем память удаляемого элемента
	return(prev);
}

void PRINT(list* list)
{
	struct list* p;
	p = list;
	do {
		printf("%d ", p->field); // вывод значения элемента p
		p = p->next; // переход к следующему узлу
	} while (p != list); // условие окончания обхода
}

void PRINTR(list* list)
{
	struct list* p;
	p = list;
	do {
		p = p->prev;  // переход к предыдущему узлу
		printf("%d ", p->field); // вывод значения элемента p
	} while (p != list); // условие окончания обхода
}

int main()
{
	list* list = INIT(10);
	ADD(list, 15);
	ADD(list, 1);
	ADD(list, 3);
	PRINT(list);
	DELETE(list);
	return 0;
}