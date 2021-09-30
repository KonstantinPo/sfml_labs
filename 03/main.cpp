#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cstdint>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Convex shapes");

    sf::ConvexShape triangle;
    triangle.setFillColor(sf::Color(0xFF, 0, 0));
    triangle.setPosition({200, 120});
    triangle.setPointCount(3);
    triangle.setPoint(0, {50, -20});
    triangle.setPoint(1, {50, 20});
    triangle.setPoint(2, {-100, 0});

    sf::ConvexShape trapeze;
    trapeze.setFillColor(sf::Color(0xff, 0, 0xff));
    trapeze.setPosition(400, 300);
    trapeze.setPointCount(4);
    trapeze.setPoint(0, {-90, 0});
    trapeze.setPoint(1, {90, 0});
    trapeze.setPoint(2, {120, 60});
    trapeze.setPoint(3, {-120, 60});
    window.clear();
    window.draw(triangle);
    window.draw(trapeze);
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
