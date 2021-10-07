#include "piece.h"
#include <vector>
#include <list>

using namespace std;
using namespace PIECE;

empty::empty(): piece() {
    pieceChar = ' ';
    position = {};
    color = -1;
    mgPieceVal = 0;
    egPieceVal = 0;
    bitboardIndex = -1;
    pieceType = piece_enum::EMPTY;
};

empty::empty(vector<short> position) {
    pieceChar = ' ';
    this->position = position;
    color = -1;
    moved = false;
    mgPieceVal = 0;
    egPieceVal = 0;
    bitboardIndex = -1;
    pieceType = piece_enum::EMPTY;
};

empty::empty(const empty& e): empty() {
    this->pieceChar = e.pieceChar;
    this->position = e.position;
    this->color = e.color;
    this->moved = e.moved;
    this->mgPieceVal = e.mgPieceVal;
    this->egPieceVal = e.egPieceVal;
    this->bitboardIndex = e.bitboardIndex;
    this->pinned = e.pinned;
    this->pinned = e.pinned;
};

list<vector<short>> empty::getLegalMoves(const vector<vector<piece*>>& positions) {
    return list<vector<short>>{};
}