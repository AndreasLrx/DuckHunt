#include <SFML/Graphics.hpp>
#include <iostream>

#include <ecstasy/integrations/event/include.hpp>
#include <ecstasy/integrations/sfml/resources/RenderWindow.hpp>
#include <ecstasy/integrations/sfml/systems/PollEvents.hpp>
#include <ecstasy/registry/Registry.hpp>
#include <ecstasy/resources/entity/RegistryEntity.hpp>
#include <ecstasy/storages/MapStorage.hpp>
#include <systems/DrawShape.hpp>

namespace esf = ecstasy::integration::sfml;
namespace event = ecstasy::integration::event;

int main()
{
    ecstasy::Registry registry;
    esf::RenderWindow &window = registry.addResource<esf::RenderWindow>(sf::VideoMode(1280, 720), "Duck Hunt");

    registry.entityBuilder()
        .with<sf::CircleShape>(10.f)
        .with<sf::Color>(sf::Color::Red)
        .with<event::MouseMoveListener>([](ecstasy::Registry &r, ecstasy::Entity entity,
                                            const event::MouseMoveEvent &e) {
            entity.get(r.getStorage<sf::CircleShape>()).setPosition(static_cast<float>(e.x), static_cast<float>(e.y));
        })
        .build();

    registry.addSystem<esf::PollEvents>();
    registry.addSystem<DrawShape>();

    while (window.get().isOpen()) {
        window.get().clear(sf::Color::White);
        registry.runSystems();
        window.get().display();
    }
    return 0;
}