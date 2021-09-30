#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cstdint>

int main()
{
    sf::RenderWindow window(sf::VideoMode({240, 220 * 3 + 40}), "traffic light");
    window.clear();
    float left = 10.0f;
    float top = 10.0f;
    sf::CircleShape red;
    red.setRadius(110);
    red.setPosition({left, top});
    red.setFillColor(sf::Color(0xFF, 0x00, 0x0));
    window.draw(red);

    sf::CircleShape yellow;
    yellow.setRadius(110);
    yellow.setPosition({left, top + 230});
    yellow.setFillColor(sf::Color(0xFF, 0xFF, 0x0));

    sf::CircleShape green;
    green.setRadius(110);
    green.setPosition({left, top + 230 * 2});
    green.setFillColor(sf::Color(0, 0xFF, 0x0));

    window.draw(red);
    window.draw(yellow);
    window.draw(green);

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