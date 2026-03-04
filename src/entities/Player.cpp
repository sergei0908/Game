#include "Player.h"

#include <iostream>

Player::Player() {
    if (!texture.loadFromFile("C:/Users/lebed/work/cpp/MyGame/assets/texture_player.png")) {
        std::cerr << "Error loading texture_player.png" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setOrigin(texture.getSize().x / 2.f, texture.getSize().y / 2.f);
    sprite.setScale(0.25f, 0.25f);
    sprite.setPosition(400.f, 300.f);
    speed = 7.f;
    hp = 100;
}

void Player::takeDamage(int damage) {
    hp -= damage;
}

bool Player::isAlive() const {
    return hp > 0;
}

sf::Vector2f Player::getPosition() const
{
    return sprite.getPosition();
}

void Player::Draw(sf::RenderWindow& window) {
    window.draw(sprite);
}


void Player::Update() {
    position = {0.f, 0.f};
    sf::Vector2f pos = sprite.getPosition();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && pos.x > 15.f) {
        position.x = -speed;
        if (isRight) {
            sprite.setScale(-0.25f, 0.25f);
            isRight = false;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && pos.x < 785.f) {
        position.x = speed;
        if (!isRight) {
            sprite.setScale(0.25f, 0.25f);
            isRight = true;
        }

    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && pos.y > 30.f) {
        position.y = -speed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && pos.y < 570.f) {
        position.y = speed;
    }
    sprite.move(position);
}
