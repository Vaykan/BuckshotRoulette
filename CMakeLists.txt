cmake_minimum_required(VERSION 3.28)
project(Buckshot_Roulette)

set(CMAKE_CXX_STANDARD 23)

add_executable(Buckshot_Roulette
        src/items/item.cpp
        src/main.cpp
        src/random.cpp
        src/shell.cpp
        src/shotgun.cpp
        src/player.cpp
        src/items/pill.cpp
        include/items/pill.h
)
target_include_directories(Buckshot_Roulette PUBLIC include)

