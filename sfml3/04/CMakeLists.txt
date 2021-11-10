add_executable(04 main.cpp)

include_directories("${CMAKE_CURRENT_LIST_DIR}/../../../SFML/include")

set(SFML_STATIC_LIBRARIES TRUE)

find_package(Freetype)
find_package(JPEG)
find_package(SFML 2 COMPONENTS window graphics system)

target_compile_features(04 PUBLIC cxx_std_17)
target_compile_definitions(04 PRIVATE SFML_STATIC)

target_link_libraries(04 sfml-graphics)