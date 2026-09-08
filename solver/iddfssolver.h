//
// Created by sushiljadhav on 9/6/26.
//

#ifndef RUBIKS_CUBE_MINE_IDDFSSOLVER_H
#define RUBIKS_CUBE_MINE_IDDFSSOLVER_H
#include "../models/rubikscube3darray.h"

class IDDFSSolver
{
private:

    RubiksCube3dArray cube;
    vector<RubiksCube::MOVE> moves;

    bool dfs(int depth,int maxDepth);

public:

    IDDFSSolver(RubiksCube3dArray cube);

    vector<RubiksCube::MOVE> solve(int maxDepth);
};
#endif //RUBIKS_CUBE_MINE_IDDFSSOLVER_H
