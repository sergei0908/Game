#include "Player.h"

#include <iostream>

// конструктор
Player::Player() {
    if (!runTexture.loadFromFile("C:/Users/lebed/work/cpp/MyGame/src/runTexture.png")) {
        std::cerr << "Error loading run.png" << std::endl;
    }
    if (!idleTexture.loadFromFile("C:/Users/lebed/work/cpp/MyGame/src/Character-Idle-2.png"))
    if (!attackTexture.loadFromFile("attackTexture.png")) {
        std::cerr << "Error loading attack.png" << std::endl;
    }
    if (!jumpTexture.loadFromFile("C:/Users/lebed/work/cpp/MyGame/src/jumpTexture.png")) {
        std::cerr << "Error loading jump.png" << std::endl;
    }
    sprite.setTexture(idleTexture);
    sprite.setOrigin(frameWidth / 2.f, frameHeight / 2.f);
    sprite.setPosition(400.f, 300.f);
    sprite.setTextureRect(sf::IntRect(0, 0, frameWidth, frameHeight));
    speed = 5.f;
    hp = 100;
}

// функция получения урона
void Player::takeDamage(int damage) {
    hp -= damage;
}

// проверка на жизнь
bool Player::isAlive() const {
    return hp > 0;
}

// получить координаты
sf::Vector2f Player::getPosition() const
{
    return sprite.getPosition();
}

// отрисовка
void Player::Draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Player::setAnimation(PlayerState newState)
{
    if (state == newState) return;

    state = newState;
    frame = 0;

    switch (state)
    {
        case PlayerState::Idle:
            sprite.setTexture(idleTexture);
            maxFrames = 11;
            break;

        case PlayerState::Run:
            sprite.setTexture(runTexture);
            maxFrames = 8;
            break;

        case PlayerState::Attack:
            sprite.setTexture(attackTexture);
            maxFrames = 9;
            break;

        case PlayerState::Jump:
            sprite.setTexture(jumpTexture);
            maxFrames = 6;
            break;
    }
}

void Player::updateAnimation()
{
    animationTimer += 0.016f;

    if (animationTimer >= animationSpeed)
    {
        animationTimer = 0;
        frame++;

        if (frame >= maxFrames)
            frame = 0;

        sprite.setTextureRect(
            sf::IntRect(frame * frameWidth, 0, frameWidth, frameHeight)
        );
    }
}

void Player::Update()
{
    position = {0.f, 0.f};
    bool moving = false;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        position.x = -speed;
        sprite.setScale(-1.f, 1.f);
        moving = true;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        position.x = speed;
        sprite.setScale(1.f, 1.f);
        moving = true;
    }

    // прыжок
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && onGround)
    {
        velocityY = jumpForce;
        onGround = false;
    }

    velocityY += gravity;
    sprite.move(0.f, velocityY);

    if (sprite.getPosition().y >= groundY)
    {
        sprite.setPosition(sprite.getPosition().x, groundY);
        velocityY = 0;
        onGround = true;
    }

    if (moving)
        setAnimation(PlayerState::Run);
    else if (!onGround)
        setAnimation(PlayerState::Jump);
    else
        setAnimation(PlayerState::Idle);

    sprite.move(position);

    updateAnimation();
}

