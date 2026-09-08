cmake_minimum_required(VERSION 3.10)
project(military_training_game)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Raylib
find_package(raylib REQUIRED)

# Add source files
set(SOURCES
    src/main.cpp
    src/game.cpp
    src/player.cpp
    src/scene.cpp
)

# Create executable
add_executable(military_training_game ${SOURCES})

# Link Raylib
target_link_libraries(military_training_game raylib)

# Include directories
target_include_directories(military_training_game PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)