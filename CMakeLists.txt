cmake_minimum_required(VERSION 3.28)
project(Buckshot_Roulette)

set(CMAKE_CXX_STANDARD 23)

set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS "-g")
set(CMAKE_CXX_FLAGS "-O3")

set(CMAKE_CXX_FLAGS "-static")

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
        src/items/beer.cpp
        src/items/beer.h
        src/items/adrenaline.cpp
        src/items/adrenaline.h
        src/items/magnifier.cpp
        src/items/magnifier.h
        src/items/handcuffs.cpp
        src/items/handcuffs.h
        src/items/inverter.cpp
        src/items/inverter.h
        src/items/saw.cpp
        src/items/saw.h
        src/items/phone.cpp
        src/items/phone.h
)

