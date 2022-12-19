///
/// @file Player.hpp
/// @author Andréas Leroux (andreas.leroux@epitech.eu)
/// @brief
/// @version 1.0.0
/// @date 2022-12-19
///
/// @copyright Copyright (c) 2022
///
///

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include <stddef.h>

class Player {
  public:
    Player();
    ~Player() = default;

    void reloadAmmo();
    void addScore(size_t score);
    size_t getScore() const;

  private:
    size_t _score;
    size_t _ammo;
};

#endif /* !PLAYER_HPP_ */
