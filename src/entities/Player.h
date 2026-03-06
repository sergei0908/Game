#pragma once
#include "Entity.h"

class Player : public Entity{
private:
    enum class PlayerState {
        Idle,
        Run,
        Attack,
        Jump
    };
    PlayerState state = PlayerState::Idle;
    sf::Texture runTexture;
    sf::Texture attackTexture;
    sf::Texture jumpTexture;
    sf::Texture idleTexture;
    int frame = 0;
    float animationTimer = 0;
    float animationSpeed = 0.1f;
    int frameWidth = 96;
    int frameHeight = 64;
    int maxFrames = 10;

    float velocityY = 0.f;
    float gravity = 0.5f;
    float jumpForce = -12.f;
    bool onGround = true;
    float groundY = 300.f;
public:
    Player();
    ~Player() override = default;

    void Update() override;
    bool isAlive() const;
    void Draw(sf::RenderWindow & window) override;
    void takeDamage(int hp) override;
    void setAnimation(PlayerState newState);
    void updateAnimation();
    sf::Vector2f getPosition() const;
};
