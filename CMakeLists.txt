cmake_minimum_required(VERSION 3.10)

project(DS_EXPT)

set(CMAKE_CXX_STANDARD 11)

include_directories(inc)

aux_source_directory(${PROJECT_SOURCE_DIR}/src SRC)

set(EXECUTABLE_OUTPUT_PATH ./)

# Add executable
add_executable(main ${SRC})
