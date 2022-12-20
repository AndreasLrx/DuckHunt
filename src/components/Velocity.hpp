///
/// @file Velocity.hpp
/// @author Andréas Leroux (andreas.leroux@epitech.eu)
/// @brief
/// @version 1.0.0
/// @date 2022-12-19
///
/// @copyright Copyright (c) 2022
///
///

#ifndef COMPONENTS_VELOCITY_HPP_
#define COMPONENTS_VELOCITY_HPP_

#include <SFML/Graphics.hpp>

class Velocity : public sf::Vector2f {
  public:
    template <typename... Args>
    Velocity(Args &&...args) : sf::Vector2f(std::forward<Args &&>(args)...)
    {
    }

    ~Velocity() = default;
};

#endif /* !COMPONENTS_VELOCITY_HPP_ */
