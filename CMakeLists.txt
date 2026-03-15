cmake_minimum_required(VERSION 3.00)
project(project_name CXX)
include_directories(HEADER_FILES)
file(GLOB MAIN
    "main.cpp"
    )
    add_executable(executable ${MAIN})
