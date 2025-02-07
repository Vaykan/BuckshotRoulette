cmake_minimum_required(VERSION 3.28)
project(Buckshot_Roulette)

set(CMAKE_CXX_STANDARD 23)

set(wxWidgets_ROOT_DIR "D:/wxWidgets-3.2.6")
set(wxWidgets_LIB_DIR "D:/wxWidgets-3.2.6/lib/gcc_lib")

find_package(wxWidgets REQUIRED COMPONENTS net core base)
if(wxWidgets_USE_FILE) # not defined in CONFIG mode
    include(${wxWidgets_USE_FILE})
endif()

add_executable(Buckshot_Roulette WIN32
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
        src/myFrame.cpp
        src/myFrame.h
)

target_link_libraries(Buckshot_Roulette ${wxWidgets_LIBRARIES})

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -static")