#pragma once
#include <iostream>

namespace ao
{
	class Trap
	{
	public:
		Trap();
		Trap(int a1, int a2, int a3, int a4);
		int GetP();
		double GetS();
		~Trap();
		
	private:
		int m_a1;
		int m_a2;
		int m_a3;
		int m_a4;
	};
}
