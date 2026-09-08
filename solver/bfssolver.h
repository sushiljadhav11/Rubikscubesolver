//
// Created by sushiljadhav on 9/6/26.
//

#ifndef RUBIKS_CUBE_MINE_BFSSOLVER_H
#define RUBIKS_CUBE_MINE_BFSSOLVER_H

#include "../models/rubikscube3darray.h"
#include<bits/stdc++.h>

class BFSSolver
{
private:
    RubiksCube3dArray cube;

public:
    BFSSolver(RubiksCube3dArray cube);

    std::vector<RubiksCube::MOVE> solve();
};

#endif