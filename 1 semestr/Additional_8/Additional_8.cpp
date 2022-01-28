#include <iostream>
#include "Header.hpp"

int main()
{
	int a, b, c, d;
	std::cin >> a >> b >> c >> d;
	ao::Trap trap(a, b, c, d);
	std::cout << "Perimetr = " << trap.GetP() << std::endl;
	std::cout << "Square = " << trap.GetS() << std::endl;
	return 0;
}
