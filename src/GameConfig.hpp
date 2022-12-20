///
/// @file GameConfig.hpp
/// @author Andréas Leroux (andreas.leroux@epitech.eu)
/// @brief
/// @version 1.0.0
/// @date 2022-12-19
///
/// @copyright Copyright (c) 2022
///
///

#ifndef GAMECONFIG_HPP_
#define GAMECONFIG_HPP_

#include <SFML/Graphics.hpp>
#include <ecstasy/registry/Registry.hpp>
#include "Game.hpp"

class GameConfig {
  public:
    GameConfig(unsigned int size = 256);
    ~GameConfig() = default;

    void initialize();
    void run();

    void processInputs();
    void update();
    void render();

    constexpr ecstasy::Registry &getRegistry()
    {
        return _registry;
    }

    sf::Vector2i getSize();

  private:
    void addBackground(sf::IntRect rect, long int drawOrder = -1000, sf::Vector2f position = sf::Vector2f(0.f, 0.f),
        const std::string &texture = "background");

    ecstasy::Registry _registry;
    sf::Vector2i _size;

    static constexpr size_t _game_loop_system_mask = 0xff00000000000000;
    static constexpr size_t _game_loop_inputs = 0x0100000000000000;
    static constexpr size_t _game_loop_update = 0x0200000000000000;
    static constexpr size_t _game_loop_render = 0x0300000000000000;
};

#endif /* !GAMECONFIG_HPP_ */
