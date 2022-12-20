#include <ecstasy/registry/Registry.hpp>
#include <ecstasy/storages/MapStorage.hpp>
#include "components/Position.hpp"
#include "components/Velocity.hpp"
#include "resources/FixedClock.hpp"

#include "Movement.hpp"

void Movement::run(ecstasy::Registry &registry)
{
    for (auto [position, velocity] : registry.query<Position, Velocity>())
        position += velocity * registry.getResource<FixedClock>().elapsedSeconds();
}
