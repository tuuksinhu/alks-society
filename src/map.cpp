#include "map.hpp"

#include <fstream>
#include <iostream>
#include <sstream>

Map::Map() {}

void Map::addTileType(int id, const std::string& filePath) {
    sf::Texture tex;
    if (tex.loadFromFile(filePath)) {
        m_textures[id] = tex;
    }
}

void Map::buildMap(const std::vector<std::vector<int>>& layout, float tileSize) {
    m_sprites.clear();

    for (size_t y = 0; y < layout.size(); ++y) {
        for (size_t x = 0; x < layout[y].size(); ++x) {
            int type = layout[y][x];

            if (m_textures.count(type)) {
                sf::Sprite sprite(m_textures[type]);

                sf::FloatRect bounds = sprite.getLocalBounds();

                float scaleX = tileSize / bounds.size.x;
                float scaleY = tileSize / bounds.size.y;

                sprite.setScale({scaleX, scaleY});
                sprite.setPosition({x * tileSize, y * tileSize});

                m_sprites.push_back(sprite);
            }
        }
    }
}

void Map::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    for (const auto& sprite : m_sprites) {
        target.draw(sprite, states);
    }
}

void Map::loadFromFile(const std::string& path, float tileSize) {
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "Error loading file: " << path << std::endl;
        return;
    }

    std::vector<std::vector<int>> layout;
    std::string line;

    while (std::getline(file, line)) {
        std::vector<int> row;
        std::stringstream ss(line);
        int tileID;

        while (ss >> tileID) {
            row.push_back(tileID);
        }

        if (!row.empty()) {
            layout.push_back(row);
        }
    }

    file.close();

    buildMap(layout, tileSize);
}
