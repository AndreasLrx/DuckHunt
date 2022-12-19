#include <SFML/Graphics.hpp>
#include <ecstasy/storages/MapStorage.hpp>

#include "Game.hpp"
#include "GameConfig.hpp"
#include "RandomDevice.hpp"

Game::Game() : _score(0), _round(0)
{
}

void Game::newRound(GameConfig &config)
{
    ++_round;
    newWave(config);
}

void Game::newWave(GameConfig &config)
{
    _player.reloadAmmo();
    for (int i = 0; i < 2; i++)
        addDuck(config);
}

void Game::addDuck(GameConfig &config)
{
    auto size = config.getSize();
    float scaleY = (static_cast<float>(size.y) / 256.f);
    float scaleX = (static_cast<float>(size.x) / 256.f);
    auto &rand = config.getRegistry().getResource<RandomDevice>();

    auto &rect = config.getRegistry()
                     .entityBuilder()
                     .with<sf::RectangleShape>(sf::Vector2f(34.f * scaleX, 29.f * scaleY))
                     .build()
                     .get(config.getRegistry().getStorage<sf::RectangleShape>());
    rect.setTexture(&config.getTexture("sprites"));
    rect.setTextureRect(sf::IntRect(15, 259, 34, 29));
    rect.setPosition(sf::Vector2f(
        static_cast<float>(rand.randInt(0, 227)) * scaleX, static_cast<float>(rand.randInt(0, 160)) * scaleY));
}
