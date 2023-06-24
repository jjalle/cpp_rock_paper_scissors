cmake_minimum_required(VERSION 3.1)
project(Game.Exe)

add_executable(${PROJECT_NAME})

target_sources(${PROJECT_NAME}
    PRIVATE
    ${PATH_EXE_SRC}/main.cpp
)
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "Game")

target_link_libraries(${PROJECT_NAME} PUBLIC
    Game
)

if ( CMAKE_COMPILER_IS_GNUCC )
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)
endif()
if ( MSVC )
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
endif()