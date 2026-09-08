#include "rubikscube3darray.h"

bool RubiksCube3dArray::operator==(const RubiksCube &r1) const
{
    for(int face = 0; face < 6; face++)
    {
        for(int row = 0; row < 3; row++)
        {
            for(int col = 0; col < 3; col++)
            {
                if(
                    getColor((FACE)face,row,col)
                    !=
                    r1.getColor((FACE)face,row,col)
                )
                    return false;
            }
        }
    }

    return true;
}

uint64_t RubiksCube3dArray::getHash() const
{
    uint64_t hash = 0;

    for(int face = 0; face < 6; face++)
    {
        for(int row = 0; row < 3; row++)
        {
            for(int col = 0; col < 3; col++)
            {
                hash = hash * 6
                       +
                       getColor(
                           (FACE)face,
                           row,
                           col
                       );
            }
        }
    }

    return hash;
}

RubiksCube3dArray::RubiksCube3dArray()
{
    for(int row = 0; row < 3; row++)
    {
        for(int col = 0; col < 3; col++)
        {
            cube[UP][row][col] = WHITE;
            cube[LEFT][row][col] = GREEN;
            cube[FRONT][row][col] = RED;
            cube[RIGHT][row][col] = BLUE;
            cube[BACK][row][col] = ORANGE;
            cube[DOWN][row][col] = YELLOW;
        }
    }
}

RubiksCube::COLOR RubiksCube3dArray::getColor(
        FACE face,
        unsigned row,
        unsigned col) const
{
    return cube[face][row][col];
}

bool RubiksCube3dArray::isSolved() const
{
    for (int face = 0; face < 6; face++)
    {
        COLOR centerColor = cube[face][1][1];

        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                if (cube[face][row][col] != centerColor)
                    return false;
            }
        }
    }

    return true;
}

RubiksCube& RubiksCube3dArray::move(MOVE ind) {
    switch(ind)
    {
        case U:
            return u();

        case UPRIME:
            return uPrime();

        case U2:
            return u2();

        case R:
            return r();

        case RPRIME:
            return rPrime();

        case R2:
            return r2();

        case L: return l();
        case LPRIME: return lPrime();
        case L2: return l2();

        case F: return f();
        case FPRIME: return fPrime();
        case F2: return f2();

        case B: return b();
        case BPRIME: return bPrime();
        case B2: return b2();

        case D: return d();
        case DPRIME: return dPrime();
        case D2: return d2();
        default:
            return *this;
    }
}
RubiksCube& RubiksCube3dArray::invert(MOVE ind) {
    switch(ind)
    {
        case U:       return uPrime();
        case UPRIME:  return u();
        case U2:      return u2();

        case L:       return lPrime();
        case LPRIME:  return l();
        case L2:      return l2();

        case R:       return rPrime();
        case RPRIME:  return r();
        case R2:      return r2();

        case F:       return fPrime();
        case FPRIME:  return f();
        case F2:      return f2();

        case B:       return bPrime();
        case BPRIME:  return b();
        case B2:      return b2();

        case D:       return dPrime();
        case DPRIME:  return d();
        case D2:      return d2();
    }

    return *this;
}
static void rotateFaceClockwise(
        RubiksCube::COLOR face[3][3])
{
    RubiksCube::COLOR temp[3][3];

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            temp[j][2 - i] = face[i][j];
        }
    }

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            face[i][j] = temp[i][j];
        }
    }
}
RubiksCube& RubiksCube3dArray::f() {
    rotateFaceClockwise(cube[FRONT]);

    COLOR temp[3];

    for(int i = 0; i < 3; i++)
        temp[i] = cube[UP][2][i];

    for(int i = 0; i < 3; i++)
        cube[UP][2][i] = cube[LEFT][2-i][2];

    for(int i = 0; i < 3; i++)
        cube[LEFT][i][2] = cube[DOWN][0][i];

    for(int i = 0; i < 3; i++)
        cube[DOWN][0][i] = cube[RIGHT][2-i][0];

    for(int i = 0; i < 3; i++)
        cube[RIGHT][i][0] = temp[i];

    return *this;
}
RubiksCube& RubiksCube3dArray::fPrime() {
    f();
    f();
    f();
    return *this;
}
RubiksCube& RubiksCube3dArray::f2() {
    f();
    f();

    return *this;
}
RubiksCube& RubiksCube3dArray::u() {
    rotateFaceClockwise(cube[UP]);

    COLOR temp[3];

    for(int i = 0; i < 3; i++)
        temp[i] = cube[FRONT][0][i];

    for(int i = 0; i < 3; i++)
        cube[FRONT][0][i] = cube[RIGHT][0][i];

    for(int i = 0; i < 3; i++)
        cube[RIGHT][0][i] = cube[BACK][0][i];

    for(int i = 0; i < 3; i++)
        cube[BACK][0][i] = cube[LEFT][0][i];

    for(int i = 0; i < 3; i++)
        cube[LEFT][0][i] = temp[i];

    return *this;
}
RubiksCube& RubiksCube3dArray::uPrime() {
    u();
    u();
    u();
    return *this;
}
RubiksCube& RubiksCube3dArray::u2() {
    u();
    u();

    return *this;
}

RubiksCube& RubiksCube3dArray::l() {
    rotateFaceClockwise(cube[LEFT]);

    COLOR temp[3];

    for(int i = 0; i < 3; i++)
        temp[i] = cube[UP][i][0];

    for(int i = 0; i < 3; i++)
        cube[UP][i][0] = cube[BACK][2-i][2];

    for(int i = 0; i < 3; i++)
        cube[BACK][2-i][2] = cube[DOWN][i][0];

    for(int i = 0; i < 3; i++)
        cube[DOWN][i][0] = cube[FRONT][i][0];

    for(int i = 0; i < 3; i++)
        cube[FRONT][i][0] = temp[i];

    return *this;
}
RubiksCube& RubiksCube3dArray::lPrime() {
    l();
    l();
    l();

    return *this;
}
RubiksCube& RubiksCube3dArray::l2() {
    l();
    l();

    return *this;
}

RubiksCube& RubiksCube3dArray::r() {
    rotateFaceClockwise(cube[RIGHT]);

    COLOR temp[3];

    for(int i = 0; i < 3; i++)
        temp[i] = cube[UP][i][2];

    for(int i = 0; i < 3; i++)
        cube[UP][i][2] = cube[FRONT][i][2];

    for(int i = 0; i < 3; i++)
        cube[FRONT][i][2] = cube[DOWN][i][2];

    for(int i = 0; i < 3; i++)
        cube[DOWN][i][2] = cube[BACK][2-i][0];

    for(int i = 0; i < 3; i++)
        cube[BACK][2-i][0] = temp[i];


    return *this;
}
RubiksCube& RubiksCube3dArray::rPrime() {
        r();
        r();
        r();

        return *this;
}
RubiksCube& RubiksCube3dArray::r2() {
    r();
    r();

    return *this;
}

RubiksCube& RubiksCube3dArray::b() {
    rotateFaceClockwise(cube[BACK]);

    COLOR temp[3];

    for(int i = 0; i < 3; i++)
        temp[i] = cube[UP][0][i];

    for(int i = 0; i < 3; i++)
        cube[UP][0][i] = cube[RIGHT][i][2];

    for(int i = 0; i < 3; i++)
        cube[RIGHT][i][2] = cube[DOWN][2][2-i];

    for(int i = 0; i < 3; i++)
        cube[DOWN][2][i] = cube[LEFT][i][0];

    for(int i = 0; i < 3; i++)
        cube[LEFT][i][0] = temp[2-i];

    return *this;
}
RubiksCube& RubiksCube3dArray::bPrime() {
    b();
    b();
    b();
    return *this;
}
RubiksCube& RubiksCube3dArray::b2() {
    b();
    b();
    return *this;
}

RubiksCube& RubiksCube3dArray::d() {
    rotateFaceClockwise(cube[DOWN]);

    COLOR temp[3];

    for(int i = 0; i < 3; i++)
        temp[i] = cube[FRONT][2][i];

    for(int i = 0; i < 3; i++)
        cube[FRONT][2][i] = cube[LEFT][2][i];

    for(int i = 0; i < 3; i++)
        cube[LEFT][2][i] = cube[BACK][2][i];

    for(int i = 0; i < 3; i++)
        cube[BACK][2][i] = cube[RIGHT][2][i];

    for(int i = 0; i < 3; i++)
        cube[RIGHT][2][i] = temp[i];

    return *this;
}
RubiksCube& RubiksCube3dArray::dPrime() {
    d();
    d();
    d();
    return *this;
}
RubiksCube& RubiksCube3dArray::d2() {
    d();
    d();

    return *this;
}