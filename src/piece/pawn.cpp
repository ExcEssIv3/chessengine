#include "piece.h"
#include <list>
#include <vector>

using namespace std;
using namespace PIECE;

pawn::pawn(): piece() {
    pieceChar = 'P';
    color = 0;
    bitboardIndex = 0;
    mgPieceVal = 128;
    egPieceVal = 213;
};

pawn::pawn(vector<short> position, short color): piece(position, color) {
    pieceChar = (color > 0) ? 'p' : 'P';
    bitboardIndex = (color > 0) ? 6 : 0;
    mgPieceVal = 128;
    egPieceVal = 213;
};

pawn::pawn(const pawn& p) {
    this->position = p.position;
    this->pieceChar = p.pieceChar;
    this->color = p.color;
    this->moved = p.moved;
    this->bitboardIndex = p.bitboardIndex;
    this->mgPieceVal = p.mgPieceVal;
    this->egPieceVal = p.egPieceVal;
    this->pinned = p.pinned;
};

list<vector<short>> pawn::getLegalMoves(const vector<vector<piece*>>& positions) {
    return list<vector<short>>{};
};