#include "Header.hpp"

namespace ao
{
	Trap::Trap()
	{
		std::cout << "Empty constructor" << std::endl;
	}

	Trap::Trap(int a1, int a2, int a3, int a4)
	{
		m_a1 = a1;
		m_a2 = a2;
		m_a3 = a3;
		m_a4 = a4;
		if (a1 <= 0)
		{
			std::cout << "a1 <= 0" << std::endl;
			m_a1 = 1;
		}
		if (a2 <= 0)
		{
			std::cout << "a2 <= 0" << std::endl;
			m_a2 = 1;
		}
		if (a3 <= 0)
		{
			std::cout << "a3 <= 0" << std::endl;
			m_a3 = 1;
		}
		if (a4 <= 0)
		{
			std::cout << "a4 <= 0" << std::endl;
			m_a4 = 1;
		}

		std::cout << "Constructor works!" << std::endl;
	}

	Trap::~Trap()
	{
		std::cout << "Destructor works!" << std::endl;
	}

	int Trap::GetP()
	{
		return m_a1 + m_a2 + m_a3 + m_a4;
	}

	double Trap::GetS()
	{
		switch (m_a2 == m_a4)
		{
		case true:
			return ((m_a3 + m_a1) * sqrt((m_a4 * m_a4 - ((m_a3 - m_a1) / 2) * ((m_a3 - m_a1) / 2)))) / 2;
		case false:
			return ((m_a4 + m_a2) * sqrt((m_a1 * m_a1 - ((m_a4 - m_a2) / 2) * ((m_a4 - m_a2) / 2)))) / 2;
		}
	}
}
