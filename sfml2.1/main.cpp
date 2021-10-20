#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cstdint>
#include <cmath>

static const float BALL_SIZE = 40;
static const uint32_t WINDOW_WIDTH = 800;
static const uint32_t WINDOW_HEIGHT = 600;
int main()
{
    sf::RenderWindow window(sf::VideoMode({WINDOW_WIDTH, WINDOW_HEIGHT}), "Wave Moving ball");
    sf::Clock clock;
    sf::Vector2f position(10, 350);

    sf::CircleShape ball(BALL_SIZE);
    ball.setFillColor(sf::Color(0xff, 0xff, 0xff));
    auto speedX = 100.0f;
    const auto amplY = 80.0f;
    const auto period = 2;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        auto dt = clock.getElapsedTime().asSeconds();
        sf::Vector2f offset(dt * speedX, amplY * std::sin(dt * 2.0f * (float)M_PI / period));
        offset += position;
        if ((offset.x + 2 * BALL_SIZE >= WINDOW_WIDTH || offset.x <= 0.0f))
        {
            speedX = -speedX;
            position = offset;
            clock.restart();
        }

        ball.setPosition(offset);
        window.clear();
        window.draw(ball);
        window.display();
    }
}