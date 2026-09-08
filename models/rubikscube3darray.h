//
// Created by sushiljadhav on 9/5/26.
//
#ifndef RUBIKS_CUBE_MINE_RUBIKSCUBE3DARRAY_H
#define RUBIKS_CUBE_MINE_RUBIKSCUBE3DARRAY_H

#include "rubikscube.h"

class RubiksCube3dArray : public RubiksCube {

private:

    COLOR cube[6][3][3];

public:

    RubiksCube3dArray();

    COLOR getColor(FACE face,
                   unsigned row,
                   unsigned col) const override;
    bool isSolved() const override;
    RubiksCube& move(MOVE ind) override;
    RubiksCube& invert(MOVE ind) override;

    RubiksCube& f() override;
    RubiksCube& fPrime() override;
    RubiksCube& f2() override;

    RubiksCube& u() override;
    RubiksCube& uPrime() override;
    RubiksCube& u2() override;

    RubiksCube& l() override;
    RubiksCube& lPrime() override;
    RubiksCube& l2() override;

    RubiksCube& r() override;
    RubiksCube& rPrime() override;
    RubiksCube& r2() override;

    RubiksCube& b() override;
    RubiksCube& bPrime() override;
    RubiksCube& b2() override;

    RubiksCube& d() override;
    RubiksCube& dPrime() override;
    RubiksCube& d2() override;

    bool operator==(const RubiksCube &r1) const override;
    uint64_t getHash() const override;
};
#endif