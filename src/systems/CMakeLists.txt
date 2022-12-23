set(SRCROOT ${SRCROOT}/systems)
set(INCROOT ${INCROOT}/systems)

set(SRC
    ${SRC}
    ${SRCROOT}/ClearWindow.cpp
    ${INCROOT}/ClearWindow.hpp
    ${SRCROOT}/DisplayWindow.cpp
    ${INCROOT}/DisplayWindow.hpp
    ${SRCROOT}/DrawShape.cpp
    ${INCROOT}/DrawShape.hpp
    ${SRCROOT}/GetRenderWindow.cpp
    ${INCROOT}/GetRenderWindow.hpp
    ${SRCROOT}/Movement.cpp
    ${INCROOT}/Movement.hpp
    ${SRCROOT}/UpdateAnimation.cpp
    ${INCROOT}/UpdateAnimation.hpp
    PARENT_SCOPE)
