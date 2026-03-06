cmake_minimum_required(VERSION 3.26)
project(MyGame)

set(CMAKE_CXX_STANDARD 17)

set(SFML_DIR "C:/Users/lebed/work/cpp/MyGame/SFML-2.6.1/lib/cmake/SFML")
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/assets)

find_package(SFML 2.6 COMPONENTS graphics window system REQUIRED)

add_executable(MyGame
        src/main.cpp
        src/Entities/Game.h
        src/Entities/Game.cpp
        src/Entities/Player.cpp
        src/Entities/Enemy.cpp
        src/Entities/Player.h
        src/Entities/Enemy.h
        src/Entities/Entity.cpp
        src/Entities/Enemy.h
        src/entities/Bullet.cpp
        src/entities/Bullet.h
)

target_link_libraries(MyGame sfml-graphics sfml-window sfml-system)