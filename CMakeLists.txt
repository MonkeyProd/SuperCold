cmake_minimum_required(VERSION 3.0.0)
project(sfml_game VERSION 0.1.0)

include(CTest)
include(FindPkgConfig)
enable_testing()

include_directories(src/Assets)

file(GLOB game_src "src/**/*.cpp" "src/Game/Utils/debug.cpp" "src/main.cpp" "src/settings.toml" "src/external/SimplexNoise/*.cpp")

add_executable(sfml_game ${game_src})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")

pkg_check_modules(SFML REQUIRED sfml-window sfml-system sfml-graphics sfml-audio)

target_link_libraries(sfml_game PUBLIC ${SFML_LINK_LIBRARIES})
target_include_directories(sfml_game PUBLIC ${SFML_INCLUDE_DIRS})
target_include_directories(sfml_game PUBLIC /usr/local/include)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
