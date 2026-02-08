cmake_minimum_required(VERSION 3.15)
project(alks-society CXX)

set(CMAKE_CXX_STANDARD 17)

find_package(SFML 3 COMPONENTS Graphics Window System Audio REQUIRED)

add_executable(game 
    src/main.cpp
    src/interface.cpp
    src/player.cpp
    src/screen.cpp
)

target_link_libraries(game SFML::Graphics SFML::Window SFML::System SFML::Audio)
