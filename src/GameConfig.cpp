#include <chrono>

#include <ecstasy/integrations/event/include.hpp>
#include <ecstasy/integrations/sfml/resources/RenderWindow.hpp>
#include <ecstasy/integrations/sfml/systems/PollEvents.hpp>
#include <ecstasy/registry/Registry.hpp>
#include <ecstasy/resources/entity/RegistryEntity.hpp>
#include <ecstasy/storages/MapStorage.hpp>
#include "RandomDevice.hpp"
#include "components/Position.hpp"
#include "components/Size.hpp"
#include "resources/FixedClock.hpp"
#include "systems/ClearWindow.hpp"
#include "systems/DisplayWindow.hpp"
#include "systems/DrawShape.hpp"
#include "systems/GetRenderWindow.hpp"
#include "systems/Movement.hpp"

#include "GameConfig.hpp"

namespace esf = ecstasy::integration::sfml;
namespace event = ecstasy::integration::event;

GameConfig::GameConfig(unsigned int size) : _size(static_cast<int>(size), static_cast<int>(size))
{
    initialize();
}

void GameConfig::addBackground(sf::IntRect bounds, sf::Vector2f position, const std::string &texture)
{
    float scaleY = (static_cast<float>(_size.y) / 256.f);
    float scaleX = (static_cast<float>(_size.x) / 256.f);

    auto &rect = _registry.entityBuilder()
                     .with<sf::RectangleShape>(sf::Vector2f(
                         static_cast<float>(bounds.width) * scaleX, static_cast<float>(bounds.height) * scaleY))
                     .build()
                     .get(_registry.getStorage<sf::RectangleShape>());
    rect.setTextureRect(bounds);
    rect.setTexture(&_textures.at(texture));
    rect.setPosition(position.x * scaleX, position.y * scaleY);
}

void GameConfig::initialize()
{
    _textures.emplace(std::make_pair("background", sf::Texture())).first->second.loadFromFile("assets/backgrounds.png");
    _textures.emplace(std::make_pair("sprites", sf::Texture())).first->second.loadFromFile("assets/sprites.png");
    _textures.emplace(std::make_pair("target", sf::Texture())).first->second.loadFromFile("assets/target.png");
    _registry
        .addResource<esf::RenderWindow>(
            sf::VideoMode(static_cast<int>(_size.x), static_cast<int>(_size.y)), "Duck Hunt")
        .get()
        .setMouseCursorVisible(false);
    _registry.addResource<RandomDevice>();

    // Back
    addBackground(sf::IntRect(67, 297, 256, 256));
    // Back blur top - bottom
    addBackground(sf::IntRect(67, 687, 256, 188));
    addBackground(sf::IntRect(67, 877, 256, 36), sf::Vector2f(0.f, 220.f));

    /// Bush
    addBackground(sf::IntRect(61, 595, 32, 64), sf::Vector2f(194.f, 135.f));

    /// Tree + 5 bushes (top to bottom)
    addBackground(sf::IntRect(3, 555, 56, 130), sf::Vector2f(10.f, 69.f));
    addBackground(sf::IntRect(137, 595, 32, 24), sf::Vector2f(13.f, 47.f));
    addBackground(sf::IntRect(231, 595, 32, 24), sf::Vector2f(36.f, 70.f));
    addBackground(sf::IntRect(265, 595, 24, 16), sf::Vector2f(29.f, 90.f));
    addBackground(sf::IntRect(205, 595, 24, 24), sf::Vector2f(7.f, 93.f));
    addBackground(sf::IntRect(137, 595, 32, 24), sf::Vector2f(46.f, 103.f));

    /// Grass
    addBackground(sf::IntRect(61, 555, 256, 38), sf::Vector2f(0.f, 163.f));

    /// Round, shots, level, score
    addBackground(sf::IntRect(325, 409, 24, 8), sf::Vector2f(24.f, 208.f), "sprites");
    addBackground(sf::IntRect(445, 428, 29, 21), sf::Vector2f(21.f, 221.f), "sprites");
    addBackground(sf::IntRect(325, 428, 117, 21), sf::Vector2f(61.f, 221.f), "sprites");
    addBackground(sf::IntRect(421, 406, 53, 21), sf::Vector2f(189.f, 221.f), "sprites");

    /// Shots
    addBackground(sf::IntRect(64, 386, 4, 7), sf::Vector2f(25.f, 224.f), "sprites");
    addBackground(sf::IntRect(64, 386, 4, 7), sf::Vector2f(33.5f, 224.f), "sprites");
    addBackground(sf::IntRect(64, 386, 4, 7), sf::Vector2f(42.f, 224.f), "sprites");
    addBackground(sf::IntRect(133, 450, 21, 6), sf::Vector2f(25.f, 233.f), "sprites");

    /// Ducks
    for (int i = 0; i < 10; i++)
        addBackground(sf::IntRect(340, 386, 7, 7), sf::Vector2f(96.f + static_cast<float>(i) * 8.f, 224.f), "sprites");

    // Score
    for (int i = 0; i < 6; i++)
        addBackground(sf::IntRect(357, 385, 7, 7), sf::Vector2f(192.f + static_cast<float>(i) * 8.f, 224.f), "sprites");

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
    _registry.addSystem<Movement, _game_loop_update>();

    _game.newRound(*this);
}

void GameConfig::run()
{
    std::chrono::system_clock::time_point previous = std::chrono::system_clock::now();
    std::chrono::microseconds lag(0);
    const std::chrono::milliseconds msPerUpdate(1000 / 60);
    auto &clock = _registry.addResource<FixedClock>();

    while (getRenderWindow(_registry).get().isOpen()) {
        std::chrono::system_clock::time_point current = std::chrono::system_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::microseconds>(current - previous);
        previous = current;
        lag += elapsed;

        processInputs();

        /// @brief Make less update with higher delay to try to reduce missed update frames
        auto updateTime = (lag > 10 * msPerUpdate) ? 3 * msPerUpdate : msPerUpdate;
        while (lag >= updateTime) {
            clock.newFrame(updateTime);
            update();
            lag -= updateTime;
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

sf::Vector2i GameConfig::getSize()
{
    return _size;
}

sf::Texture &GameConfig::getTexture(std::string name)
{
    return _textures.at(name);
}
