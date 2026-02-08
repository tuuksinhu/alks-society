#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>

class Player : public sf::Drawable, public sf::Transformable {
   public:
    Player();
    void update(float deltaTime);
    void setPosition(sf::Vector2f pos);

   private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    sf::RectangleShape shape;
    float speed = 400.0f;
    float playerWalk = 1.0f;
    float playerRun = 0.5f;

    enum class playerWeapon { NONE, GUN };
};
