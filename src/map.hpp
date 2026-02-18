#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <vector>

class Map : public sf::Drawable {
   public:
    Map();
    void addTileType(int id, const std::string& filePath);
    void buildMap(const std::vector<std::vector<int>>& layout, float tileSize);
    void loadFromFile(const std::string& path, float tileSize);

   private:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    std::map<int, sf::Texture> m_textures;  // Armazena as texturas (grama, areia, etc)
    std::vector<sf::Sprite> m_sprites;      // Todos os tiles posicionados na tela
};
