#include "board.h"
#include "../piece/piece.h"
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
            new rook({0,0}, 0),
            new knight({0,1}, 0),
            new bishop({0,2}, 0),
            new king({0,3}, 0),
            new queen({0,4}, 0),
            new bishop({0,5}, 0),
            new knight({0,6}, 0),
            new rook({0,7}, 0)
        }),
        vector<piece*> ({
            new pawn({1,0}, 0),
            new pawn({1,1}, 0),
            new pawn({1,2}, 0),
            new pawn({1,3}, 0),
            new pawn({1,4}, 0),
            new pawn({1,5}, 0),
            new pawn({1,6}, 0),
            new pawn({1,7}, 0)
        }),
        vector<piece*> ({
            new PIECE::empty({2,0}),
            new PIECE::empty({2,1}),
            new PIECE::empty({2,2}),
            new PIECE::empty({2,3}),
            new PIECE::empty({2,4}),
            new PIECE::empty({2,5}),
            new PIECE::empty({2,6}),
            new PIECE::empty({2,7})
        }),
        vector<piece*> ({
            new PIECE::empty({3,0}),
            new PIECE::empty({3,1}),
            new PIECE::empty({3,2}),
            new PIECE::empty({3,3}),
            new PIECE::empty({3,4}),
            new PIECE::empty({3,5}),
            new PIECE::empty({3,6}),
            new PIECE::empty({3,7})
        }),
        vector<piece*> ({
            new PIECE::empty({4,0}),
            new PIECE::empty({4,1}),
            new PIECE::empty({4,2}),
            new PIECE::empty({4,3}),
            new PIECE::empty({4,4}),
            new PIECE::empty({4,5}),
            new PIECE::empty({4,6}),
            new PIECE::empty({4,7})
        }),
        vector<piece*> ({
            new PIECE::empty({5,0}),
            new PIECE::empty({5,1}),
            new PIECE::empty({5,2}),
            new PIECE::empty({5,3}),
            new PIECE::empty({5,4}),
            new PIECE::empty({5,5}),
            new PIECE::empty({5,6}),
            new PIECE::empty({5,7})
        }),
        vector<piece*> ({
            new pawn({6,0}, 1),
            new pawn({6,1}, 1),
            new pawn({6,2}, 1),
            new pawn({6,3}, 1),
            new pawn({6,4}, 1),
            new pawn({6,5}, 1),
            new pawn({6,6}, 1),
            new pawn({6,7}, 1)
        }),
        vector<piece*> ({
            new rook({7,0}, 1),
            new knight({7,1}, 1),
            new bishop({7,2}, 1),
            new king({7,3}, 1),
            new queen({7,4}, 1),
            new bishop({7,5}, 1),
            new knight({7,6}, 1),
            new rook({7,7}, 1)
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
    // for (int i = 0; i < 8; i++) {
    //     for (int j = 0; j < 8; j++) {
    //         if (board[i][j] != nullptr) {
    //             delete board[i][j];
    //         }
    //     }
    // }
};

vector<vector<piece*>> mailbox::getBoard() {
    return board;
}

bitboard mailbox::getBitboard() {
    bitboard boardRepresentation = bitboard();
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(board[i][j]->getChar() != ' ') {
                boardRepresentation.updateBitboard(board[i][j], {static_cast<short>(i), static_cast<short>(j)});
            }
        }
    }
    return boardRepresentation;
};

piece* mailbox::getPieceAtIndex(const vector<short>& index) {
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

void mailbox::movePiece(const vector<short>& startIndex, const vector<short>& finalIndex) {
    piece* pieceToMove = board[startIndex[0]][startIndex[1]];
    pieceToMove->move(finalIndex);
    board[startIndex[0]][startIndex[1]] = new PIECE::empty(startIndex);
    board[finalIndex[0]][finalIndex[1]] = pieceToMove;
};
