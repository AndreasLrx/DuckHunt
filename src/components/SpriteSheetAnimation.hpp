///
/// @file SpriteSheetAnimation.hpp
/// @author Andréas Leroux (andreas.leroux@epitech.eu)
/// @brief
/// @version 1.0.0
/// @date 2022-12-23
///
/// @copyright Copyright (c) 2022
///
///

#ifndef SPRITESHEETANIMATION_HPP_
#define SPRITESHEETANIMATION_HPP_

#include <SFML/Graphics.hpp>
#include <vector>

struct SpriteSheetAnimation {
    size_t currentFrame;
    float currentFrameDuration;
    std::vector<sf::IntRect> frames;
    float frameDurationSeconds;

    SpriteSheetAnimation(float frameDuration, std::initializer_list<sf::IntRect> pFrames)
        : currentFrame(-1), currentFrameDuration(0.f), frames(pFrames), frameDurationSeconds(frameDuration)
    {
    }

    SpriteSheetAnimation(float frameDuration, const std::vector<sf::IntRect> &pFrames)
        : currentFrame(-1), currentFrameDuration(0.f), frames(pFrames), frameDurationSeconds(frameDuration)
    {
    }
};

#endif /* !SPRITESHEETANIMATION_HPP_ */
