#pragma once
#include "Entity.h"

class Player;

class Enemy : public Entity {
private:
    Player* player;
    sf::Texture& texture;
public:
    Enemy(sf::Texture& texture, Player* player);
    ~Enemy() override = default;

    Enemy(const Enemy&) = delete;
    Enemy& operator=(const Enemy&) = delete;

    Enemy(Enemy&&) = default;
    Enemy& operator=(Enemy&&) = default;

    void setPosition(float x,float y);
    void Update() override;
    void takeDamage(int damage) override;
    bool isAlive();
    void Draw(sf::RenderWindow & window) override;
    sf::FloatRect getBounds() const;
};
