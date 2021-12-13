#include <iostream>
#include "Header.hpp"
#include <ctime>
namespace AO
{
	Device::Device(std::string name1, int address1)
	{
		name = name1;
		address = address1;
		energy = 0;
		temperature = 0;
	}
	Device::~Device()
	{

	};

	void Device::Poll()
	{
		srand(time(0));
		switch (address)
		{
		case 0:
			temperature = rand() % 1000;
			energy = 1000 + rand() % 10000;
			if (temperature == 0) 
				energy = 0;
			break;
		case 1:
			temperature = rand() % 1000;
			energy = 1000 + rand() % 10000;
			if (temperature == 0) 
				energy = 0;
			break;
		}
	}
	void Device::Print()
	{
		std::cout << "Name:  " << name << '\n' << "Number: " << address << '\n' << "Energy: " << energy << '\n' << "Temperature: " << temperature << '\n';
	}

}