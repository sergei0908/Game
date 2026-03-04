#pragma once
#include <SFML/Graphics.hpp>

class Bullet {
    private:
    // sf::Texture& texture;
    sf::Sprite sprite;
    sf::Vector2f position;
    float speed;

    public:
    Bullet(sf::Vector2f pos, sf::Vector2f dir, sf::Texture& texture);
    void Update();
    void Draw(sf::RenderWindow& window);
    sf::FloatRect getBounds() const;
};