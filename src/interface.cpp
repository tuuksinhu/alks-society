#include "interface.hpp"

#include <SFML/Graphics/Text.hpp>
#include <memory>

#include "color.hpp"

std::unique_ptr<sf::Text> UI::menuTitle = nullptr;
std::unique_ptr<sf::Text> UI::startTutorial = nullptr;
std::unique_ptr<sf::Text> UI::pauseTitle = nullptr;

void UI::centerOrigin(sf::Text& text) {
    sf::FloatRect textRect = text.getLocalBounds();

    text.setOrigin({textRect.position.x + textRect.size.x / 2.0f,
                    textRect.position.y + textRect.size.y / 2.0f});
}

void UI::init(const sf::Font& mainFont) {
    UI::menuTitle = std::make_unique<sf::Text>(mainFont, "Alks Society");
    UI::menuTitle->setCharacterSize(100);
    UI::menuTitle->setFillColor(sf::Color(Colors::mainTextColor));
    centerOrigin(*UI::menuTitle);
    UI::menuTitle->setPosition({960.0f, 300.0f});

    UI::pauseTitle = std::make_unique<sf::Text>(mainFont, "Game Paused!");
    UI::pauseTitle->setCharacterSize(100);
    UI::pauseTitle->setFillColor(sf::Color(Colors::mainTextColor));
    centerOrigin(*UI::pauseTitle);
    UI::pauseTitle->setPosition({960.0f, 300.0f});
}

void UI::drawMenu(sf::RenderWindow& window) {
    if (UI::menuTitle) window.draw(*UI::menuTitle);
    if (UI::startTutorial) window.draw(*UI::startTutorial);
}

void UI::drawPause(sf::RenderWindow& window) {
    if (UI::pauseTitle) window.draw(*UI::pauseTitle);
}
