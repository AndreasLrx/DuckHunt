///
/// @file FixedClock.cpp
/// @author Andréas Leroux (andreas.leroux@epitech.eu)
/// @brief
/// @version 1.0.0
/// @date 2022-12-20
///
/// @copyright Copyright (c) 2022
///
///

#include "FixedClock.hpp"

FixedClock::FixedClock() : _lastFrame(std::chrono::microseconds::zero())
{
}

std::chrono::microseconds FixedClock::elapsed() const
{
    return _lastFrame;
}

float FixedClock::elapsedSeconds() const
{
    return std::chrono::duration_cast<std::chrono::duration<float, std::ratio<1>>>(_lastFrame).count();
}

void FixedClock::newFrame(std::chrono::microseconds frameTime)
{
    _lastFrame = frameTime;
}
