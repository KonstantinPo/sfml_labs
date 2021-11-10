cmake_minimum_required(VERSION 3.8 FATAL_ERROR)

project(sfml-lab-2.1)

include_directories("${CMAKE_CURRENT_LIST_DIR}/../../SFML/include")

add_executable(main main.cpp)

set(SFML_STATIC_LIBRARIES TRUE)

find_package(Freetype)
find_package(JPEG)
find_package(SFML 2 COMPONENTS window graphics system)

target_compile_features(main PUBLIC cxx_std_17)
target_compile_definitions(main PRIVATE SFML_STATIC)

target_link_libraries(main sfml-graphics)