#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <memory>

class UI {
   public:
    static void init(const sf::Font& mainFont);
    static void drawMenu(sf::RenderWindow& window);
    static void drawPause(sf::RenderWindow& window);

   private:
    static std::unique_ptr<sf::Text> menuTitle;
    static std::unique_ptr<sf::Text> startTutorial;
    static std::unique_ptr<sf::Text> pauseTitle;

    static void centerOrigin(sf::Text& text);
};
