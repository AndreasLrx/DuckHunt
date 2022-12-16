///
/// @file DisplayWindow.hpp
/// @author Andréas Leroux (andreas.leroux@epitech.eu)
/// @brief
/// @version 1.0.0
/// @date 2022-12-16
///
/// @copyright Copyright (c) 2022
///
///

#ifndef SYSTEMS_DISPLAYWINDOW_HPP_
#define SYSTEMS_DISPLAYWINDOW_HPP_

#include <ecstasy/system/ISystem.hpp>

class DisplayWindow : public ecstasy::ISystem {
  public:
    void run(ecstasy::Registry &registry) override final;
};

#endif /* !SYSTEMS_DISPLAYWINDOW_HPP_ */
