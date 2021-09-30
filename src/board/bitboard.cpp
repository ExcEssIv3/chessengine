#include "board.h"
#include "../piece/piece.h"
#include "../piece/piecehelpers.h"
#include <tuple>
#include <vector>
#include <bitset>
#include <iostream>

using namespace PIECE;
using namespace BOARD;
using namespace std;

bitboard::bitboard() {
    // TODO: update bitboard to hold actual bitboard values
    board = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };
}

bitboard::bitboard(vector<vector<piece*>> mailbox) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (mailbox[i][j]->getChar() != ' ') {
                short positionConversion = i * 8 + j;
                board[mailbox[i][j]->getBitboardIndex()] ^= 1UL << positionConversion;
            }
        }
    }
};

bitboard::~bitboard() {};

// throws exception on out of bounds
void bitboard::updateBitboard(piece* p, const vector<short>& position) {
    short positionConversion = position[0] * 8 + position[1];
    if (positionConversion > 63) {
        string exception = "Position out of bounds, passed value is " + to_string(position[0]) + ", " + to_string(position[1]);
        throw exception;
    }
    board[p->getBitboardIndex()][positionConversion].flip();
};

vector<bitset<64>> bitboard::getBitboard() {
    return board;
};

vector<vector<piece*>> bitboard::generateMailbox() {
    vector<vector<piece*>> mailbox(8, vector<piece*>(8, new piece()));

    for(int i = 0; i < 12; i++) {
        
        //TODO: fix this garbage, certain checking every bit is not the fastest solution

        for (int j = 0; j < 64; j++) {
            if (board[i][j]) {
                // delete mailbox[j / 8][j % 8];
                mailbox[j / 8][j % 8] = getPieceByShort(i, {static_cast<short>(j / 8), static_cast<short>(j % 8)});
            }
        }
    }

    return mailbox;
};

void bitboard::movePiece(short startIndex, short finalIndex) {
    short pieceIndex;
    for (int i = 0; i < 12; i++) {
        if (board[i][startIndex]) {
            board[i][startIndex].flip();
            pieceIndex = i;
        }
    }

    for (int i = 0; i < 12; i++) {
        if (board[i][finalIndex]) {
            board[i][finalIndex].flip();
        }
    }

    board[pieceIndex][finalIndex].flip();
};

void bitboard::movePiece(short bitboardIndex, short startIndex, short finalIndex) {
    board[bitboardIndex][startIndex].flip();
    for (int i = 0; i < 12; i++) {
        if (board[i][finalIndex]) {
            board[i][finalIndex].flip();
        }
    }
    board[bitboardIndex][finalIndex].flip();
};

void bitboard::printBitboard() {
    for (int i = 0; i < 12; i++) {
        bitset<64> bits(board[i]);
        cout << bits << endl;
    }
};