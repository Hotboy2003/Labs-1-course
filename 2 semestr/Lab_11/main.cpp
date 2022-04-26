#include <iostream>
#include <string>

class LANG
{
public:
    LANG()
    {

    }

    virtual std::string someCodeRelatedThing() = 0;
    virtual std::string someCodeRelatedStuff() = 0;

    virtual ~LANG()
    {

    }
};

class JAVA : LANG
{
public:
    JAVA() : LANG()
    { 

    }

    std::string someCodeRelatedThing() override
    {
        return "java thing";
    }

    std::string someCodeRelatedStuff() override
    {
        return "java stuff";
    }

    virtual ~JAVA()
    {

    }

protected:
};

class C_PLUS_PLUS : public LANG
{
public:
    C_PLUS_PLUS() : LANG()
    {

    }

    std::string someCodeRelatedThing() override
    {
        return "C++ thing";
    }

    std::string someCodeRelatedStuff() override
    {
        return "C++ stuff";
    }

    virtual ~C_PLUS_PLUS() 
    {

    }
protected:
};

class PHP : public LANG
{
public:
    PHP() : LANG()
    {

    }

    std::string someCodeRelatedThing() override
    {
        return "PHP thing";
    }

    std::string someCodeRelatedStuff() override
    {
        return "PHP stuff";
    }

    virtual ~PHP()
    {

    }
protected:
};



int main()
{
    JAVA java;
    std::cout << java.someCodeRelatedStuff() << std::endl;

    PHP php;
    std::cout << php.someCodeRelatedThing() << std::endl;

    C_PLUS_PLUS cplusplus;
    std::cout << cplusplus.someCodeRelatedStuff() << std::endl;

    return 0;
}
