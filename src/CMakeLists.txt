set(SRCROOT ${PROJECT_SOURCE_DIR}/src)
set(INCROOT ${PROJECT_SOURCE_DIR}/src)

set(SRC
    ${SRCROOT}/Game.cpp
    ${INCROOT}/Game.hpp
    ${SRCROOT}/GameConfig.cpp
    ${INCROOT}/GameConfig.hpp
    ${SRCROOT}/Player.cpp
    ${INCROOT}/Player.hpp)
set(INCDIRS ${INCROOT})

add_subdirectory(resources)
add_subdirectory(systems)

# Source groups are a feature in Visual Studio.
source_group("" FILES ${SRC})

set(TARGET_NAME DuckHunt)
set(LIB_NAME lib${TARGET_NAME})


add_library(${LIB_NAME} ${SRC})
set_compiler_flags(${LIB_NAME})

target_include_directories(${LIB_NAME} PRIVATE ${INCDIRS})
target_include_directories(${LIB_NAME} PUBLIC ${INCROOT})
target_link_libraries(${LIB_NAME} PUBLIC ecstasy)
target_link_libraries_system(${LIB_NAME} PUBLIC sfml-graphics sfml-window sfml-system)

add_executable(${TARGET_NAME} ${SRCROOT}/main.cpp)
set_compiler_flags(${TARGET_NAME})
target_link_libraries(${TARGET_NAME} PRIVATE ${LIB_NAME})

add_custom_command(TARGET ${TARGET_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${TARGET_NAME}> ${PROJECT_SOURCE_DIR}/)
