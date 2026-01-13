cmake_minimum_required(VERSION 3.28)
project(button LANGUAGES CXX)

set(CMAKE_POLICY_DEFAULT_CMP0077 NEW)

# Set the C++ Version
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Disable Shared Libs
set(BUILD_SHARED_LIBS OFF)
set(SDL_SHARED OFF)
set(SDL_STATIC ON)

include(FetchContent)

FetchContent_Declare(
        SDL3
        GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
        GIT_TAG release-3.4.0
        OVERRIDE_FIND_PACKAGE
)

FetchContent_MakeAvailable(SDL3)

add_executable(${PROJECT_NAME} main.cpp    "Button.h" "Button.cpp")
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL3::SDL3-static)