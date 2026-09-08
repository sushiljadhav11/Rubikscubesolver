//
// Created by sushiljadhav on 9/6/26.
//
#include "iddfssolver.h"

IDDFSSolver::IDDFSSolver(
        RubiksCube3dArray cube)
{
    this->cube = cube;
}

bool IDDFSSolver::dfs(
        int depth,
        int maxDepth)
{
    if(cube.isSolved())
        return true;

    if(depth == maxDepth)
        return false;

    for(int move = RubiksCube::L;
        move <= RubiksCube::B2;
        move++)
    {
        cube.move(
            (RubiksCube::MOVE)move
        );

        moves.push_back(
            (RubiksCube::MOVE)move
        );

        if(dfs(
                depth + 1,
                maxDepth
           ))
            return true;

        moves.pop_back();

        cube.invert(
            (RubiksCube::MOVE)move
        );
    }

    return false;
}

vector<RubiksCube::MOVE>
IDDFSSolver::solve(int maxDepth)
{
    for(int depth = 0;
        depth <= maxDepth;
        depth++)
    {
        moves.clear();

        if(dfs(0,depth))
            return moves;
    }

    return {};
}
