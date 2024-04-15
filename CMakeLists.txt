# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Informática Básica
#
# @author Roberto Perez Medina
# @date 28 Jun 2022
# @brief CMakeLists.txt example
# CMakeLists.txt defines the whole build
# CMake reads CMakeLists.txt sequentially
#
# Build process:
#   1. cd <project_folder>
#   2. mkdir build
#   3. cd build
#   4. cmake ..
#   5. make


cmake_minimum_required(VERSION 3.1)  # Mandatory

# set the project name 
project(p04_code_analyzer                # Mandatory
    VERSION 1.0
    DESCRIPTION "p04_code_analyzer"
    LANGUAGES CXX)


# specify the C++ standard
set(CMAKE_CXX_STANDARD 14) 						# Use c++14
set(CMAKE_CXX_STANDARD_REQUIRED True)

# tell cmake to output binaries here:
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# Debug and release flags
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# tell cmake where to look for *.h files
include_directories(${PROJECT_SOURCE_DIR}/src)

add_executable(p04_code_analyzer
    src/comments.h
    src/comments.cc
    src/main.h
    src/main.cc
    src/statements.h
    src/statements.cc
    src/variables.h
    src/variables.cc
    src/p04_code_analyzer.cc
    src/precompiler.h
    src/precompiler.cc)
