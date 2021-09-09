#include "board.h"
#include <iostream>
#include <tuple>
// using namespace std;
using namespace board;

void bitboard::updateBitboard(short piece, tuple<short, short> position) {
    short positionConversion = get<0>(position) * 8 + get<1>(position);
    board[piece] ^= 1UL << positionConversion;
};

// class board {

// }