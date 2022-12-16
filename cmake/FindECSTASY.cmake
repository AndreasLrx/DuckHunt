cmake_minimum_required(VERSION 3.14)
    
include(FetchContent)

if(NOT ecstasy_FOUND)
    FetchContent_Declare(
        ecstasy
        GIT_REPOSITORY https://github.com/AndreasLrx/ecstasy.git
        GIT_TAG        main)

    FetchContent_GetProperties(ecstasy)

    if(NOT ecstasy_POPULATED)
        SET(FETCHCONTENT_QUIET NO)
        SET(ECSTASY_INTEGRATIONS_EVENT ON)
        SET(ECSTASY_INTEGRATIONS_SFML ON)
        SET(ECSTASY_INTEGRATIONS_USER_ACTION ON)
        set(BUILD_TEST_SUITE OFF)
        FetchContent_Populate(ecstasy)
        ADD_SUBDIRECTORY(${ecstasy_SOURCE_DIR} ${ecstasy_BINARY_DIR})
        SET(ecstasy_FOUND TRUE)
    endif()
endif()
