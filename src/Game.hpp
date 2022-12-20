///
/// @file Game.hpp
/// @author Andréas Leroux (andreas.leroux@epitech.eu)
/// @brief
/// @version 1.0.0
/// @date 2022-12-19
///
/// @copyright Copyright (c) 2022
///
///

#ifndef GAME_HPP_
#define GAME_HPP_

#include <SFML/Graphics.hpp>
#include <ecstasy/registry/Registry.hpp>
#include <ecstasy/resources/Resource.hpp>
#include "Player.hpp"

class GameConfig;
class Game : public ecstasy::Resource {
  public:
    Game(sf::Vector2f scale = sf::Vector2f(1.f, 1.f));
    ~Game() = default;

    void newRound(ecstasy::Registry &registry);
    void newWave(ecstasy::Registry &registry);
    void endWave(ecstasy::Registry &registry);

    void addDuck(ecstasy::Registry &registry);

  private:
    sf::Vector2f _scale;
    size_t _score;
    size_t _wave;
    size_t _round;
    Player _player;
};

#endif /* !GAME_HPP_ */
