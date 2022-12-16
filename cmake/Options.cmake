cmake_minimum_required(VERSION 3.17)

include(CMakeDependentOption)

option(BUILD_TEST_SUITE "Whether the test suite must be built." OFF)
option(ENABLE_TEST_COVERAGE "Whether the tests code coverage must be enabled" OFF)


## Display configuration
message(STATUS "Options:")
list(APPEND CMAKE_MESSAGE_INDENT "  ")
    message(STATUS "Build Tests: ${BUILD_TEST_SUITE}")
    message(STATUS "Enable test coverage: ${ENABLE_TEST_COVERAGE}")
list(POP_BACK CMAKE_MESSAGE_INDENT)
