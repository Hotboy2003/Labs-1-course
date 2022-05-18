#include <iostream>
#include <string>
#include <memory>

class Teacher
{
public:
	Teacher(const std::string& name)
	{
		m_name = name;
	}

	~Teacher()
	{
		std::cout << "Teacher destructor" << std::endl;
	}

private:
	std::string m_name;
};

class Student
{
	Student(const std::string& name)
	{
		m_name = name;
	}

	~Student()
	{
		std::cout << "Student destructor" << std::endl;
	}
private:
	std::string m_name;
};

int main()
{
	std::shared_ptr<Teacher> Sasha;
	std::shared_ptr<Teacher> Maksim = Sasha;
	std::shared_ptr<Teacher> Petya;
	return 0;
}