#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cstdint>

int main()
{
    sf::RenderWindow window(sf::VideoMode({640, 480}), "KPA");
    window.clear();

    sf::RectangleShape sh1;
    sh1.setSize({20, 100});
    sh1.setRotation(0);
    sh1.setPosition({50, 40});
    sh1.setFillColor(sf::Color(0xFF, 0x00, 0x00));

    sf::RectangleShape sh2;
    sh2.setSize({45, 20});
    sh2.setRotation(-40);
    sh2.setPosition({70, 70});
    sh2.setFillColor(sf::Color(0xFF, 0x00, 0x00));

    sf::RectangleShape sh3;
    sh3.setSize({60, 20});
    sh3.setOrigin(0, 20);
    sh3.setRotation(60);
    sh3.setPosition({70, 88});
    sh3.setFillColor(sf::Color(0xFF, 0x00, 0x00));

    sf::RectangleShape sh4;
    sh4.setSize({20, 100});
    sh4.setRotation(0);
    sh4.setPosition({140, 40});
    sh4.setFillColor(sf::Color(0x00, 0xFF, 0x00));

    sf::RectangleShape sh5;
    sh5.setSize({20, 100});
    sh5.setRotation(0);
    sh5.setPosition({200, 40});
    sh5.setFillColor(sf::Color(0x00, 0xFF, 0x00));

    sf::RectangleShape sh6;
    sh6.setSize({80, 20});
    sh6.setRotation(0);
    sh6.setPosition({140, 40});
    sh6.setFillColor(sf::Color(0x00, 0xFF, 0x00));

    sf::RectangleShape sh7;
    sh7.setSize({80, 20});
    sh7.setRotation(0);
    sh7.setPosition({140, 80});
    sh7.setFillColor(sf::Color(0x00, 0xFF, 0x00));

    sf::RectangleShape sh8;
    sh8.setSize({20, 100});
    sh8.setRotation(0);
    sh8.setPosition({240, 40});
    sh8.setFillColor(sf::Color(0xFF, 0xFF, 0x00));

    sf::RectangleShape sh9;
    sh9.setSize({20, 100});
    sh9.setRotation(0);
    sh9.setPosition({300, 40});
    sh9.setFillColor(sf::Color(0xFF, 0xFF, 0x00));

    sf::RectangleShape sh10;
    sh10.setSize({80, 20});
    sh10.setRotation(0);
    sh10.setPosition({240, 40});
    sh10.setFillColor(sf::Color(0xFF, 0xFF, 0x00));

    window.draw(sh1);
    window.draw(sh2);
    window.draw(sh3);
    window.draw(sh4);
    window.draw(sh5);
    window.draw(sh6);
    window.draw(sh7);

    window.draw(sh8);
    window.draw(sh9);
    window.draw(sh10);

    window.display();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
    }
}