cmake_minimum_required(VERSION 3.28)
project(Buckshot_Roulette)

set(CMAKE_CXX_STANDARD 23)

add_executable(Buckshot_Roulette
        src/items/item.cpp
        src/main.cpp
        src/random.cpp
        src/shotgun.cpp
        src/player.cpp
        src/items/pill.cpp
        src/items/pill.h
        src/items/cigarette.cpp
        src/items/cigarette.h
        src/session.cpp
        src/session.h
        src/input.cpp
        src/input.h
)

