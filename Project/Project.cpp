#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
#include "Source.hpp"
#include <iostream>

//using namespace std::chrono_literals;

int main()
{
    // установка русского языка
    setlocale(LC_ALL, "Rus");

    // Начальные переменные
    float t = 0; // с
    float sx = 20; // положение шарика по иксу (м)
    float sy = 1060; // положение шарика по игреку (м)

    // создаем пустой объект
    ao::Circle* circle = nullptr;

    // создание текста
    sf::Font font; 
    sf::Text text;
    if (!font.loadFromFile("fonts\\arial.ttf"))
    {
        std::cout << "Error font wasn't load" << std::endl;
        return -1;
    }
    text.setFont(font);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold);

    // Фон
    sf::Image planimg[11];
    planimg[1].loadFromFile("img/Earth.jpg");
    planimg[2].loadFromFile("img/Earth.jpg");
    planimg[3].loadFromFile("img/Merkuri.jpg");
    planimg[4].loadFromFile("img/Venera.jpg");
    planimg[5].loadFromFile("img/Mars.jpg");
    planimg[6].loadFromFile("img/Jupiter.jpg");
    planimg[7].loadFromFile("img/Saturn.jpg");
    planimg[8].loadFromFile("img/Uran.jpg");
    planimg[9].loadFromFile("img/Neptun.jpg");
    planimg[10].loadFromFile("img/Earth.jpg");

    sf::Texture plante[11];
    plante[1].loadFromImage(planimg[1]);
    plante[2].loadFromImage(planimg[2]);
    plante[3].loadFromImage(planimg[3]);
    plante[4].loadFromImage(planimg[4]);
    plante[5].loadFromImage(planimg[5]);
    plante[6].loadFromImage(planimg[6]);
    plante[7].loadFromImage(planimg[7]);
    plante[8].loadFromImage(planimg[8]);
    plante[9].loadFromImage(planimg[9]);
    plante[10].loadFromImage(planimg[10]);

    // Определяем планету
    int k = ao::Print();

    // если пользователь выберет что то не то
    if ((k > 10) || (k < 1))
    {
        k = 2;
        text.setString(L"Написано же по русски, что нужно выбрать число от 1 до 10. По умолчанию выбрана планета Земля");
    }
    else if (k == 1)
        text.setString(L"Ха, попался! Солнце - это звезда. Как можно этого не знать? Еще скажи что Земля плоская. По умолчанию выбрана планета Земля.");
    else if (k == 10)
        text.setString(L"Ха, попался! Но я не виню тебя, мало кто знает, что Плутон с 2004 года перестал считаться планетой. Мне жалко эту планету. По умолчанию выбрана планета Земля");

    // определяем фон
    sf::Sprite background;
    background.setTexture(plante[k]);
    // определяем g
    float g = ao::G(k);

    //Создание окна
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Flying ball!");

    //Цикл (работает до тех пор пока окно открыто)
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // взааимодействие с мышью
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            sf::Vector2i mp = sf::Mouse::getPosition(window);

            float d = sqrt((mp.x - sx) * (mp.x - sx) + (mp.y - sy) * (mp.y - sy))/5;
            float dx = mp.x - sx;
            float dy = sy - mp.y;
            float angle = atan(dy / dx);
            
            if (circle != nullptr)
                delete circle;

            circle = new ao::Circle(sx, sy, 20, angle, d);
            t = 0;
        }

        // Движение шарика
        if (circle != nullptr)
            circle->Move(t, g);

        //очистить окно от всего
        window.clear();

        // рисуем фон и текст
        window.draw(background);
        window.draw(text);

        //Перемещение фигуры в буфер
        if (circle != nullptr)
            window.draw(*circle->Get());

        //Отобразить все что есть в буфер
        window.display();

        //изменение времени
        //std::this_thread::sleep_for(40ms);
        t += 0.04;
    }

    //Удаление фигур (обязательно)
    if (circle != nullptr)
        delete circle;

    return 0;
}