#include <SFML/Graphics.hpp>
#include <ecstasy/registry/Registry.hpp>
#include <ecstasy/storages/MapStorage.hpp>
#include "components/SpriteSheetAnimation.hpp"
#include "resources/FixedClock.hpp"

#include "UpdateAnimation.hpp"

void UpdateAnimation::run(ecstasy::Registry &registry)
{
    for (auto [rect, animation] : registry.query<sf::RectangleShape, SpriteSheetAnimation>()) {
        animation.currentFrameDuration += registry.getResource<FixedClock>().elapsedSeconds();
        if (animation.currentFrameDuration > animation.frameDurationSeconds
            || animation.currentFrame == static_cast<size_t>(-1)) {
            animation.currentFrameDuration = 0.f;
            ++animation.currentFrame;
            if (animation.currentFrame >= animation.frames.size() || animation.currentFrame == static_cast<size_t>(-1))
                animation.currentFrame = 0;
            rect.setTextureRect(animation.frames[animation.currentFrame]);
        }
    }
}
