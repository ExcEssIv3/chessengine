#include "board.h"
#include "piece.h"
#include <iostream>
#include <vector>
#include <tuple>
#include <string>
using namespace std;
using namespace BOARD;

mailbox::mailbox() {
    this->board = vector<vector<pieceTypes>> ({
        vector<pieceTypes> ({
            pieceTypes::r,
            pieceTypes::n,
            pieceTypes::b,
            pieceTypes::k,
            pieceTypes::q,
            pieceTypes::b,
            pieceTypes::n,
            pieceTypes::r
        }),
        vector<pieceTypes> ({
            pieceTypes::p,
            pieceTypes::p,
            pieceTypes::p,
            pieceTypes::p,
            pieceTypes::p,
            pieceTypes::p,
            pieceTypes::p,
            pieceTypes::p,
        }),
        vector<pieceTypes> ({
            pieceTypes::empty,
            pieceTypes::empty,
            pieceTypes::empty,
            pieceTypes::empty,
            pieceTypes::empty,
            pieceTypes::empty,
            pieceTypes::empty,
            pieceTypes::empty
        }),
        vector<pieceTypes> ({
            pieceTypes::empty,
            pieceTypes::empty,
            pieceTypes::empty,
            pieceTypes::empty,
            pieceTypes::empty,
            pieceTypes::empty,
            pieceTypes::empty,
            pieceTypes::empty
        }),
        vector<pieceTypes> ({
            pieceTypes::empty,
            pieceTypes::empty,
            pieceTypes::empty,
            pieceTypes::empty,
            pieceTypes::empty,
            pieceTypes::empty,
            pieceTypes::empty,
            pieceTypes::empty
        }),
        vector<pieceTypes> ({
            pieceTypes::empty,
            pieceTypes::empty,
            pieceTypes::empty,
            pieceTypes::empty,
            pieceTypes::empty,
            pieceTypes::empty,
            pieceTypes::empty,
            pieceTypes::empty
        }),
        vector<pieceTypes> ({
            pieceTypes::P,
            pieceTypes::P,
            pieceTypes::P,
            pieceTypes::P,
            pieceTypes::P,
            pieceTypes::P,
            pieceTypes::P,
            pieceTypes::P
        }),
        vector<pieceTypes> ({
            pieceTypes::R,
            pieceTypes::N,
            pieceTypes::B,
            pieceTypes::K,
            pieceTypes::Q,
            pieceTypes::B,
            pieceTypes::N,
            pieceTypes::R
        })
    });
};

mailbox::mailbox(bitboard boardRepresentation) {
    board = boardRepresentation.generateMailbox();
};

mailbox::mailbox(vector<vector<pieceTypes>> positions) {
    board = positions;
};

mailbox::~mailbox() {};

vector<vector<pieceTypes>> mailbox::getBoard() {
    return board;
}

bitboard mailbox::getBitboard() {
    bitboard boardRepresentation = bitboard();
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(board[i][j] != pieceTypes::empty) {
                boardRepresentation.updateBitboard(board[i][j], {static_cast<short>(i), static_cast<short>(j)});
            }
        }
    }
    return boardRepresentation;
};

pieceTypes mailbox::getPieceAtIndex(vector<short> index) {
    return pieceTypes::empty;
};

void mailbox::printBoard() {
    for (int i = 7; i > -1; i--) {
        cout << " --- --- --- --- --- --- --- ---" << endl;
        for (int j = 0; j < 8; j++) {
            cout << "| " << getPieceChar(board[i][j]) << " ";
        }
        cout << "|" << endl;
    }
    cout <<  " --- --- --- --- --- --- --- ---" << endl;
};

void mailbox::movePiece(vector<short> startIndex, vector<short>finalIndex) {
    pieceTypes piece = board[startIndex[0]][startIndex[1]];
    board[startIndex[0]][startIndex[1]] = pieceTypes::empty;
    board[finalIndex[0]][finalIndex[1]] = piece;
};
