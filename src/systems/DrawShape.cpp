#include <SFML/Graphics.hpp>
#include <ecstasy/registry/concepts/RegistryModifier.hpp>
#include <ecstasy/storages/MapStorage.hpp>

#include <ecstasy/registry/concepts/QueryableType.hpp>
#include <ecstasy/registry/modifiers/Maybe.hpp>
#include <ecstasy/registry/modifiers/Or.hpp>
#include <set>
#include <util/BitSet.hpp>
#include "GetRenderWindow.hpp"
#include "components/DrawOrder.hpp"
#include "components/Position.hpp"

#include "DrawShape.hpp"

namespace esf = ecstasy::integration::sfml;

using key_type = std::pair<std::size_t, long int>;

class Comparer {
  public:
    Comparer() = default;

    bool operator()(const key_type &a, const key_type &b) const
    {
        if (a.second == b.second)
            return a.first < b.first;
        else
            return a.second < b.second;
    }
};

void DrawShape::run(ecstasy::Registry &registry)
{
    ecstasy::ModifiersAllocator allocator;
    auto &window = getRenderWindow(registry);
    std::set<key_type, Comparer> drawables;

    auto query = registry
                     .select<ecstasy::Maybe<sf::CircleShape>, ecstasy::Maybe<sf::RectangleShape>,
                         ecstasy::Maybe<Position>, DrawOrder>()
                     .where<ecstasy::Or<sf::CircleShape, sf::RectangleShape>>(allocator);

    for (auto it = query.begin(); it != query.end(); ++it) {
        [[maybe_unused]] auto [circle, rect, maybePos, order] = *it;
        drawables.emplace(std::make_pair(it.getPosition(), order.order));
    }

    for (auto drawable : drawables) {
        auto [circle, rect, maybePos, order] = query.getQueryData(drawable.first);
        (void)order;

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
