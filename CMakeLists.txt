cmake_minimum_required(VERSION 3.21)

project(minesweeper)

file(GLOB minesweeper_sources "src/*/*.cpp")

add_executable(minesweeper src/main.cpp ${minesweeper_sources})
target_include_directories(minesweeper PUBLIC "src/")

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.4.0 # or a later release
)

FetchContent_MakeAvailable(Catch2)

add_executable(grid_test test/minesweeper/grid_test.cpp ${minesweeper_sources})
target_link_libraries(grid_test PRIVATE Catch2::Catch2WithMain)
target_include_directories(grid_test PUBLIC "src/")

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)
catch_discover_tests(grid_test)