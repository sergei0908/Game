#include "Game.h"
#include <cmath>
#include <iostream>


// Конструктор
Game::Game() : window(sf::VideoMode(800, 600), "SFML Shooter")
{
    if (!texture_enemy.loadFromFile("texture_enemy.png"))
        std::cerr << "Error loading enemy texture\n";
    if (!texture_bullet.loadFromFile("C:/Users/lebed/work/cpp/MyGame/assets/bullet.png")) {
        std:: cerr <<  "Error loading texture bullet" << std::endl;
    }
    window.setFramerateLimit(60);
}

// Главный игровой цикл
void Game::run()
{
    while (window.isOpen())
    {
        processEvents();
        Update();
        render();
    }
}

// Обработка событий
void Game::processEvents()
{
    sf::Event event;

    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

// Обновление логики
void Game::Update()
{
    // стрельба
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
            sf::Vector2f playerPos = player.getPosition();
            sf::Vector2f enemyPos = enemies.back()->getPosition();
            sf::Vector2f dir = enemyPos - playerPos;

            float length = std::sqrt(dir.x * dir.x + dir.y * dir.y);
            if (length != 0)
                dir /= length;

            bullets.push_back(Bullet(playerPos, dir, texture_bullet));
    }

    // проверка поподания в моба
    for (auto enemy = enemies.begin(); enemy != enemies.end();)
    {
        for (auto iter = bullets.begin(); iter != bullets.end();)
        {
            if ((*enemy)->getBounds().intersects(iter->getBounds()))
            {
                (*enemy)->takeDamage(5);
                iter = bullets.erase(iter);
            }
            else
                ++iter;
        }

        if (!(*enemy)->isAlive())
            enemy = enemies.erase(enemy);
        else
            ++enemy;
    }

    // обновление всех событий  пуль
    for (auto& bullet : bullets)
        bullet.Update();

    // обновление событий игрока
    player.Update();

    // обновление всех событий мобов
    for (auto& enemy : enemies)
        enemy->Update();
}

// Отрисовка
void Game::render()
{
    window.clear(sf::Color::Black);
    player.Draw(window);

    for (auto& enemy : enemies) {
        enemy->Draw(window);
    }
    for (auto& bullet: bullets) {
        bullet.Draw(window);
    }

    window.display();
}