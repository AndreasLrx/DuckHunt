///
/// @file DrawShape.hpp
/// @author Andréas Leroux (andreas.leroux@epitech.eu)
/// @brief
/// @version 1.0.0
/// @date 2022-12-16
///
/// @copyright Copyright (c) 2022
///
///

#ifndef SYSTEMS_DRAWSHAPE_HPP_
#define SYSTEMS_DRAWSHAPE_HPP_

#include <ecstasy/system/ISystem.hpp>

class DrawShape : public ecstasy::ISystem {
  public:
    void run(ecstasy::Registry &registry) override final;
};

#endif /* !SYSTEMS_DRAWSHAPE_HPP_ */
