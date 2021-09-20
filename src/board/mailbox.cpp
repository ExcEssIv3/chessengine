#include "board.h"
#include "piece.h"
#include <iostream>
#include <vector>
#include <tuple>
#include <string>
using namespace std;
using namespace BOARD;
using namespace PIECE;

mailbox::mailbox() {
    this->board = vector<vector<piece*>> ({
        vector<piece*> ({
            &piece({0,0}, 'R', 0),
            &piece({0,1}, 'N', 0),
            &piece({0,2}, 'B', 0),
            &piece({0,3}, 'K', 0),
            &piece({0,4}, 'Q', 0),
            &piece({0,5}, 'B', 0),
            &piece({0,6}, 'N', 0),
            &piece({0,7}, 'R', 0)
        }),
        vector<piece*> ({
            &piece({1,0}, 'P', 0),
            &piece({1,1}, 'P', 0),
            &piece({1,2}, 'P', 0),
            &piece({1,3}, 'P', 0),
            &piece({1,4}, 'P', 0),
            &piece({1,5}, 'P', 0),
            &piece({1,6}, 'P', 0),
            &piece({1,7}, 'P', 0)
        }),
        vector<piece*> ({
            &piece({2,0}, ' ', -1),
            &piece({2,1}, ' ', -1),
            &piece({2,2}, ' ', -1),
            &piece({2,3}, ' ', -1),
            &piece({2,4}, ' ', -1),
            &piece({2,5}, ' ', -1),
            &piece({2,6}, ' ', -1),
            &piece({2,7}, ' ', -1)
        }),
        vector<piece*> ({
            &piece({3,0}, ' ', -1),
            &piece({3,1}, ' ', -1),
            &piece({3,2}, ' ', -1),
            &piece({3,3}, ' ', -1),
            &piece({3,4}, ' ', -1),
            &piece({3,5}, ' ', -1),
            &piece({3,6}, ' ', -1),
            &piece({3,7}, ' ', -1)
        }),
        vector<piece*> ({
            &piece({4,0}, ' ', -1),
            &piece({4,1}, ' ', -1),
            &piece({4,2}, ' ', -1),
            &piece({4,3}, ' ', -1),
            &piece({4,4}, ' ', -1),
            &piece({4,5}, ' ', -1),
            &piece({4,6}, ' ', -1),
            &piece({4,7}, ' ', -1)
        }),
        vector<piece*> ({
            &piece({5,0}, ' ', -1),
            &piece({5,1}, ' ', -1),
            &piece({5,2}, ' ', -1),
            &piece({5,3}, ' ', -1),
            &piece({5,4}, ' ', -1),
            &piece({5,5}, ' ', -1),
            &piece({5,6}, ' ', -1),
            &piece({5,7}, ' ', -1)
        }),
        vector<piece*> ({
            &piece({6,0}, 'p', 1),
            &piece({6,1}, 'p', 1),
            &piece({6,2}, 'p', 1),
            &piece({6,3}, 'p', 1),
            &piece({6,4}, 'p', 1),
            &piece({6,5}, 'p', 1),
            &piece({6,6}, 'p', 1),
            &piece({6,7}, 'p', 1)
        }),
        vector<piece*> ({
            &piece({7,0}, 'r', 1),
            &piece({7,1}, 'n', 1),
            &piece({7,2}, 'b', 1),
            &piece({7,3}, 'k', 1),
            &piece({7,4}, 'q', 1),
            &piece({7,5}, 'b', 1),
            &piece({7,6}, 'n', 1),
            &piece({7,7}, 'r', 1)
        })
    });
};

mailbox::mailbox(bitboard boardRepresentation) {
    board = boardRepresentation.generateMailbox();
};

mailbox::mailbox(vector<vector<piece*>> positions) {
    board = positions;
};

mailbox::~mailbox() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            delete board[i][j];
        }
    }
};

vector<vector<piece*>> mailbox::getBoard() {
    return board;
}

bitboard mailbox::getBitboard() {
    bitboard boardRepresentation = bitboard();
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(board[i][j]->getPieceType() != pieceTypes::empty) {
                boardRepresentation.updateBitboard(board[i][j], {static_cast<short>(i), static_cast<short>(j)});
            }
        }
    }
    return boardRepresentation;
};

piece* mailbox::getPieceAtIndex(vector<short> index) {
    return board[index[0]][index[1]];
};

void mailbox::printBoard() {
    for (int i = 7; i > -1; i--) {
        cout << " --- --- --- --- --- --- --- ---" << endl;
        for (int j = 0; j < 8; j++) {
            cout << "| " << board[i][j]->getChar() << " ";
        }
        cout << "|" << endl;
    }
    cout <<  " --- --- --- --- --- --- --- ---" << endl;
};

void mailbox::movePiece(vector<short> startIndex, vector<short>finalIndex) {
    piece* pieceToMove = board[startIndex[0]][startIndex[1]];
    pieceToMove->move(finalIndex);
    board[startIndex[0]][startIndex[1]] = &piece(startIndex, ' ', -1);
    board[finalIndex[0]][finalIndex[1]] = pieceToMove;
};
