#include "board.h"
#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
using namespace board;

mailbox::mailbox() {
    vector<vector<pieceTypes>> board = vector<vector<pieceTypes>> ({
        vector<pieceTypes> ({
            pieceTypes::brook,
            pieceTypes::bknight,
            pieceTypes::bbishop,
            pieceTypes::bking,
            pieceTypes::bqueen,
            pieceTypes::bbishop,
            pieceTypes::bknight,
            pieceTypes::brook
        }),
        vector<pieceTypes> ({
            pieceTypes::bpawn,
            pieceTypes::bpawn,
            pieceTypes::bpawn,
            pieceTypes::bpawn,
            pieceTypes::bpawn,
            pieceTypes::bpawn,
            pieceTypes::bpawn,
            pieceTypes::bpawn,
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
            pieceTypes::wpawn,
            pieceTypes::wpawn,
            pieceTypes::wpawn,
            pieceTypes::wpawn,
            pieceTypes::wpawn,
            pieceTypes::wpawn,
            pieceTypes::wpawn,
            pieceTypes::wpawn
        }),
        vector<pieceTypes> ({
            pieceTypes::wrook,
            pieceTypes::wknight,
            pieceTypes::wbishop,
            pieceTypes::wking,
            pieceTypes::wqueen,
            pieceTypes::wbishop,
            pieceTypes::wknight,
            pieceTypes::wrook
        })
    });
    boardRepresentation = bitboard(board);

};

mailbox::mailbox(bitboard boardRepresentation) {
    this->boardRepresentation = boardRepresentation;
    board = boardRepresentation.generateMailbox();
};

mailbox::mailbox(vector<vector<pieceTypes>> positions) {
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(positions[i][j] != pieceTypes::empty) {
                boardRepresentation.updateBitboard(positions[i][j], make_tuple(i, j));
            }
        }
    }
    board = positions;
};

vector<vector<pieceTypes>> mailbox::getBoard() {
    return board;
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
    switch(piece) {
        case pieceTypes::wpawn:
            return 'P';
        case pieceTypes::wrook:
            return 'R';
        case pieceTypes::wknight:
            return 'N';
        case pieceTypes::wbishop:
            return 'B';
        case pieceTypes::wking:
            return 'K';
        case pieceTypes::wqueen:
            return 'Q';
        case pieceTypes::bpawn:
            return 'p';
        case pieceTypes::brook:
            return 'r';
        case pieceTypes::bknight:
            return 'n';
        case pieceTypes::bbishop:
            return 'b';
        case pieceTypes::bking:
            return 'k';
        case pieceTypes::bqueen:
            return 'q';
        default:
            return ' ';

    }
};