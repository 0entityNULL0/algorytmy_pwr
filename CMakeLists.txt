cmake_minimum_required(VERSION 3.00)
project(project_name CXX)
include_directories(HEADER_FILES)
file(GLOB MAIN
    "main.cpp"
    )
    add_executable(testy ${MAIN})
file(GLOB UNIT
    "unit_testy.cpp"
    )
    add_executable(unit_testy ${UNIT})
file(GLOB TREE
    "test_drzewa.cpp"
    )
    add_executable(testy_drzewa ${TREE})
