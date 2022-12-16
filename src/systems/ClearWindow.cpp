#include "ClearWindow.hpp"
#include "GetRenderWindow.hpp"

void ClearWindow::run(ecstasy::Registry &registry)
{
    getRenderWindow(registry).get().clear(_color);
}