//
// Created by sushiljadhav on 9/5/26.
//
#include "rubikscube.h"

string RubiksCube::getColorLetter(COLOR color) const {
    switch (color) {
        case WHITE:  return "W";
        case GREEN:  return "G";
        case RED:    return "R";
        case BLUE:   return "B";
        case ORANGE: return "O";
        case YELLOW: return "Y";
    }
    return "?";
}

string RubiksCube::getMove(MOVE ind) {
    switch (ind) {
        case L: return "L";
        case LPRIME: return "L'";
        case L2: return "L2";

        case R: return "R";
        case RPRIME: return "R'";
        case R2: return "R2";

        case U: return "U";
        case UPRIME: return "U'";
        case U2: return "U2";

        case D: return "D";
        case DPRIME: return "D'";
        case D2: return "D2";

        case F: return "F";
        case FPRIME: return "F'";
        case F2: return "F2";

        case B: return "B";
        case BPRIME: return "B'";
        case B2: return "B2";
    }
    return "";
}
void RubiksCube::print() const {

    string faceNames[6] = {
        "UP",
        "LEFT",
        "FRONT",
        "RIGHT",
        "BACK",
        "DOWN"
    };

    for(int face = 0; face < 6; face++) {

        cout << faceNames[face] << "\n";

        for(int row = 0; row < 3; row++) {

            for(int col = 0; col < 3; col++) {

                cout << getColorLetter(
                        getColor(
                                (FACE)face,
                                row,
                                col
                        )
                ) << " ";
            }

            cout << "\n";
        }

        cout << "\n";
    }
}
RubiksCube::MOVE RubiksCube::getRandomMove()
{
    return (MOVE)(rand() % 18);
}