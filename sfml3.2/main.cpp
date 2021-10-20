#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include <cstdint>
#include <iostream>

constexpr uint32_t WINDOW_WIDTH = 800;
constexpr uint32_t WINDOW_HEIGHT = 600;

struct Eye
{
    sf::ConvexShape white;
    sf::ConvexShape black;
    sf::Vector2f moveRadius;
    float angle;
};

sf::Vector2f toEuclidean(float radius, float angle)
{
    return {
        radius * cos(angle),
        radius * sin(angle)};
}

float toDegrees(float radians)
{
    return radians * 180.0f / M_PI;
}

float toRadians(float degrees)
{
    return degrees * M_PI / 180.0;
}

static void updateBlack(Eye &eye)
{
    auto radians = toRadians(eye.angle);
    sf::Vector2f offset(eye.moveRadius.x * std::cos(radians), eye.moveRadius.y * std::sin(radians));
    auto origin = eye.white.getPosition();
    origin += offset;
    eye.black.setPosition(origin.x, origin.y);
}

static void initEyes(Eye &left, Eye &right)
{
    const int pointCount = 200;
    sf::Color white(0xff, 0xff, 0xff), black(0, 0, 0);
    sf::Vector2f whiteRadius(50, 100), blackRadius(14, 20);

    left.angle = -45.0f;
    left.moveRadius = {25, 70};
    left.white.setPosition({WINDOW_WIDTH / 3, WINDOW_HEIGHT / 2});
    left.white.setFillColor(white);
    left.white.setPointCount(pointCount);

    right.moveRadius = left.moveRadius;
    right.angle = left.angle;
    right.white.setPosition({1.5f * WINDOW_WIDTH / 3, WINDOW_HEIGHT / 2});
    right.white.setFillColor(white);
    right.white.setPointCount(pointCount);

    left.black.setPosition({WINDOW_WIDTH / 3, WINDOW_HEIGHT / 2});
    left.black.setFillColor(black);
    left.black.setPointCount(pointCount);

    right.black.setPosition({1.5f * WINDOW_WIDTH / 3, WINDOW_HEIGHT / 2});
    right.black.setFillColor(black);
    right.black.setPointCount(pointCount);

    for (auto i = 0; i < pointCount; ++i)
    {
        auto angle = 2.0f * M_PI * i / pointCount;
        auto sin = std::sin(angle);
        auto cos = std::cos(angle);
        sf::Vector2f point(whiteRadius.x * sin, whiteRadius.y * cos);
        right.white.setPoint(i, point);
        left.white.setPoint(i, point);
        point = {blackRadius.x * sin, blackRadius.y * cos};
        left.black.setPoint(i, point);
        right.black.setPoint(i, point);
    }
    updateBlack(left);
    updateBlack(right);
}

static void update(sf::Vector2f &mousePosition, Eye &left, Eye &right)
{
    sf::Vector2f delta = mousePosition - left.white.getPosition();
    left.angle = toDegrees(atan2(delta.y, delta.x));
    //std::cout << " left delta y =" << delta.y << ", left delta x = " << delta.x << std::endl;
    delta = mousePosition - right.white.getPosition();
    right.angle = toDegrees(atan2(delta.y, delta.x));
    std::cout << " left angle =" << left.angle << ", right angle =" << right.angle << std::endl;
    updateBlack(left);
    updateBlack(right);
}

static void redrawFrame(sf::RenderWindow &window, Eye &left, Eye &right)
{
    window.clear();
    window.draw(left.white);
    window.draw(left.black);
    window.draw(right.white);
    window.draw(right.black);
    window.display();
}

static void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
    //std::cout << "mouse x=" << event.x << ", y=" << event.y << std::endl;
    mousePosition = {float(event.x), float(event.y)};
}

static void pollEvents(sf::RenderWindow &window, sf::Vector2f &mousePosition)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::MouseMoved:
            onMouseMove(event.mouseMove, mousePosition);
            break;
        default:
            break;
        }
    }
}

int main()
{
    sf::ContextSettings setting;
    setting.antialiasingLevel = 8;
    sf::RenderWindow window(
        sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
        "Seeking eyes", sf::Style::Default, setting);
    sf::Vector2f mousePosition;
    Eye left, right;
    initEyes(left, right);
    while (window.isOpen())
    {
        pollEvents(window, mousePosition);
        update(mousePosition, left, right);
        redrawFrame(window, left, right);
    }
    return 0;
}