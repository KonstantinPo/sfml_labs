#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <cstdint>
#include <iostream>

static void pollEvents(sf::RenderWindow &window)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window.close();
            break;
        case sf::Event::MouseButtonPressed:
            std::cout << "mouse pressed,"
                      << " x=" << event.mouseButton.x
                      << " y=" << event.mouseButton.y
                      << std::endl;
            break;
        case sf::Event::MouseButtonReleased:
            std::cout << "mouse released,"
                      << " x=" << event.mouseButton.x
                      << " y=" << event.mouseButton.y
                      << std::endl;
            break;
        default:
            break;
        }
    }
}

static void redrawFrame(sf::RenderWindow &window)
{
    window.clear();
    window.display();
}

int main()
{
    constexpr uint32_t WINDOW_WIDTH = 800;
    constexpr uint32_t WINDOW_HEIGHT = 600;
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Print mouse event in terminal");
    while (window.isOpen())
    {
        pollEvents(window);
        redrawFrame(window);
    }
}