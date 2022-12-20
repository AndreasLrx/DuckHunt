///
/// @file Position.hpp
/// @author Andréas Leroux (andreas.leroux@epitech.eu)
/// @brief
/// @version 1.0.0
/// @date 2022-12-19
///
/// @copyright Copyright (c) 2022
///
///

#ifndef COMPONENTS_POSITION_HPP_
#define COMPONENTS_POSITION_HPP_

#include <SFML/Graphics.hpp>

class Position : public sf::Vector2f {
  public:
    template <typename... Args>
    Position(Args &&...args) : sf::Vector2f(std::forward<Args &&>(args)...)
    {
    }

    ~Position() = default;
};

#endif /* !COMPONENTS_POSITION_HPP_ */
