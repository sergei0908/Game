#include "Enemy.h"

#include "Player.h"

void Enemy::Draw(sf::RenderWindow & window) {
    window.draw(sprite);
}

// конструктор
Enemy::Enemy(sf::Texture& tex, Player * player) : texture(tex), player(player){
    sprite.setTexture(tex);
    sprite.setOrigin(texture.getSize().x / 2.f, texture.getSize().y / 2.f);
    sprite.setScale(0.1f, 0.1f);
    sprite.setPosition(100.f, 300.f);
    speed = 0.5f;
    hp = 25;
}

// установить позицию для спрайта(текстуры)
void Enemy::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}

// обновление логики (перемещение мобов на игрока)
void Enemy::Update() {
    sf::Vector2f player_pos = player->getPosition();
    sf::Vector2f enemy_pos = sprite.getPosition();

    if (player_pos.x + 30 < enemy_pos.x) sprite.move(-speed, 0);
    if (player_pos.x - 30 > enemy_pos.x) sprite.move(speed, 0);
    if (player_pos.y - 30 > enemy_pos.y) sprite.move(0, speed);
    if (player_pos.y + 30 < enemy_pos.y) sprite.move(0, -speed);

}

// функция возвращает область текстуры для проверки столкновений с пулями
sf::FloatRect Enemy::getBounds() const {
    return sprite.getGlobalBounds();
}

// проверка на жизнь
bool Enemy::isAlive() {
    return hp > 0;
}

// получение урона
void Enemy::takeDamage(int damage) {
    hp -= damage;
}
