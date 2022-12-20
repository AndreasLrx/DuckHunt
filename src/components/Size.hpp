///
/// @file Size.hpp
/// @author Andréas Leroux (andreas.leroux@epitech.eu)
/// @brief
/// @version 1.0.0
/// @date 2022-12-19
///
/// @copyright Copyright (c) 2022
///
///

#ifndef COMPONENTS_SIZE_HPP_
#define COMPONENTS_SIZE_HPP_

#include <SFML/Graphics.hpp>

class Size : public sf::Vector2f {
  public:
    template <typename... Args>
    Size(Args &&...args) : sf::Vector2f(std::forward<Args &&>(args)...)
    {
    }

    ~Size() = default;
};

#endif /* !COMPONENTS_SIZE_HPP_ */
