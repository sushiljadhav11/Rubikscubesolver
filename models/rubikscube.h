#ifndef RUBIKS_CUBE_MINE_RUBKISCUBE_H
#define RUBIKS_CUBE_MINE_RUBKISCUBE_H
#include <bits/stdc++.h>
using namespace  std;
class RubiksCube {
public:

    enum FACE {
        UP,
        LEFT,
        FRONT,
        RIGHT,
        BACK,
        DOWN
    };

    enum COLOR {
        WHITE,
        GREEN,
        RED,
        BLUE,
        ORANGE,
        YELLOW
    };

    enum MOVE {
        L,
        LPRIME,
        L2,

        R,
        RPRIME,
        R2,

        U,
        UPRIME,
        U2,

        D,
        DPRIME,
        D2,

        F,
        FPRIME,
        F2,

        B,
        BPRIME,
        B2
    };
public:
    static MOVE getRandomMove();
    virtual COLOR getColor(FACE face, unsigned row, unsigned col) const = 0;

    virtual bool isSolved() const = 0;

    virtual RubiksCube& move(MOVE ind) = 0;

    virtual RubiksCube& invert(MOVE ind) = 0;

    virtual void print() const;

    string getColorLetter(COLOR color) const;

    vector<MOVE> randomShuffleCube(unsigned int times);
    virtual string getMove(MOVE ind);

    //18 cube moves
    virtual RubiksCube& f() = 0;
    virtual RubiksCube& fPrime() = 0;
    virtual RubiksCube& f2() = 0;

    virtual RubiksCube& u() = 0;
    virtual RubiksCube& uPrime() = 0;
    virtual RubiksCube& u2() = 0;

    virtual RubiksCube& l() = 0;
    virtual RubiksCube& lPrime() = 0;
    virtual RubiksCube& l2() = 0;

    virtual RubiksCube& r() = 0;
    virtual RubiksCube& rPrime() = 0;
    virtual RubiksCube& r2() = 0;

    virtual RubiksCube& b() = 0;
    virtual RubiksCube& bPrime() = 0;
    virtual RubiksCube& b2() = 0;

    virtual RubiksCube& d() = 0;
    virtual RubiksCube& dPrime() = 0;
    virtual RubiksCube& d2() = 0;

    //comparator
    virtual bool operator==(const RubiksCube &r1) const = 0;
    //hashing support
    virtual uint64_t getHash() const = 0;
    
};

#endif // RUBIKS_CUBE_MINE_RUBKISCUBE_H