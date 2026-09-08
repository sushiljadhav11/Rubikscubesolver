#include <bits/stdc++.h>
#include "models/rubikscube3darray.h"
#include "solver/bfssolver.h"
#include "solver/idastarsolver.h"
#include<chrono>

#include "solver/iddfssolver.h"
using namespace std;
void scrambleCube(
        RubiksCube3dArray &cube,
        int numMoves,
        vector<RubiksCube::MOVE> &scrambleMoves)
{
    scrambleMoves.clear();

    int lastFace = -1;

    for(int i = 0; i < numMoves; i++)
    {
        RubiksCube::MOVE move;

        do
        {
            move =
                (RubiksCube::MOVE)(rand() % 18);
        }
        while((int)move / 3 == lastFace);

        lastFace = (int)move / 3;

        cube.move(move);

        scrambleMoves.push_back(move);
    }
}

long long getExecutionTime(function<void()> func)
{
        auto start =
            chrono::high_resolution_clock::now();

        func();

        auto stop =
            chrono::high_resolution_clock::now();

        return chrono::duration_cast<
            chrono::milliseconds
        >(stop - start).count();
}

void benchmark(int scrambleLength)
{
    RubiksCube3dArray cube;

    vector<RubiksCube::MOVE> scrambleMoves;

    scrambleCube(
        cube,
        scrambleLength,
        scrambleMoves
    );

    cout << "\n====================================\n";
    cout << "Scramble Length : "
         << scrambleLength
         << endl;

    cout << "Scramble : ";

    for(auto move : scrambleMoves)
    {
        cout << cube.getMove(move) << " ";
    }

    cout << "\n====================================\n";

    long long bfsTime =
        getExecutionTime([&]()
        {
            BFSSolver solver(cube);
            solver.solve();
        });

    long long iddfsTime =
        getExecutionTime([&]()
        {
            IDDFSSolver solver(cube);
            solver.solve(scrambleLength + 2);
        });

    long long idaTime =
        getExecutionTime([&]()
        {
            IDAStarSolver solver(cube);
            solver.solve();
        });

    cout << "BFS    : "
         << bfsTime
         << " ms\n";

    cout << "IDDFS  : "
         << iddfsTime
         << " ms\n";

    cout << "IDA*   : "
         << idaTime
         << " ms\n";
}

int main()
{
    srand(time(nullptr));

    benchmark(3);
    benchmark(4);
    benchmark(5);

    return 0;
}