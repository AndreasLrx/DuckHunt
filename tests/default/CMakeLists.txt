set(SRCROOT ${SRCROOT}/default)

set(SRC
    ${SRCROOT}/tests_placeholder.cpp
)

add_duckhunt_test(
    NAME duckhunt_test_placeholder
    DISPLAY_NAME "DuckHunt-Placeholder-Tests"
    SOURCES ${SRC}
)
