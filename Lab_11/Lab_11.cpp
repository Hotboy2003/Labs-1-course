#include <iostream>
#include "Header.hpp"
#include <vector>


int main()
{
	setlocale(LC_ALL, "Rus");

	std::vector<AO::Device*> vec;
	AO::Device* device = new AO::Device("СПТ963", 0);
	vec.push_back(device);
	device = new AO::Device("МКТС", 1);

	for (auto& i : vec)
	{
		i->Poll();
		i->Print();
	}
	for (int i = 0; i < vec.size(); i++)
	{
		delete vec[i];
	}
}