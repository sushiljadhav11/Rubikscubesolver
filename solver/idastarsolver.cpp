#include "idastarsolver.h"
#include <climits>

using namespace std;

bool sameFace(
        RubiksCube::MOVE m1,
        RubiksCube::MOVE m2)
{
    return (m1 / 3) == (m2 / 3);
}

IDAStarSolver::IDAStarSolver(
        RubiksCube3dArray cube)
{
    this->cube = cube;
}

int IDAStarSolver::heuristic()
{
    int misplaced = 0;

    for(int face = 0; face < 6; face++)
    {
        auto center =
                cube.getColor(
                        (RubiksCube::FACE)face,
                        1,
                        1
                );

        for(int row = 0; row < 3; row++)
        {
            for(int col = 0; col < 3; col++)
            {
                if(
                        cube.getColor(
                                (RubiksCube::FACE)face,
                                row,
                                col
                        )
                        != center
                )
                {
                    misplaced++;
                }
            }
        }
    }

    return misplaced / 8;
}

int IDAStarSolver::search(
        int g,
        int bound,
        int lastMove)
{
    int h = heuristic();

    int f = g + h;

    if(f > bound)
        return f;

    if(cube.isSolved())
        return -1;

    int minimum = INT_MAX;

    for(int move = RubiksCube::L;
        move <= RubiksCube::B2;
        move++)
    {
        if(
                lastMove != -1 &&
                sameFace(
                        (RubiksCube::MOVE)move,
                        (RubiksCube::MOVE)lastMove
                )
          )
        {
            continue;
        }

        cube.move(
                (RubiksCube::MOVE)move
        );

        moves.push_back(
                (RubiksCube::MOVE)move
        );

        int result =
                search(
                        g + 1,
                        bound,
                        move
                );

        if(result == -1)
            return -1;

        minimum =
                min(
                        minimum,
                        result
                );

        moves.pop_back();

        cube.invert(
                (RubiksCube::MOVE)move
        );
    }

    return minimum;
}

vector<RubiksCube::MOVE>
IDAStarSolver::solve()
{
    int bound = heuristic();

    while(true)
    {
        moves.clear();

        int result =
                search(
                        0,
                        bound,
                        -1
                );

        if(result == -1)
            return moves;

        if(result == INT_MAX)
            return {};

        bound = result;
    }
}