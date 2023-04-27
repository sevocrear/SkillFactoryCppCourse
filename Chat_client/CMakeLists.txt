cmake_minimum_required(VERSION 3.10)

# Set the project name
project(project)

# Add all *.cpp files under the src directory to a variable named SOURCES
file(GLOB SOURCES "*.cpp" "include/*.cpp")

# Add the include directory to the include paths
include_directories(include)

# Add the executable target
add_executable(client ${SOURCES})

# TODO: Add Client which reads messages_info and sends it to the net (if updated)
# TODO: Add Server which receives messages from net and writes it to the messages_info