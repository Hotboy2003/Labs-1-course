#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
#include "Header.hpp"
#include <iostream>

using namespace std::chrono_literals;

int main()
{
    setlocale(LC_ALL, "Rus");
    float g = 0;
    float t = 0; // с


    // Фон
    sf::Texture texture;
    if (!texture.loadFromFile("img/Earth.jpg"))
    {
        std::cout << "ERROR: not found Earth.jpg" << std::endl;
        return -1;
    }
    sf::Sprite background(texture);


    // Определяем планету
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
    if ((k > 10) || (k < 1))
    {
        std::cout << "Написано же по русски, что нужно выбрать число от 1 до 10. По умолчанию выбрана планета Земля" << std::endl;
        g = ao::g_earth;
        if (!texture.loadFromFile("img/Earth.jpg"))
        {
            std::cout << "ERROR: not found Earth.jpg" << std::endl;
            return -1;
        }
        sf::Sprite background(texture);
    }
    else if (k == 1)
    {
        std::cout << "Ха, попался! Солнце - это звезда. Как можно этого не знать? Еще скажи что Земля плоская. По умолчанию выбрана планета Земля." << std::endl;
        g = ao::g_earth;
        if (!texture.loadFromFile("img/Earth.jpg"))
        {
            std::cout << "ERROR: not found Earth.jpg" << std::endl;
            return -1;
        }
        sf::Sprite background(texture);
    }
    else if (k == 10)
    {
        std::cout << "Ха, попался! Но я не виню тебя, мало кто знает, что Плутон с 2004 года перестал считаться планетой. Мне жалко эту планету. По умолчанию выбрана планета Земля" << std::endl;
        g = ao::g_earth;
        if (!texture.loadFromFile("img/Earth.jpg"))
        {
            std::cout << "ERROR: not found Earth.jpg" << std::endl;
            return -1;
        }
        sf::Sprite background(texture);
    }
    else if (k == 2)
    {
        g = ao::g_earth;
        if (!texture.loadFromFile("img/Earth.jpg"))
        {
            std::cout << "ERROR: not found Earth.jpg" << std::endl;
            return -1;
        }
        sf::Sprite background(texture);
    }
    else if (k == 3)
    {
        g = ao::g_merkuri;
        if (!texture.loadFromFile("img/Merkuri.jpg"))
        {
            std::cout << "ERROR: not found Merkuri.jpg" << std::endl;
            return -1;
        }
        sf::Sprite background(texture);
    }
    else if (k == 4)
    {
        g = ao::g_venera;
        if (!texture.loadFromFile("img/Venera.jpg"))
        {
            std::cout << "ERROR: not found Venera.jpg" << std::endl;
            return -1;
        }
        sf::Sprite background(texture);
    }
    else if (k == 5)
    {
        g = ao::g_mars;
        if (!texture.loadFromFile("img/Mars.jpg"))
        {
            std::cout << "ERROR: not found Masrs.jpg" << std::endl;
            return -1;
        }
        sf::Sprite background(texture);
    }
    else if (k == 6)
    {
        g = ao::g_jupiter;
        if (!texture.loadFromFile("img/Jupiter.jpg"))
        {
            std::cout << "ERROR: not found Jupiter.jpg" << std::endl;
            return -1;
        }
        sf::Sprite background(texture);
    }
    else if (k == 7)
    {
        g = ao::g_saturn;
        if (!texture.loadFromFile("img/Saturn.jpg"))
        {
            std::cout << "ERROR: not found Saturn.jpg" << std::endl;
            return -1;
        }
        sf::Sprite background(texture);
    }
    else if (k == 8)
    {
        g = ao::g_uran;
        if (!texture.loadFromFile("img/Uran.jpg"))
        {
            std::cout << "ERROR: not found Uran.jpg" << std::endl;
            return -1;
        }
        sf::Sprite background(texture);
    }
    else if (k == 9)
    {
        g = ao::g_neptun;
        if (!texture.loadFromFile("img/Neptun.jpg"))
        {
            std::cout << "ERROR: not found Neptun.jpg" << std::endl;
            return -1;
        }
        sf::Sprite background(texture);
    }

    //Создание окна
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Flying ball!");

    float sx = 20;
    float sy = 1060;

    ao::Circle* circle = nullptr;

    //Цикл (работает до тех пор пока окно открыто)
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

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

        window.draw(background);

        //Перемещение фигуры в буфер
        if (circle != nullptr)
            window.draw(*circle->Get());

        //Отобразить все что есть в буфер
        window.display();

        std::this_thread::sleep_for(40ms);
        t += 0.04;
    }
    //Удаление фигур (обязательно)
    if (circle != nullptr)
        delete circle;

    return 0;
}