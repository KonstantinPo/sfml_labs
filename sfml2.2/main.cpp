#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cstdint>
#include <cmath>

static const uint32_t WINDOW_WIDTH = 800;
static const uint32_t WINDOW_HEIGHT = 600;

static const int pointCount = 200;
static const float radius = 200.f;
static const float moveRadius = 50.0f;
static const float period = 5.0f;

sf::ConvexShape DrawRose(const sf::Vector2f &&offset, float rotate)
{
    sf::ConvexShape shape;
    shape.setPosition({400, 300});
    shape.setFillColor(sf::Color(0xff, 0x09, 0x80));
    shape.setPointCount(pointCount);
    for (auto i = 0; i < pointCount; ++i)
    {
        auto angle = 2.0f * M_PI * i / pointCount;
        auto curRadius = std::sin(6 * angle) * radius;
        sf::Vector2f point(curRadius * std::sin(angle) + offset.x, curRadius * std::cos(angle) + offset.y);
        sf::Vector2f rotPoint(point.x * std::cos(rotate) - point.y * std::sin(rotate),
                              point.x * std::sin(rotate) + point.y * std::cos(rotate));
        shape.setPoint(i, rotPoint);
    }
    return shape;
}

int main()
{
    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Ellipse");
    sf::Clock clock;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        auto dt = clock.getElapsedTime().asSeconds();
        float angle = 2.0f * M_PI * dt / period;

        auto rose = DrawRose({moveRadius * std::cos(angle), moveRadius * std::sin(angle)}, angle);
        window.clear();
        window.draw(rose);
        window.display();
    }
}