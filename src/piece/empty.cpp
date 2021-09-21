#include "piece.h"
#include <vector>

using namespace std;
using namespace PIECE;

empty::empty() {
    pieceChar = ' ';
    position = {};
    color = -1;
    moved = false;
    mgPieceVal, egPieceVal = 0;
    bitboardIndex = -1;
};

empty::empty(vector<short> position) {
    pieceChar = ' ';
    this->position = position;
    color = -1;
    moved = false;
    mgPieceVal, egPieceVal = 0;
    bitboardIndex = -1;
};

empty::empty(const empty& e): empty() {
    this->pieceChar = e.pieceChar;
    this->position = e.position;
    this->color = e.color;
    this->moved = e.moved;
    this->mgPieceVal = e.mgPieceVal;
    this->egPieceVal = e.egPieceVal;
    this->bitboardIndex = e.bitboardIndex;
};