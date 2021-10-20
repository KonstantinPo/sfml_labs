#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cstdint>
#include <cmath>

static const uint32_t WINDOW_WIDTH = 800;
static const uint32_t WINDOW_HEIGHT = 600;

static const int pointCount = 200;
static const sf::Vector2f elipseRadius(200.f, 80.f);

int main()
{
    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Ellipse");
    sf::ConvexShape shape;
    shape.setPosition({400, 300});
    shape.setFillColor(sf::Color(0xff, 0xff, 0xff));
    shape.setPointCount(pointCount);
    for (auto i = 0; i < pointCount; ++i)
    {
        auto angle = 2.0f * M_PI * i / pointCount;
        sf::Vector2f point(elipseRadius.x * std::sin(angle), elipseRadius.y * std::cos(angle));
        shape.setPoint(i, point);
    }
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}