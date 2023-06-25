cmake_minimum_required(VERSION 3.1)
project(Game)

add_library(${PROJECT_NAME} STATIC)

target_sources(${PROJECT_NAME}
    PRIVATE
    ${PATH_LIB_INCLUDE}/Config.h
    ${PATH_LIB_INCLUDE}/Game.h
    ${PATH_LIB_INCLUDE}/Hand.h
    ${PATH_LIB_INCLUDE}/Input.h
    ${PATH_LIB_INCLUDE}/Turn.h
    ${PATH_LIB_SRC}/Game.cpp
    ${PATH_LIB_SRC}/Input.cpp
    ${PATH_LIB_SRC}/Turn.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
    ${PATH_LIB_INCLUDE}
    ${SDL2_INCLUDE_DIRS}
)

if ( CMAKE_COMPILER_IS_GNUCC )
    target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra)
    if (CMAKE_BUILD_TYPE MATCHES Debug)
        find_program( GCOV_PATH gcov )
        target_compile_options(${PROJECT_NAME} PRIVATE -g --coverage -fprofile-abs-path)
        target_link_libraries(${PROJECT_NAME} PRIVATE gcov)
    endif()
endif()
if ( MSVC )
    target_compile_options(${PROJECT_NAME} PRIVATE /W4)
endif()