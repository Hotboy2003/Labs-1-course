#include <Header.hpp>

namespace ao
{
	Rectangle::Rectangle(int x, int y, float h, float w, float velocity)
	{
		m_x = x;
		m_y = y;
		m_h = h;
		m_w = w;
		m_velocity = velocity;
		m_shape = new sf::RectangleShape(sf::Vector2f(m_h, m_w));
		m_shape->setOrigin(m_h / 2, m_w / 2);
		m_shape->setFillColor(sf::Color::Green);
		m_shape->setPosition(m_x, m_y);
	}
	Rectangle::~Rectangle()
	{
		delete m_shape;
	}

	sf::RectangleShape* Rectangle::Get() { return m_shape; }

	void Rectangle::Move()
	{
		m_y -= m_velocity;
		m_shape->setPosition(m_x, m_y);
	}

	void Rectangle::SetY(int y)
	{
		m_y = y;
		m_shape->setPosition(m_x, m_y);
	}

	int Rectangle::GetY() { return m_y; }
}