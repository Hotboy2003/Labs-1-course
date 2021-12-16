#include <SFML/Graphics.hpp>
#include "Source.hpp"
#include <iostream>

// пространство имен
namespace ao
{
	// конструктор
	Circle::Circle(int x, int y, float r, float angle, float v0)
	{
		m_x = x;
		m_y = y;
		m_r = r;
		m_v0 = v0;
		m_angle = (2 * acos(-1) - angle);
		m_circle = new sf::CircleShape(m_r);
		m_circle->setOrigin(m_r, m_r);
		m_circle->setPosition(m_x, m_y);
		m_circle->setFillColor(sf::Color::Green);
	}

	// Деструктор 
	Circle::~Circle()
	{
		delete m_circle;
	}

	// метод, задающий движение 
	void Circle::Move(float t, float g)
	{
		float x = m_x + m_v0 * cos(m_angle) * t;
		float y = m_y + m_v0 * sin(m_angle) * t + g * t * t / 2;

		m_circle->setPosition(x, y);
	}

	// передача объекта
	sf::CircleShape* Circle::Get()
	{
		return m_circle;
	}

	//вывод текста и выбор планеты
	int Print()
	{
		int k;
		std::cout << "Выберите планету: " << std::endl;
		std::cout << "Солнце -- 1 " << std::endl;
		std::cout << "Земля -- 2 " << std::endl;
		std::cout << "Меркурий -- 3 " << std::endl;
		std::cout << "Венера -- 4 " << std::endl;
		std::cout << "Марс -- 5 " << std::endl;
		std::cout << "Юпитер -- 6 " << std::endl;
		std::cout << "Сатурн -- 7 " << std::endl;
		std::cout << "Уран -- 8 " << std::endl;
		std::cout << "Нептун -- 9 " << std::endl;
		std::cout << "Плутон -- 10 " << std::endl;

		std::cin >> k;
		return k;
	}

	// определение g
	float G(int k)
	{
		float grav[11] = { 0, 9.8, 9.8, 3.7, 8.87, 3.721, 24.79, 10.44, 8.87, 11.15, 9.8 };
		float g = grav[k];
		return g;
	}
}