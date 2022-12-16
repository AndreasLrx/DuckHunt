#include <SFML/Graphics.hpp>
#include <ecstasy/storages/MapStorage.hpp>
#include "GetRenderWindow.hpp"

#include "DrawShape.hpp"

namespace esf = ecstasy::integration::sfml;

void DrawShape::run(ecstasy::Registry &registry)
{
    auto &window = getRenderWindow(registry);

    for (auto [circle, color] : registry.query<sf::CircleShape, sf::Color>()) {
        circle.setFillColor(color);
        window.get().draw(circle);
    }
}
