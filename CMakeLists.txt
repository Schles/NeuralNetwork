cmake_minimum_required (VERSION 2.8.11)
project (NeuralNet)

SET(CMAKE_CXX_FLAGS "-std=c++0x")

add_subdirectory (extern/armadillo-7.500.2)

file(GLOB SOURCES "src/Network/*.cpp")

add_executable (neural
    src/main.cpp
    ${SOURCES}
)

include_directories(
    "Network"
)

target_link_libraries (neural armadillo)
