///
/// @file FixedClock.hpp
/// @author Andréas Leroux (andreas.leroux@epitech.eu)
/// @brief
/// @version 1.0.0
/// @date 2022-12-20
///
/// @copyright Copyright (c) 2022
///
///

#ifndef FIXEDCLOCK_HPP_
#define FIXEDCLOCK_HPP_

#include <chrono>
#include <ecstasy/resources/Resource.hpp>

class FixedClock : public ecstasy::Resource {
  public:
    /// Starts the clock.
    FixedClock();

    /// Get the time elapsed since the last frame.
    std::chrono::microseconds elapsed() const;

    /// Get the time elapsed since the last frame (in seconds).
    float elapsedSeconds() const;

    void newFrame(std::chrono::microseconds frameTime);

  private:
    std::chrono::microseconds _lastFrame;
};

#endif /* !FIXEDCLOCK_HPP_ */
