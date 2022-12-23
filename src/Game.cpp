#include <SFML/Graphics.hpp>
#include <ecstasy/storages/MapStorage.hpp>

#include <ecstasy/query/conditions/include.hpp>
#include "Game.hpp"
#include "GameConfig.hpp"
#include "components/DrawOrder.hpp"
#include "components/Duck.hpp"
#include "components/DuckIcon.hpp"
#include "components/Position.hpp"
#include "components/Velocity.hpp"
#include "resources/AssetsMap.hpp"
#include "resources/RandomDevice.hpp"

#include <iostream>

Game::Game(sf::Vector2f scale) : _scale(scale), _score(0), _wave(0), _round(0)
{
}

void Game::newRound(ecstasy::Registry &registry)
{
    if (_round > 0) {
        _score += 1000;
        for (auto [rect, icon] : registry.query<sf::RectangleShape, DuckIcon>())
            rect.setFillColor(sf::Color::White);
    }
    ++_round;
    _wave = 0;
    newWave(registry);
}

void Game::newWave(ecstasy::Registry &registry)
{
    ++_wave;
    std::cerr << "Round " << _round << ", Wave " << _wave << std::endl;
    _player.reloadAmmo();
    for (int i = 0; i < 2; i++)
        addDuck(registry, static_cast<int>((_wave - 1) * 2 + i));
}

void Game::endWave(ecstasy::Registry &registry)
{
    if (_wave == 5)
        newRound(registry);
    else
        newWave(registry);
}

void Game::addDuck(ecstasy::Registry &registry, int id)
{
    auto &rand = registry.getResource<RandomDevice>();
    int randInt = rand.randInt(0, 100);
    Duck::Color color = (randInt < 50) ? Duck::Color::Black : ((randInt < 80) ? Duck::Color::Blue : Duck::Color::Brown);
    sf::Vector2i rectPos = (color == Duck::Color::Black)
        ? sf::Vector2i(15, 258)
        : ((color == Duck::Color::Blue) ? sf::Vector2i(207, 290) : sf::Vector2i(399, 322));

    auto &rect = registry.entityBuilder()
                     .with<sf::RectangleShape>(sf::Vector2f(34.f * _scale.x, 29.f * _scale.y))
                     .with<Position>(static_cast<float>(rand.randInt(0, 227)) * _scale.x,
                         static_cast<float>(rand.randInt(0, 160)) * _scale.y)
                     .with<DrawOrder>(0)
                     .with<Velocity>(20.f * _scale.x, 20.f * _scale.y)
                     .with<Duck>(id, color)
                     .build()
                     .get(registry.getStorage<sf::RectangleShape>());
    rect.setTexture(&registry.getResource<Textures>().get("sprites"));
    rect.setTextureRect(sf::IntRect(rectPos, sf::Vector2i(34, 30)));
}

void Game::killDuck(ecstasy::Registry &registry, ecstasy::Entity entity, Duck &duck)
{
    for (auto [rect, icon] : registry.query<sf::RectangleShape, DuckIcon>()) {
        if (icon.id == duck.id)
            rect.setFillColor(sf::Color::Red);
    }

    _score += (static_cast<size_t>(duck.color) + 1) * 500;
    registry.eraseEntity(entity);
    auto q = registry.query<Duck>();
    if (q.getMask().firstSet() == q.getMask().size() - 1)
        endWave(registry);
}
