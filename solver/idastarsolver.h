#ifndef RUBIKS_CUBE_MINE_IDASTARSOLVER_H
#define RUBIKS_CUBE_MINE_IDASTARSOLVER_H

#include "../models/rubikscube3darray.h"
#include <bits/stdc++.h>

class IDAStarSolver
{
private:

    RubiksCube3dArray cube;
    std::vector<RubiksCube::MOVE> moves;

    int heuristic();

    int search(
            int g,
            int bound,
            int lastMove
    );

public:

    IDAStarSolver(
            RubiksCube3dArray cube
    );

    std::vector<RubiksCube::MOVE> solve();
};

#endif