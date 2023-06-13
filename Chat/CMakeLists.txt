cmake_minimum_required(VERSION 3.10)

# Set the project name
project(project)

include(FetchContent)
find_package(PostgreSQL REQUIRED)

FetchContent_Declare(
   taocpp-taopq
   GIT_REPOSITORY https://github.com/taocpp/taopq
   GIT_TAG main
)
FetchContent_MakeAvailable(taocpp-taopq)

# Add all *.cpp files under the src directory to a variable named SOURCES
file(GLOB SOURCES "*.cpp" "include/*.cpp")

# Add the include directory to the include paths
include_directories(include)

# Add the executable target
add_executable(chat ${SOURCES})

target_link_libraries(chat taocpp::taopq)
set_target_properties(chat PROPERTIES CXX_STANDARD 17)