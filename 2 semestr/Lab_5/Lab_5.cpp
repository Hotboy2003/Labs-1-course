#include <iostream>

struct Elem
{
    int data;   //Данные 
    //Указатели на соседние вершины
    Elem* left;
    Elem* right;
    Elem* parent;
};

//Инициализация вершины
Elem* MAKE(int data, Elem* p)
{
    Elem* q = new Elem;       //Выделяем память под вершину
    q->data = data;
    q->left = nullptr;
    q->right = nullptr;
    q->parent = p;
    return q;
}

//Добавление элемента
void ADD(int data, Elem*& root)
{
    //Если корневого элемента нет, то вызываем функцию MAKE и делаем его nullptr
    if (root == nullptr) {
        root = MAKE(data, nullptr);
        return;
    }
    Elem* v = root;
    //Проверяем есть ли правый или левый потомок у корня (если да, то проходим дальше по дереву)
    while ((data < v->data && v->left != nullptr) || (data > v->data && v->right != nullptr))
        if (data < v->data)
            v = v->left;
        else
            v = v->right;
    //Игнорирование одинаковых элементов
    if (data == v->data)
        return;
    //Создаем вершину
    Elem* u = MAKE(data, v);
    //Определяем является она левым или правым потомком (больше или меньше корневого элемента)
    if (data < v->data)
        v->left = u;
    else
        v->right = u;
}

//Обход дерева
void PASS(Elem* v)
{
    if (v == nullptr)
        return;
 
    //Проходим по левым элементам до последнего
    PASS(v->left);
    // Выводятся все левые элементы
    std::cout << v->data << std::endl;

    //Проходим по правым элементам до последнего и также выводим все
    PASS(v->right);
}





int main()
{
    Elem* root = nullptr; //Создание корня
    
    return 0;
}
