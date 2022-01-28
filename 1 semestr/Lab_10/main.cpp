#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
#include <Header.hpp>
#include <vector>
#include <iostream>



using namespace std::chrono_literals;

int main()
{
    const int width = 800;
    const int height = 600;

    sf::Texture texture;
    if (!texture.loadFromFile("1.jpg"))
    {
        std::cout << "ERROR" << std::endl;
        return -1;
    }
    sf::Sprite background(texture);


    //Инициализация 
    srand(time(0));
    sf::RenderWindow window(sf::VideoMode(width, height), "SFML works!");

    const int N = 20;

    std::vector<ao::Rectangle*> rectangles;
    //новое изменение для ООП (создание фигур)
    /*ao::Rectangle* rectangle = new ao::Rectangle(200, 200, 50, 50);
    rectangles.push_back(rectangle);
    ao::Rectangle* rectangle = new ao::Rectangle(400, 400, 50, 50);
    rectangles.push_back(rectangle);
    ao::Rectangle* rectangle = new ao::Rectangle(400, 200, 50, 50);
    rectangles.push_back(rectangle);*/

    for (int i = 0; i <= width; i += width / N)
        rectangles.push_back(new ao::Rectangle(i, 600, 20, 20, (rand() % 5+1))); //rand дает от 0 до 32767
    
    //Цикл
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //обработка
        for (const auto& rectangle : rectangles)
        {
            rectangle->Move();
            if(rectangle->GetY() < 10)
                rectangle->SetY(10);
        }


        //очистить окно от всего
        window.clear();


        //Фон
        window.draw(background);
        //Перемещение фигуры в буфер
        for (const auto& rectangle : rectangles)
            window.draw(*rectangle->Get());
        /*window.draw(*rectangle_1->Get());
        window.draw(*rectangle_2->Get());
        window.draw(*rectangle_3->Get());*/
        //Отобразить все, что есть в буфере
        window.display();

        std::this_thread::sleep_for(40ms);
    }
    //Удаление фигур (обязательно)
    for(const auto& rectangle : rectangles)
        delete rectangle;
    rectangles.clear();
    /*delete rectangle_1;
    delete rectangle_2;
    delete rectangle_3;*/

    return 0;
}