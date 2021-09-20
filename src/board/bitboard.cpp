#include "board.h"
#include "piece.h"
#include <tuple>
#include <vector>
#include <bitset>
#include <iostream>

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
            if (mailbox[i][j]->getPieceType() != pieceTypes::empty) {
                short positionConversion = i * 8 + j;
                board[static_cast<int>(mailbox[i][j]->getPieceType())] ^= 1UL << positionConversion;
            }
        }
    }
};

bitboard::~bitboard() {};

// throws exception on out of bounds
void bitboard::updateBitboard(piece* pieces, vector<short> position) {
    short positionConversion = position[0] * 8 + position[1];
    if (positionConversion > 63) {
        string exception = "Position out of bounds, passed value is " + to_string(position[0]) + ", " + to_string(position[1]);
        throw exception;
    }
    board[static_cast<int>(pieces->getPieceType())][positionConversion].flip();
};

vector<bitset<64>> bitboard::getBitboard() {
    return board;
};

vector<vector<piece*>> bitboard::generateMailbox() {
    vector<vector<piece*>> mailbox(8, vector<piece*>(8, &piece()));

    for(int i = 0; i < 12; i++) {
        
        //TODO: fix this garbage, certain checking every bit is not the fastest solution

        for (int j = 0; j < 64; j++) {
            if (board[i][j]) {
                delete mailbox[j / 8][j % 8];
                mailbox[j / 8][j % 8] = getPieceByShort(i);
                mailbox[j / 8][j % 8]->move({static_cast<short>(j / 8), static_cast<short>(j % 8)});
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

void bitboard::movePiece(pieceTypes piece, short startIndex, short finalIndex) {
    board[static_cast<int>(piece)][startIndex].flip();
    for (int i = 0; i < 12; i++) {
        if (board[i][finalIndex]) {
            board[i][finalIndex].flip();
        }
    }
    board[static_cast<int>(piece)][finalIndex].flip();
};

void bitboard::printBitboard() {
    for (int i = 0; i < 12; i++) {
        bitset<64> bits(board[i]);
        cout << bits << endl;
    }
};