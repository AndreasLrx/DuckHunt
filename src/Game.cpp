#include <SFML/Graphics.hpp>
#include <ecstasy/storages/MapStorage.hpp>

#include "Game.hpp"
#include "GameConfig.hpp"
#include "components/DrawOrder.hpp"
#include "components/Duck.hpp"
#include "components/Position.hpp"
#include "components/Velocity.hpp"
#include "resources/AssetsMap.hpp"
#include "resources/RandomDevice.hpp"

Game::Game(sf::Vector2f scale) : _scale(scale), _score(0), _round(0)
{
}

void Game::newRound(ecstasy::Registry &registry)
{
    ++_round;
    newWave(registry);
    _score += 1000;
}

void Game::newWave(ecstasy::Registry &registry)
{
    _player.reloadAmmo();
    for (int i = 0; i < 2; i++)
        addDuck(registry);
}

void Game::addDuck(ecstasy::Registry &registry)
{
    auto &rand = registry.getResource<RandomDevice>();

    auto &rect = registry.entityBuilder()
                     .with<sf::RectangleShape>(sf::Vector2f(34.f * _scale.x, 29.f * _scale.y))
                     .with<Position>(static_cast<float>(rand.randInt(0, 227)) * _scale.x,
                         static_cast<float>(rand.randInt(0, 160)) * _scale.y)
                     .with<DrawOrder>(0)
                     .with<Velocity>(20.f * _scale.x, 20.f * _scale.y)
                     .with<Duck>()
                     .build()
                     .get(registry.getStorage<sf::RectangleShape>());
    rect.setTexture(&registry.getResource<Textures>().get("sprites"));
    rect.setTextureRect(sf::IntRect(15, 259, 34, 29));
}
