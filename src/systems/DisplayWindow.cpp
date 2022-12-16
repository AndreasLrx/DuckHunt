#include "DisplayWindow.hpp"
#include "GetRenderWindow.hpp"

void DisplayWindow::run(ecstasy::Registry &registry)
{
    getRenderWindow(registry).get().display();
}