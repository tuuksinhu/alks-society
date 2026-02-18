#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>
#include <iostream>

#include "color.hpp"
#include "interface.hpp"
#include "map.hpp"
#include "player.hpp"
#include "screen.hpp"

int main() {
    sf::VideoMode mode({1920, 1080});

    sf::RenderWindow window(mode, "Alks Society", sf::State::Windowed);
    window.setFramerateLimit(165);
    std::cout << "\nHello, Society!\n" << std::endl;

    sf::Font mainFont;
    if (!mainFont.openFromFile("res/fonts/ARIAL.TTF")) {
        std::cerr << "Failed loading font in: 'res/fonts/ARIAL.TTF'" << std::endl;
        return -1;
    }

    Map gameMap;
    gameMap.addTileType(0, "res/tileset/tiles/Grass_Middle.png");
    gameMap.addTileType(1, "res/tileset/tiles/Path_Tile.png");

    gameMap.loadFromFile("res/map.txt", 128.f);

    Player player;
    player.setPosition({960.f, 540.f});

    sf::Clock clock;

    UI::init(mainFont);

    while (window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }

            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (Screen::CurrentState == GameState::Menu) {
                    if (keyPressed->code == sf::Keyboard::Key::Enter)
                        Screen::CurrentState = GameState::Game;

                    if (keyPressed->code == sf::Keyboard::Key::Q) window.close();
                } else if (Screen::CurrentState == GameState::Game) {
                    if (keyPressed->code == sf::Keyboard::Key::Escape)
                        Screen::CurrentState = GameState::Pause;
                } else if (Screen::CurrentState == GameState::Pause)
                    if (keyPressed->code == sf::Keyboard::Key::Escape ||
                        keyPressed->code == sf::Keyboard::Key::Enter) {
                        Screen::CurrentState = GameState::Game;
                    }
            }
        }

        if (Screen::CurrentState == GameState::Game) {
            player.update(deltaTime);
        }

        window.clear(sf::Color(Colors::Background));

        switch (Screen::CurrentState) {
            case GameState::Menu:
                UI::drawMenu(window);
                break;

            case GameState::Game:
                window.draw(gameMap);
                window.draw(player);
                break;

            case GameState::Pause:
                UI::drawPause(window);
                break;
        }

        window.display();
    }
    return 0;
}
