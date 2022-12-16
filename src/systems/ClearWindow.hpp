///
/// @file ClearWindow.hpp
/// @author Andréas Leroux (andreas.leroux@epitech.eu)
/// @brief
/// @version 1.0.0
/// @date 2022-12-16
///
/// @copyright Copyright (c) 2022
///
///

#ifndef SYSTEMS_CLEARWINDOW_HPP_
#define SYSTEMS_CLEARWINDOW_HPP_

#include <SFML/Graphics.hpp>
#include <ecstasy/system/ISystem.hpp>

class ClearWindow : public ecstasy::ISystem {
  public:
    ClearWindow(sf::Color clearColor = sf::Color::Black) : _color(clearColor)
    {
    }

    void run(ecstasy::Registry &registry) override final;

  private:
    sf::Color _color;
};

#endif /* !SYSTEMS_CLEARWINDOW_HPP_ */
