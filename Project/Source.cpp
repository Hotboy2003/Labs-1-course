#include <SFML/Graphics.hpp>
#include "Source.hpp"

// пространство имен
namespace ao
{
	/*Planets::Planets(int x0, int y0, float r0)
	{
		m_x0 = x0;
		m_y0 = y0;
		m_r0 = r0;
		m_planets = new sf::CircleShape(m_r0);
		m_planets->setOrigin(m_r0, m_r0);
		m_planets->setPosition(m_x0, m_y0);
		m_planets->setFillColor(sf::Color::Green);
	}
	Planets::~Planets()
	{
		delete m_planets;
	}
	sf::CircleShape* Planets::Get()
	{
		return m_planets;
	}*/


	// класс
	Circle::Circle(int x, int y, float r, float angle, float v0)
	{
		// конструктор
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
}