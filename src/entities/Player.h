#pragma once
#include "Entity.h"

class Player : public Entity{
private:
    bool isRight = true;
public:
    Player();
    ~Player() override = default;

    void Update() override;
    bool isAlive() const;
    void Draw(sf::RenderWindow & window) override;
    void takeDamage(int hp) override;
    sf::Vector2f getPosition() const;
};
