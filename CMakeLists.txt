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
file(GLOB ZAD5
    "sortowanie_zapis.cpp"
    )
    add_executable(sortowanie_zapis ${ZAD5})
file(GLOB T1
    "testy_czasowe_filmow.cpp"
    )
    add_executable(testy_czasowe_filmow ${T1})
file(GLOB T2
    "testy_czasowe_int.cpp"
    )
    add_executable(testy_czasowe_int ${T2})
file(GLOB T3
    "testy_kubek.cpp"
    )
    add_executable(testy_kubek ${T3})
