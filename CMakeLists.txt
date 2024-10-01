# Set the minimum version of CMake that can be used
# To find the cmake version run
# $ cmake --version

cmake_policy(SET CMP0078 NEW)
cmake_policy(SET CMP0086 NEW)


cmake_minimum_required(VERSION 3.5)

# Set the project name
project(Wells_Fargo_Project_1)

# Find SWIG and include the SWIG module
find_package(SWIG REQUIRED)
include(UseSWIG)

# Set the directories that should be included in the build command for this target
# when running g++ these will be included as -I/directory/path/
include_directories(${PROJECT_SOURCE_DIR}/include)


# Add SWIG interface file
set(WRAPPER_SOURCE src/Matrix.i)

# Create a sources variable with a link to all cpp files to compile
set(SOURCES
    src/Matrix.cpp
    src/main.cpp
)

# Create SWIG wrapper
swig_add_library(Matrix
    LANGUAGE python
    SOURCES ${WRAPPER_SOURCE} ${SOURCES}
)

# Include the necessary directories for SWIG generated code
target_include_directories(Matrix PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

# Add an executable with the above sources
add_executable(hello_headers ${SOURCES})

# Link SWIG library with the main executable
target_link_libraries(hello_headers Matrix ${PYTHON_LIBRARIES})

