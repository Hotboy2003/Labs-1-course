#pragma once
#include <SFML/Graphics.hpp>

// пространство имен
namespace ao
{
	// класс
	class Circle
	{
	public:
		// конструктор
		Circle(int x, int y, float r, float angle, float v0);
		
		// Деструктор 
		~Circle();

		// метод, задающий движение 
		void Move(float t, float g);

		// передача объекта
		sf::CircleShape* Get();

	private:
		int m_x, m_y;
		float m_r;
		float m_angle;
		float m_v0;
		sf::CircleShape* m_circle;
	};

	// вывод меню и выбор планеты
	int Print();

	// определение g
	float G(int k);
}