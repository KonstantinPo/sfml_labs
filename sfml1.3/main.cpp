#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cstdint>

int main()
{
    sf::RenderWindow window(sf::VideoMode({570, 550}), "House");

    sf::RectangleShape house;
    house.setSize({455, 240});
    house.setFillColor(sf::Color(77, 46, 11));
    house.setPosition({55, 300});

    sf::RectangleShape door;
    door.setSize({72, 165});
    door.setFillColor(sf::Color(24, 23, 23));
    door.setPosition({100, 375});

    sf::ConvexShape roof;
    roof.setFillColor(sf::Color(93, 30, 23));
    roof.setPosition({3, -3});
    roof.setPointCount(4);
    roof.setPoint(0, {168, 185});
    roof.setPoint(1, {397, 185});
    roof.setPoint(2, {562, 303});
    roof.setPoint(3, {3, 303});

    sf::ConvexShape tube;
    tube.setFillColor(sf::Color(59, 56, 56));
    tube.setPosition({0, -5});
    tube.setPointCount(8);
    tube.setPoint(0, {353, 243});
    tube.setPoint(1, {353, 180});
    tube.setPoint(2, {341, 180});
    tube.setPoint(3, {341, 140});
    tube.setPoint(4, {399, 140});
    tube.setPoint(5, {399, 180});
    tube.setPoint(6, {387, 180});
    tube.setPoint(7, {387, 243});

    sf::Color smokeColor(191, 191, 191);
    sf::CircleShape smoke0(16);
    smoke0.setOrigin(16, 16);
    smoke0.setPosition({382, 128});
    smoke0.setFillColor(smokeColor);

    sf::CircleShape smoke1(18);
    smoke1.setOrigin(18, 18);
    smoke1.setFillColor(smokeColor);
    smoke1.setPosition({395, 103});

    sf::CircleShape smoke2(22);
    smoke2.setOrigin(22, 22);
    smoke2.setFillColor(smokeColor);
    smoke2.setPosition({412, 78});

    sf::CircleShape smoke3(23);
    smoke3.setOrigin(23, 23);
    smoke3.setFillColor(smokeColor);
    smoke3.setPosition({423, 54});

    window.draw(house);
    window.draw(door);
    window.draw(roof);
    window.draw(smoke0);
    window.draw(smoke1);
    window.draw(smoke2);
    window.draw(smoke3);
    window.draw(tube);
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
