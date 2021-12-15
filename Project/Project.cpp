#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
#include "Header.hpp"
#include <iostream>

using namespace std::chrono_literals;

int main()
{
    setlocale(LC_ALL, "Rus");
    float t = 0; // с
    float grav[11] = { 0, 0, 9.8, 3.7, 8.87, 3.721, 24.79, 10.44, 8.87, 11.15, 0 };

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
        std::cout << "Написано же по русски, что нужно выбрать число от 1 до 10. По умолчанию выбрана планета Земля" << std::endl;
    else if (k == 1)
        std::cout << "Ха, попался! Солнце - это звезда. Как можно этого не знать? Еще скажи что Земля плоская. По умолчанию выбрана планета Земля." << std::endl;
    else if (k == 10)
        std::cout << "Ха, попался! Но я не виню тебя, мало кто знает, что Плутон с 2004 года перестал считаться планетой. Мне жалко эту планету. По умолчанию выбрана планета Земля" << std::endl;

    float g = grav[k];
    sf::Sprite background;
    background.setTexture(plante[k]);

    /*if ((k > 10) || (k < 1))
    {
        std::cout << "Написано же по русски, что нужно выбрать число от 1 до 10. По умолчанию выбрана планета Земля" << std::endl;
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
        if (!texture.loadFromFile("img/Earth.jpg"))
        {
            std::cout << "ERROR: not found Earth.jpg" << std::endl;
            return -1;
        }
        sf::Sprite background(texture);
    }
    else if (k == 2)
    {
        if (!texture.loadFromFile("img/Earth.jpg"))
        {
            std::cout << "ERROR: not found Earth.jpg" << std::endl;
            return -1;
        }
        sf::Sprite background(texture);
    }
    else if (k == 3)
    {
        if (!texture.loadFromFile("img/Merkuri.jpg"))
        {
            std::cout << "ERROR: not found Merkuri.jpg" << std::endl;
            return -1;
        }
        sf::Sprite background(texture);
    }
    else if (k == 4)
    {
        if (!texture.loadFromFile("img/Venera.jpg"))
        {
            std::cout << "ERROR: not found Venera.jpg" << std::endl;
            return -1;
        }
        sf::Sprite background(texture);
    }
    else if (k == 5)
    {
        if (!texture.loadFromFile("img/Mars.jpg"))
        {
            std::cout << "ERROR: not found Masrs.jpg" << std::endl;
            return -1;
        }
        sf::Sprite background(texture);
    }
    else if (k == 6)
    {
        if (!texture.loadFromFile("img/Jupiter.jpg"))
        {
            std::cout << "ERROR: not found Jupiter.jpg" << std::endl;
            return -1;
        }
        sf::Sprite background(texture);
    }
    else if (k == 7)
    {
        if (!texture.loadFromFile("img/Saturn.jpg"))
        {
            std::cout << "ERROR: not found Saturn.jpg" << std::endl;
            return -1;
        }
        sf::Sprite background(texture);
    }
    else if (k == 8)
    {
        if (!texture.loadFromFile("img/Uran.jpg"))
        {
            std::cout << "ERROR: not found Uran.jpg" << std::endl;
            return -1;
        }
        sf::Sprite background(texture);
    }
    else if (k == 9)
    {
        if (!texture.loadFromFile("img/Neptun.jpg"))
        {
            std::cout << "ERROR: not found Neptun.jpg" << std::endl;
            return -1;
        }
        sf::Sprite background(texture);
    }*/
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