cmake_minimum_required(VERSION 3.19.0)

# Add ./cmake to the module path
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake ${CMAKE_CURRENT_SOURCE_DIR}/cmake/macros)

# Avoid warning about DOWNLOAD_EXTRACT_TIMESTAMP
if(POLICY CMP0135)
	cmake_policy(SET CMP0135 NEW)
	set(CMAKE_POLICY_DEFAULT_CMP0135 NEW)
endif()

include(Options)
include(macros)

find_package(ECSTASY REQUIRED)

project(DuckHunt LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include(DetectCompiler)

set(BUILDING_TESTS 0)
add_subdirectory(src)

# Unit testing
if(BUILD_TEST_SUITE)
    # Check for GoogleTest
    find_package(googletest REQUIRED)

    # Disable error on Linux release builds
    if(COMPILER_TYPE MATCHES "gcc")
        target_compile_options(gtest PRIVATE "-Wno-error=restrict")
        target_compile_options(gmock PRIVATE "-Wno-error=restrict")
    endif()

    enable_testing()

    set(BUILDING_TESTS 1)
    add_subdirectory(tests)
endif()