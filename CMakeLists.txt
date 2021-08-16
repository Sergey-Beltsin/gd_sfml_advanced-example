cmake_minimum_required(VERSION 3.20)
project(sfml_beginner)

set(CMAKE_CXX_STANDARD 17)

set(SFML_INCLUDE_DIR "./External/SFML/include")
set(SFML_LIBRARY_DIR "./External/SFML/lib")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

find_package(SFML 2.5.1 COMPONENTS system window graphics network audio)

configure_file(Fonts/Roboto-Regular.ttf Fonts/Roboto-Regular.ttf COPYONLY)
add_executable(sfml_beginner main.cpp Game.cpp Game.h Game.cpp Game.h)
target_link_libraries(sfml_beginner sfml-graphics sfml-window sfml-system sfml-audio sfml-network)
