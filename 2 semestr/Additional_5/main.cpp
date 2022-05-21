class Foo
{
public:
    Foo(int j) { i = new int[j]; }
    ~Foo() { delete i; } // добавить virtual
    //delete изменить на delete[]
    //добавить конструктор и оператор копирования
private:  //изменить на protected
    int* i;
};

// Foo изменить на public Foo
class Bar : Foo
{
public:
    Bar(int j) { i = new char[j]; }// добавить  : Foo(j)
    ~Bar() { delete i; }// добавить virtual
    // delete изменить на delete[]
private:  //изменить на protected
    char* i;  //изменить на int* i
};

void main() //void изменить на int
{
    Foo* f = new Foo(100);
    Foo* b = new Bar(200);
    *f = *b;
    delete f;
    delete b;
}

