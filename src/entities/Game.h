#pragma once

#include <memory>
#include <SFML/Graphics.hpp>
#include <vector>

#include "Player.h"
#include "Enemy.h"
#include "Bullet.h"

class Game
{
private:
    sf::RenderWindow window;
    sf::Clock clock;
    sf::Texture texture_enemy;
    sf::Texture texture_bullet;
    Player player;
    std::vector<std::unique_ptr<Enemy>> enemies;
    std::vector<Bullet> bullets;

    void processEvents();   // обработка событий
    void Update();  // обновление логики
    void render();          // отрисовка

public:
    Game();
    void run();
};