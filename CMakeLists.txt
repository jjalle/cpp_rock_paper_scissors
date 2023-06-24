cmake_minimum_required(VERSION 3.5)
project(Game)
include("config.cmake")

add_subdirectory(game)
add_subdirectory(game.exe)
add_subdirectory(test)

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT Game.Exe)
