cmake_minimum_required(VERSION 3.10)

# Set the project name
project(project)

set(CMAKE_CXX_STANDARD 17)

# Add all *.cpp files under the src directory to a variable named SOURCES
file(GLOB SOURCES "*.cpp" "include/*.cpp")

# Add the include directory to the include paths
include_directories(include)

# Add the executable target
add_executable(main ${SOURCES})

target_link_libraries(main -pthread)
set_target_properties(main PROPERTIES CXX_STANDARD 17)