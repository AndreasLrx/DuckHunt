#include <SFML/Graphics.hpp>
#include <ecstasy/registry/concepts/RegistryModifier.hpp>
#include <ecstasy/storages/MapStorage.hpp>

#include <ecstasy/registry/concepts/QueryableType.hpp>
#include <ecstasy/registry/modifiers/Maybe.hpp>
#include <ecstasy/registry/modifiers/Or.hpp>
#include <util/BitSet.hpp>
#include "GetRenderWindow.hpp"
#include "components/Position.hpp"

#include "DrawShape.hpp"

namespace esf = ecstasy::integration::sfml;

void DrawShape::run(ecstasy::Registry &registry)
{
    ecstasy::ModifiersAllocator allocator;
    auto &window = getRenderWindow(registry);

    for (auto [circle, rect, maybePos] :
        registry.select<ecstasy::Maybe<sf::CircleShape>, ecstasy::Maybe<sf::RectangleShape>, ecstasy::Maybe<Position>>()
            .where<ecstasy::Or<sf::CircleShape, sf::RectangleShape>>(allocator)) {
        if (circle) {
            if (maybePos)
                circle->get().setPosition(maybePos->get());
            window.get().draw(circle->get());
        }
        if (rect) {
            if (maybePos)
                rect->get().setPosition(maybePos->get());
            window.get().draw(rect->get());
        }
    }
}
