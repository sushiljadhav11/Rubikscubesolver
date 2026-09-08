cmake_minimum_required(VERSION 3.20)

project(rubiks_cube_mine)

set(CMAKE_CXX_STANDARD 17)

add_executable(rubiks_cube_mine
        main.cpp
        models/rubikscube.cpp
        models/rubikscube3darray.cpp
        solver/bfssolver.h
        solver/bfssolver.cpp
        solver/iddfssolver.h
        solver/iddfssolver.cpp
        patterndatabse/cornerdbmaker.h
        patterndatabse/cornerdbmaker.cpp
        patterndatabse/cornerpatterndatabase.h
        patterndatabse/cornerpatterndatabase.cpp
        solver/idastarsolver.h
        solver/idastarsolver.cpp
)