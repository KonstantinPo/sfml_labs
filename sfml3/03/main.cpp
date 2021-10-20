#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include <cstdint>
#include <iostream>

static void init(sf::ConvexShape &pointer)
{
    pointer.setPointCount(3);
    pointer.setPoint(0, {40, 0});
    pointer.setPoint(1, {-20, -20});
    pointer.setPoint(2, {-20, 20});
    pointer.setPosition({400, 300});
    pointer.setFillColor(sf::Color(0xFF, 0x80, 0x00));
}

static float toDegrees(float radians)
{
    return float(radians * 180.0 / M_PI);
}

static void update(sf::Vector2f &mousePosition, sf::ConvexShape &pointer, sf::Clock &clock)
{
    static auto curAngle = 0.0f;
    const sf::Vector2f delta = mousePosition - pointer.getPosition();
    float angle = toDegrees(std::atan2(delta.y, delta.x));
    float dtime = clock.getElapsedTime().asSeconds();

    float dw = 18.0f * dtime;
    float dAndle = angle - curAngle;

    if (dAndle < 0.0f)
    {
        if (dAndle > -180.0f)
            dAndle = std::max(dAndle, -dw);
        else
            dAndle = std::min(360.0f + dAndle, dw);
    }
    else
    {
        if (dAndle < 180.0f)
            dAndle = std::min(dAndle, dw);
        else
            dAndle = std::max(dAndle - 360.0f, -dw);
    }

    curAngle += dAndle;
    if (curAngle >= 180.0f)
        curAngle -= 360.0f;
    else if (curAngle <= -180.0f)
        curAngle += 360.0f;
    pointer.setRotation(curAngle);
    if (dtime > 0.0001f)
        clock.restart();
}

static void redrawFrame(sf::RenderWindow &window, sf::ConvexShape &pointer)
{
    window.clear();
    window.draw(pointer);
    window.display();
}

static void onMouseMove(const sf::Event::MouseMoveEvent &event, sf::Vector2f &mousePosition)
{
    std::cout << "mouse x=" << event.x << ", y=" << event.y << std::endl;
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
    constexpr uint32_t WINDOW_WIDTH = 800;
    constexpr uint32_t WINDOW_HEIGHT = 600;
    sf::ContextSettings setting;
    setting.antialiasingLevel = 8;
    sf::Clock clock;
    sf::RenderWindow window(
        sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT),
        "Pointer follow mouse", sf::Style::Default, setting);
    sf::ConvexShape pointer;
    sf::Vector2f mousePosition;
    init(pointer);

    while (window.isOpen())
    {
        pollEvents(window, mousePosition);
        update(mousePosition, pointer, clock);
        redrawFrame(window, pointer);
    }
}