#include <iostream>
#include <string>

class JAVA
{
public:
    JAVA()
    {

    }

    virtual void PRINTHELLOWORLD()
    {
        std::cout << "java hello world" << std::endl;
    }

    virtual ~JAVA()
    {

    }

protected:
};

class C_PLUS_PLUS : public JAVA
{
public:
    C_PLUS_PLUS() : JAVA()
    {

    }

    void PRINTHELLOWORLD() override
    {
        std::cout << "c_plus_plus hello world" << std::endl;
    }

    virtual ~C_PLUS_PLUS() 
    {

    }
protected:
};

class PHP : public JAVA
{
public:
    PHP() : JAVA()
    {

    }

    void PRINTHELLOWORLD() override
    {
        std::cout << "PHP hello world" << std::endl;
    }

    virtual ~PHP()
    {

    }
protected:
};



int main()
{
    JAVA java;
    java.PRINTHELLOWORLD();

    C_PLUS_PLUS cplusplus;
    cplusplus.PRINTHELLOWORLD();

    PHP php;
    php.PRINTHELLOWORLD();

    return 0;
}
