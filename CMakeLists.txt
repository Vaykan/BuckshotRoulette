cmake_minimum_required(VERSION 3.28)
project(Buckshot_Roulette)

set(CMAKE_CXX_STANDARD 23)

find_package(wxWidgets REQUIRED gl core base OPTIONAL_COMPONENTS net)
include(${wxWidgets_USE_FILE})

file(GLOB_RECURSE SRC CONFIGURE_DEPENDS
        src/*)

add_executable(Buckshot_Roulette WIN32
        ${SRC}
)
target_link_libraries(Buckshot_Roulette ${wxWidgets_LIBRARIES})
target_precompile_headers(Buckshot_Roulette PRIVATE src/pch.h)

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -static")
set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CMAKE_COMMAND} -E time")