#pragma once
#include <SFML/Graphics.hpp>

namespace ao
{
	class Rectangle
	{
	public:
		Rectangle(int x, int y, float h, float w, float velocity);

		~Rectangle();

		sf::RectangleShape* Get();

		void Move();

		void SetY(int y);

		int GetY();

	private:
		int m_x, m_y;
		float m_h, m_w;
		float m_velocity;
		sf::RectangleShape* m_shape;
	};
}