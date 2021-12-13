#include <iostream>
#include "Header.hpp"
#include <vector>


int main()
{
	setlocale(LC_ALL, "Rus");

	std::vector<VK::Device*> vec;
	VK::Device* device = new VK::Device("СПТ963", 0);
	vec.push_back(device);
	device = new VK::Device("МКТС", 1); //VK::Device* device1 = new VK::Device("МКТС", 1);
	vec.push_back(device);
	/*
	Если нужно добавить устройство, то дописать
	device = new VK::Device("...", ...);
	Можно реализовать кнопкой
	*/
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