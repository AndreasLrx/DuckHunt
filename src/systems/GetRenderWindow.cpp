///
/// @file GetRenderWindow.cpp
/// @author Andréas Leroux (andreas.leroux@epitech.eu)
/// @brief
/// @version 1.0.0
/// @date 2022-12-16
///
/// @copyright Copyright (c) 2022
///
///

#include "GetRenderWindow.hpp"

ecstasy::integration::sfml::RenderWindow &getRenderWindow(ecstasy::Registry &registry)
{
    return registry.getResource<ecstasy::integration::sfml::RenderWindow>();
}
