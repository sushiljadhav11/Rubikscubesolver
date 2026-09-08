//
// Created by sushiljadhav on 9/6/26.
//
#include "bfssolver.h"

using namespace std;

BFSSolver::BFSSolver(RubiksCube3dArray cube)
{
    this->cube = cube;
}

vector<RubiksCube::MOVE> BFSSolver::solve()
{
    queue<
        pair<
            RubiksCube3dArray,
            vector<RubiksCube::MOVE>
        >
    > q;

    unordered_set<uint64_t> visited;

    q.push({cube,{}});

    visited.insert(cube.getHash());

    while(!q.empty())
    {
        auto node = q.front();
        q.pop();

        RubiksCube3dArray currentCube = node.first;
        vector<RubiksCube::MOVE> currentPath = node.second;

        if(currentCube.isSolved())
            return currentPath;

        for(int move = RubiksCube::L;
            move <= RubiksCube::B2;
            move++)
        {
            RubiksCube3dArray nextCube = currentCube;

            nextCube.move(
                (RubiksCube::MOVE)move
            );

            uint64_t hash =
                nextCube.getHash();

            if(
                visited.find(hash)
                !=
                visited.end()
            )
                continue;

            visited.insert(hash);

            vector<RubiksCube::MOVE>
            nextPath = currentPath;

            nextPath.push_back(
                    (RubiksCube::MOVE)move
            );

            q.push({
                nextCube,
                nextPath
            });
        }
    }

    return {};
}