#pragma once
#include <SFML/Graphics.hpp>

enum class GameState { Menu, Game, Pause };

class Screen {
   public:
    static GameState CurrentState;
};
