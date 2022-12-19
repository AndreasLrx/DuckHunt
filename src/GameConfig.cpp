#include <chrono>

#include <ecstasy/integrations/event/include.hpp>
#include <ecstasy/integrations/sfml/resources/RenderWindow.hpp>
#include <ecstasy/integrations/sfml/systems/PollEvents.hpp>
#include <ecstasy/registry/Registry.hpp>
#include <ecstasy/resources/entity/RegistryEntity.hpp>
#include <ecstasy/storages/MapStorage.hpp>
#include "components/Position.hpp"
#include "components/Size.hpp"
#include "systems/ClearWindow.hpp"
#include "systems/DisplayWindow.hpp"
#include "systems/DrawShape.hpp"
#include "systems/GetRenderWindow.hpp"

#include "GameConfig.hpp"

namespace esf = ecstasy::integration::sfml;
namespace event = ecstasy::integration::event;

GameConfig::GameConfig(unsigned int size) : _size(size, size)
{
    initialize();
}

void GameConfig::initialize()
{
    _textures.emplace(std::make_pair("background", sf::Texture())).first->second.loadFromFile("assets/backgrounds.png");
    _textures.emplace(std::make_pair("target", sf::Texture())).first->second.loadFromFile("assets/target.png");
    _registry.addResource<esf::RenderWindow>(sf::VideoMode(_size.x, _size.y), "Duck Hunt")
        .get()
        .setMouseCursorVisible(false);

    /// Background
    float scaleY = (static_cast<float>(_size.y) / 256.f);
    float scaleX = (static_cast<float>(_size.x) / 256.f);

    auto &back = _registry.entityBuilder()
                     .with<sf::RectangleShape>(sf::Vector2f(static_cast<float>(_size.x), static_cast<float>(_size.y)))
                     .build()
                     .get(_registry.getStorage<sf::RectangleShape>());
    back.setTextureRect(sf::IntRect(67, 297, 256, 256));
    back.setTexture(&_textures.at("background"));

    auto &backBlurTop = _registry.entityBuilder()
                            .with<sf::RectangleShape>(sf::Vector2f(static_cast<float>(_size.x), 188 * scaleY))
                            .build()
                            .get(_registry.getStorage<sf::RectangleShape>());
    backBlurTop.setTextureRect(sf::IntRect(67, 687, 256, 188));
    backBlurTop.setTexture(&_textures.at("background"));

    auto &backBlurBottom = _registry.entityBuilder()
                               .with<sf::RectangleShape>(sf::Vector2f(static_cast<float>(_size.x), 36 * scaleY))
                               .build()
                               .get(_registry.getStorage<sf::RectangleShape>());
    backBlurBottom.setTextureRect(sf::IntRect(67, 877, 256, 36));
    backBlurBottom.setTexture(&_textures.at("background"));
    backBlurBottom.setPosition(0, static_cast<float>(_size.y) - 36 * scaleY);

    auto &backBush = _registry.entityBuilder()
                         .with<sf::RectangleShape>(sf::Vector2f(32 * scaleX, 64 * scaleY))
                         .build()
                         .get(_registry.getStorage<sf::RectangleShape>());
    backBush.setTextureRect(sf::IntRect(61, 595, 32, 64));
    backBush.setTexture(&_textures.at("background"));
    backBush.setPosition(194 * scaleX, 135 * scaleY);

    auto &backTree = _registry.entityBuilder()
                         .with<sf::RectangleShape>(sf::Vector2f(56 * scaleX, 130 * scaleY))
                         .build()
                         .get(_registry.getStorage<sf::RectangleShape>());
    backTree.setTextureRect(sf::IntRect(3, 555, 56, 130));
    backTree.setTexture(&_textures.at("background"));
    backTree.setPosition(10 * scaleX, 69 * scaleY);

    auto &backTreeBush1 = _registry.entityBuilder()
                              .with<sf::RectangleShape>(sf::Vector2f(32 * scaleX, 24 * scaleY))
                              .build()
                              .get(_registry.getStorage<sf::RectangleShape>());
    backTreeBush1.setTextureRect(sf::IntRect(137, 595, 32, 24));
    backTreeBush1.setTexture(&_textures.at("background"));
    backTreeBush1.setPosition(13 * scaleX, 47 * scaleY);

    auto &backTreeBush2 = _registry.entityBuilder()
                              .with<sf::RectangleShape>(sf::Vector2f(32 * scaleX, 24 * scaleY))
                              .build()
                              .get(_registry.getStorage<sf::RectangleShape>());
    backTreeBush2.setTextureRect(sf::IntRect(231, 595, 32, 24));
    backTreeBush2.setTexture(&_textures.at("background"));
    backTreeBush2.setPosition(36 * scaleX, 70 * scaleY);

    auto &backTreeBush3 = _registry.entityBuilder()
                              .with<sf::RectangleShape>(sf::Vector2f(24 * scaleX, 16 * scaleY))
                              .build()
                              .get(_registry.getStorage<sf::RectangleShape>());
    backTreeBush3.setTextureRect(sf::IntRect(265, 595, 24, 16));
    backTreeBush3.setTexture(&_textures.at("background"));
    backTreeBush3.setPosition(29 * scaleX, 90 * scaleY);

    auto &backTreeBush4 = _registry.entityBuilder()
                              .with<sf::RectangleShape>(sf::Vector2f(24 * scaleX, 24 * scaleY))
                              .build()
                              .get(_registry.getStorage<sf::RectangleShape>());
    backTreeBush4.setTextureRect(sf::IntRect(205, 595, 24, 24));
    backTreeBush4.setTexture(&_textures.at("background"));
    backTreeBush4.setPosition(7 * scaleX, 93 * scaleY);

    auto &backTreeBush5 = _registry.entityBuilder()
                              .with<sf::RectangleShape>(sf::Vector2f(32 * scaleX, 24 * scaleY))
                              .build()
                              .get(_registry.getStorage<sf::RectangleShape>());
    backTreeBush5.setTextureRect(sf::IntRect(137, 595, 32, 24));
    backTreeBush5.setTexture(&_textures.at("background"));
    backTreeBush5.setPosition(46 * scaleX, 103 * scaleY);

    auto &backGrass = _registry.entityBuilder()
                          .with<sf::RectangleShape>(sf::Vector2f(static_cast<float>(_size.x), 38 * scaleY))
                          .build()
                          .get(_registry.getStorage<sf::RectangleShape>());
    backGrass.setTextureRect(sf::IntRect(61, 555, 256, 38));
    backGrass.setTexture(&_textures.at("background"));
    backGrass.setPosition(0, static_cast<float>(_size.y) - 93 * scaleY);

    /// Target
    auto &targetRect = _registry.entityBuilder()
                           .with<sf::RectangleShape>(sf::Vector2f(30.f, 30.f))
                           .with<event::MouseMoveListener>(
                               [](ecstasy::Registry &r, ecstasy::Entity entity, const event::MouseMoveEvent &e) {
                                   entity.get(r.getStorage<sf::RectangleShape>())
                                       .setPosition(static_cast<float>(e.x), static_cast<float>(e.y));
                               })
                           .build()
                           .get(_registry.getStorage<sf::RectangleShape>());
    targetRect.setOrigin(sf::Vector2f(15.f, 15.f));
    targetRect.setTexture(&_textures.at("target"));

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
