cmake_minimum_required(VERSION 3.20)
project("Game of life" DESCRIPTION "Console game of life" LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

set(GOL_SOURCES GOL.hpp GOL.cpp)
add_library(GameOfLife STATIC ${GOL_SOURCES})

if(CMAKE_BUILD_TYPE STREQUAL Debug)
	add_compile_definitions(__RUN_EXAMPLE__)
endif()

add_executable(Game_of_life main.cpp)
target_link_libraries(Game_of_life PUBLIC GameOfLife)
