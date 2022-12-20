///
/// @file Movement.hpp
/// @author Andréas Leroux (andreas.leroux@epitech.eu)
/// @brief
/// @version 1.0.0
/// @date 2022-12-19
///
/// @copyright Copyright (c) 2022
///
///

#ifndef MOVEMENT_HPP_
#define MOVEMENT_HPP_

#include <ecstasy/system/ISystem.hpp>

class Movement : public ecstasy::ISystem {
  public:
    void run(ecstasy::Registry &registry) override final;
};

#endif /* !MOVEMENT_HPP_ */
