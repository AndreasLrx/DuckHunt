#include "Player.hpp"

Player::Player() : _score(0), _ammo(3)
{
}

void Player::reloadAmmo()
{
    _ammo = 3;
}

void Player::addScore(size_t score)
{
    _score += score;
}

size_t Player::getScore() const
{
    return _score;
}
