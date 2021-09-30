#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cstdint>

static const float BALL_SIZE = 40;
static const uint32_t WINDOW_WIDTH = 800;
static const uint32_t WINDOW_HEIGHT = 600;
int main()
{
    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Simple event loop");
    sf::CircleShape shape(BALL_SIZE);
    sf::Clock clock;
    shape.setFillColor(sf::Color(0xff, 0xff, 0xff));
    shape.setPosition({200, 120});
    sf::Vector2f speed(60.0f, 45.0f);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        auto dt = clock.restart().asSeconds();
        auto position = shape.getPosition();
        position += speed * dt;
        if ((position.x + 2 * BALL_SIZE >= WINDOW_WIDTH && speed.x > 0) ||
            (position.x < 0 && speed.x < 0))
            speed.x = -speed.x;
        if ((position.y + 2 * BALL_SIZE >= WINDOW_HEIGHT && speed.y > 0) ||
            (position.y < 0 && speed.y < 0))
            speed.y = -speed.y;
        shape.setPosition(position);

        window.clear();
        window.draw(shape);
        window.display();
    }
}