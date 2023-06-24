cmake_minimum_required(VERSION 3.1)

#---------------------#
#--- CPP Settings ---#
#-------------------#

# cpp17 is minimal requirement
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#--- Paths ---#
set(PATH_ROOT "${CMAKE_CURRENT_LIST_DIR}")
set(PATH_TEST "${PATH_ROOT}/test")
set(PATH_LIB_SRC "${PATH_ROOT}/game/src")
set(PATH_LIB_INCLUDE "${PATH_ROOT}/game/include")
set(PATH_EXE_SRC "${PATH_ROOT}/game.exe/src")

#--- CMake Settings ---#
# OUTPUT DIRECTORIES
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

# minimize generated junk projects
set(CMAKE_SUPPRESS_REGENERATION true)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

enable_testing()