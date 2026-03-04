#include "Bullet.h"


#include <iostream>

Bullet::Bullet(sf::Vector2f pos, sf::Vector2f dir, sf::Texture& texture) {
    sprite.setTexture(texture);
    speed = 10.f;
    position = dir * speed;
    sprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
    sprite.setScale(0.05f, 0.05f);
    sprite.setPosition(pos);
}

void Bullet::Update() {
    sprite.move(position);
}

void Bullet::Draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

sf::FloatRect Bullet::getBounds() const {
    return sprite.getGlobalBounds();
}