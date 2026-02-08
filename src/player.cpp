#include "player.hpp"

#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <cmath>

#include "color.hpp"

Player::Player() {
    shape.setSize({50.f, 50.f});
    shape.setFillColor(sf::Color(Colors::playerColor));
    shape.setOrigin({25.f, 25.f});
}

void Player::setPosition(sf::Vector2f pos) {
    shape.setPosition(pos);
}

void Player::update(float deltaTime) {
    sf::Vector2f movement(0.f, 0.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) movement.y -= playerWalk;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) movement.y += playerWalk;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) movement.x -= playerWalk;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) movement.x += playerWalk;

    if (movement.x != 0.f || movement.y != 0.f) {
        float length = std::sqrt(movement.x * movement.x + movement.y * movement.y);

        movement.x /= length;
        movement.y /= length;

        float multiplier = playerWalk;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift)) multiplier += playerRun;

        shape.move(movement * multiplier * speed * deltaTime);
    }
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(shape, states);
}
