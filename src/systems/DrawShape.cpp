#include <SFML/Graphics.hpp>
#include <ecstasy/integrations/sfml/resources/RenderWindow.hpp>
#include <ecstasy/registry/Registry.hpp>
#include <ecstasy/storages/MapStorage.hpp>

#include "DrawShape.hpp"

namespace esf = ecstasy::integration::sfml;

void DrawShape::run(ecstasy::Registry &registry)
{
    auto &window = registry.getResource<esf::RenderWindow>();

    for (auto [circle, color] : registry.query<sf::CircleShape, sf::Color>()) {
        circle.setFillColor(color);
        window.get().draw(circle);
    }
}
