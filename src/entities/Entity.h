#pragma once
#include <SFML/Graphics.hpp>

class Entity {
protected:
    sf::Sprite sprite;
    sf::Texture texture;
    sf::Vector2f position;
    float speed;
    int hp;

public:
    virtual ~Entity() = default;
    virtual void Update() = 0;
    virtual void Draw(sf::RenderWindow& window) = 0;
    virtual void takeDamage(int hp) = 0;
    sf::Vector2f getPosition() const;
};
