#include <iostream>

#include "GameConfig.hpp"

int main()
{
    GameConfig config(512);

    try {
        config.run();
    } catch (std::exception &e) {
        std::cerr << "Exception occured: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}