#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
using namespace std::chrono_literals;

int main()
{
    int shape_x_1 = 100, shape_y_1 = 700;
    int shape_x_2 = 300, shape_y_2 = 775;
    int shape_x_3 = 500, shape_y_3 = 725;
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    //создание фигур
    sf::CircleShape shape_1(100.f);
    sf::RectangleShape shape_2(sf::Vector2f(120.f,50.f));
    sf::CircleShape shape_3(80.f, 8);
    //цвет фигур
    shape_1.setFillColor(sf::Color::Green);
    shape_2.setFillColor(sf::Color::Blue);
    shape_3.setFillColor(sf::Color::Cyan);
    //Система координат фигуры
    shape_1.setOrigin(100, 100);
    shape_2.setOrigin(60, 25);
    shape_3.setOrigin(80, 80);
    //положение фигур
    shape_1.setPosition(shape_x_1, shape_y_1);
    shape_2.setPosition(shape_x_2, shape_y_2);
    shape_3.setPosition(shape_x_3, shape_y_3);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        shape_y_1--;
        shape_y_2 = shape_y_2 - 3;
        shape_y_3 = shape_y_3 - 2;
        if (shape_y_1 < 100)
            shape_y_1 = 100;
        if (shape_y_2 < 25)
            shape_y_2 = 25;
        if (shape_y_3 < 80)
            shape_y_3 = 80;
        shape_1.setPosition(shape_x_1, shape_y_1);
        shape_2.setPosition(shape_x_2, shape_y_2);
        shape_3.setPosition(shape_x_3, shape_y_3);

        window.clear();
        window.draw(shape_1);
        window.draw(shape_2);
        window.draw(shape_3);
        window.display();

        std::this_thread::sleep_for(40ms);
    }

    return 0;
}