# Rubik's Cube Solver in C++

A Rubik's Cube Solver implemented in C++ using a 3D-array cube representation.

## Features

* 3D Array Cube Representation
* All 18 Standard Cube Moves
* Move Inversion Support
* Cube Hashing
* BFS Solver
* IDDFS Solver
* IDA* Solver
* Move Pruning
* Random Scramble Generator
* Performance Benchmarking

## Algorithms Implemented

### Breadth First Search (BFS)

Finds the shortest solution but requires large memory.

### Iterative Deepening DFS (IDDFS)

Combines DFS memory efficiency with BFS-like completeness.

### Iterative Deepening A* (IDA*)

Uses a heuristic-guided search to solve cubes more efficiently.

## Technologies Used

* C++17
* STL
* CMake
* CLion

## Project Structure

```text
models/
├── rubikscube.h
├── rubikscube.cpp
├── rubikscube3darray.h
└── rubikscube3darray.cpp

solver/
├── bfssolver.h
├── bfssolver.cpp
├── iddfssolver.h
├── iddfssolver.cpp
├── idastarsolver.h
└── idastarsolver.cpp

main.cpp
CMakeLists.txt
```

## Future Improvements

* Pattern Database Heuristics
* Kociemba Two-Phase Solver
* GUI Visualization
* Bitboard Representation
