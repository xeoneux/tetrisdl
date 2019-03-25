cmake_minimum_required(VERSION 3.13)

project(tetrisdl)
set(CMAKE_CXX_STANDARD 11)

if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
  include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
  conan_basic_setup()
else()
  message(WARNING "conanbuildinfo.cmake not found")
endif()

add_executable(${PROJECT_NAME} main.cpp Tetriminos.cpp Tetriminos.h Board.cpp Board.h)
target_link_libraries(${PROJECT_NAME} ${CONAN_LIBS})
