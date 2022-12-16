///
/// @file GetRenderWindow.hpp
/// @author Andréas Leroux (andreas.leroux@epitech.eu)
/// @brief
/// @version 1.0.0
/// @date 2022-12-16
///
/// @copyright Copyright (c) 2022
///
///

#ifndef SYSTEMS_GETRENDERWINDOW_HPP_
#define SYSTEMS_GETRENDERWINDOW_HPP_

#include <ecstasy/integrations/sfml/resources/RenderWindow.hpp>
#include <ecstasy/registry/Registry.hpp>

ecstasy::integration::sfml::RenderWindow &getRenderWindow(ecstasy::Registry &registry);

#endif /* !SYSTEMS_GETRENDERWINDOW_HPP_ */
