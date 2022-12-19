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

#include <ecstasy/registry/Registry.hpp>
#include "Player.hpp"

class GameConfig;
class Game {
  public:
    Game();
    ~Game() = default;

    void newRound(GameConfig &config);
    void newWave(GameConfig &config);

    void addDuck(GameConfig &config);

  private:
    size_t _score;
    size_t _round;
    Player _player;
};

#endif /* !GAME_HPP_ */
