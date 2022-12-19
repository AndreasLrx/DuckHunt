#include <chrono>

#include <ecstasy/integrations/event/include.hpp>
#include <ecstasy/integrations/sfml/resources/RenderWindow.hpp>
#include <ecstasy/integrations/sfml/systems/PollEvents.hpp>
#include <ecstasy/registry/Registry.hpp>
#include <ecstasy/resources/entity/RegistryEntity.hpp>
#include <ecstasy/storages/MapStorage.hpp>
#include "systems/ClearWindow.hpp"
#include "systems/DisplayWindow.hpp"
#include "systems/DrawShape.hpp"
#include "systems/GetRenderWindow.hpp"

#include "GameConfig.hpp"

namespace esf = ecstasy::integration::sfml;
namespace event = ecstasy::integration::event;

GameConfig::GameConfig()
{
    initialize();
}

void GameConfig::initialize()
{
    _registry.addResource<esf::RenderWindow>(sf::VideoMode(1280, 720), "Duck Hunt");

    _registry.entityBuilder()
        .with<sf::CircleShape>(10.f)
        .with<sf::Color>(sf::Color::Red)
        .with<event::MouseMoveListener>([](ecstasy::Registry &r, ecstasy::Entity entity,
                                            const event::MouseMoveEvent &e) {
            entity.get(r.getStorage<sf::CircleShape>()).setPosition(static_cast<float>(e.x), static_cast<float>(e.y));
        })
        .build();

    _registry.addSystem<esf::PollEvents, _game_loop_inputs>();
    _registry.addSystem<ClearWindow, _game_loop_render>(sf::Color::White);
    _registry.addSystem<DrawShape, _game_loop_render + 1000>();
    _registry.addSystem<DisplayWindow, _game_loop_render + 1000000>();
}

void GameConfig::run()
{
    std::chrono::system_clock::time_point previous = std::chrono::system_clock::now();
    std::chrono::milliseconds lag(0);
    const std::chrono::milliseconds msPerUpdate(1000 / 60);

    while (getRenderWindow(_registry).get().isOpen()) {
        std::chrono::system_clock::time_point current = std::chrono::system_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(current - previous);
        previous = current;
        lag += elapsed;

        processInputs();

        while (lag >= msPerUpdate) {
            update();
            lag -= msPerUpdate;
        }

        render();
    }
}

void GameConfig::processInputs()
{
    _registry.runSystems(_game_loop_inputs, _game_loop_system_mask);
}

void GameConfig::update()
{
    _registry.runSystems(_game_loop_update, _game_loop_system_mask);
}

void GameConfig::render()
{
    _registry.runSystems(_game_loop_render, _game_loop_system_mask);
}
