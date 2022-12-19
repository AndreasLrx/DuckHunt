#include <iostream>

#include "GameConfig.hpp"

int main()
{
    GameConfig config;

    try {
        config.run();
    } catch (std::exception &e) {
        std::cerr << "Exception occured: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}