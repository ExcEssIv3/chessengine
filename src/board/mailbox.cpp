#include "board.h"
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
                boardRepresentation.updateBitboard(board[i][j], make_tuple(i, j));
            }
        }
    }
    return boardRepresentation;
}

void mailbox::printBoard() {
    for (int i = 0; i < 8; i++) {
        cout << " --- --- --- --- --- --- --- ---" << endl;
        for (int j = 0; j < 8; j++) {
            cout << "| " << getPieceChar(board[i][j]) << " ";
        }
        cout << "|" << endl;
    }
    cout <<  " --- --- --- --- --- --- --- ---" << endl;
};

char mailbox::getPieceChar(pieceTypes piece) {
    char pieceChar[] = {
        'P', 'R', 'N', 'B', 'K', 'Q', 'p', 'r', 'n', 'b', 'k', 'q', ' '
    };
    return pieceChar[static_cast<int>(piece)];
};