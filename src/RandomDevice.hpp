/*
** EPITECH PROJECT, 2022
** DuckHunt
** File description:
** RandomDevice
*/

#ifndef RANDOMDEVICE_HPP_
#define RANDOMDEVICE_HPP_

#include <ecstasy/resources/Resource.hpp>
#include <random>

class RandomDevice : public ecstasy::Resource {
  public:
    /// Construct a new Random Device resource
    RandomDevice() : _generation(_device())
    {
    }

    /// Generate a random number in the interval [min, max]
    ///
    /// @tparam numeric type of the numbers.
    /// @param min minimum value.
    /// @param max maximum value.
    /// @return numeric value in the interval [min, max]
    template <typename numeric>
    numeric randInt(numeric min, numeric max)
    {
        std::uniform_int_distribution<std::mt19937::result_type> dist(min, max);

        return static_cast<numeric>(dist(_generation));
    }

  private:
    std::random_device _device;
    std::mt19937 _generation;
};

#endif /* !RANDOMDEVICE_HPP_ */
