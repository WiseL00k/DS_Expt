cmake_minimum_required(VERSION 3.10)

project(DS_EXPT)

set(CMAKE_CXX_STANDARD 11)

include_directories(inc)

aux_source_directory(src SRC)

# Add executable
add_executable(DS_EXPT ${SRC})
