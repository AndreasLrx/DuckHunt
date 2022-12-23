///
/// @file UpdateAnimation.hpp
/// @author Andréas Leroux (andreas.leroux@epitech.eu)
/// @brief
/// @version 1.0.0
/// @date 2022-12-23
///
/// @copyright Copyright (c) 2022
///
///

#ifndef UPDATEANIMATION_HPP_
#define UPDATEANIMATION_HPP_

#include <ecstasy/system/ISystem.hpp>

class UpdateAnimation : public ecstasy::ISystem {
  public:
    void run(ecstasy::Registry &registry) override final;
};

#endif /* !UPDATEANIMATION_HPP_ */
