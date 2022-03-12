#include <iostream>
#include <fstream>
#include <cstring> 
#include <string> // подключаем строки

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

Elem* DEEP(int data, Elem* v, int& k) // v - ,    
{
    k += 1;
    if (v == nullptr)
        return v;
    if (v->data == data)
        return v;
    if (data < v->data)
    {
        return DEEP(data, v->left, k);
    }
    else
    {
        return DEEP(data, v->right, k);
    }
}

//Поиск элемента
Elem* SEARCH(int data, Elem* v) // v - ,    
{
    if (v == nullptr)
        return v;
    if (v->data == data)
        return v;
    if (data < v->data)
        return SEARCH(data, v->left);
    else
        return SEARCH(data, v->right);
}

//Удаление
void DELETE(int data, Elem*& root)
{
    //   .  
    Elem* u = SEARCH(data, root);
    if (u == nullptr)
        return;

    //   ( )
    if (u->left == nullptr && u->right == nullptr && u == root)
    {
        delete root;
        root = nullptr;
        return;
    }

    //   
    if (u->left == nullptr && u->right != nullptr && u == root) // TODO  u==root
    {
        Elem* t = u->right;
        while (t->left != nullptr)
            t = t->left;
        u->data = t->data;
        u = t;
    }

    //   
    if (u->left != nullptr && u->right == nullptr && u == root) // TODO  u==root
    {
        Elem* t = u->left;
        while (t->right != nullptr)
            t = t->right;
        u->data = t->data;
        u = t;
    }

    //    
    if (u->left != nullptr && u->right != nullptr)
    {
        Elem* t = u->right;
        while (t->left != nullptr)
            t = t->left;
        u->data = t->data;
        u = t;
    }
    Elem* t;
    if (u->left == nullptr)
        t = u->right;
    else
        t = u->left;
    if (u->parent->left == u)
        u->parent->left = t;
    else
        u->parent->right = t;
    if (t != nullptr)
        t->parent = u->parent;
    delete u;
}



void CLEAR(Elem*& v)
{
    if (v == nullptr)
        return;
    CLEAR(v->left);

    CLEAR(v->right);

    delete v;
    v = nullptr;
}


int main()
{
    Elem* root = nullptr; //Создание корня

    std::ifstream file("1.txt");
    std::ofstream fin("2.txt");
    std::string line;
    while (file>>line)
    {
        if (line[0] == 'E')
            break;
        if (line[0] == '+')
            ADD(std::stoi(line), root);
        if (line[0] == '-')
            DELETE(std::stoi(line.substr(1, line.length() - 1)), root);
        if (line[0] == '?')
        {
            int k = 0;
            if ((SEARCH(std::stoi(line.substr(1, line.length() - 1)), root) == nullptr))
                fin << "n";
            else
            {
                DEEP(std::stoi(line.substr(1, line.length() - 1)), root, k);
                fin << k;
            }
        }
    }

    PASS(root);

    CLEAR(root);

    return 0;
}
