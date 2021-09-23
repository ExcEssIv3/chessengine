#include "piece.h"
#include <list>
#include <vector>

using namespace std;
using namespace PIECE;

rook::rook() {
    pieceChar = 'R';
    color = 0;
    bitboardIndex = 1;
    mgPieceVal = 1276;
    egPieceVal = 1380;
};

rook::rook(vector<short> position, short color): piece(position, color) {
    pieceChar = (color > 0) ? 'r' : 'R';
    bitboardIndex = (color > 0) ? 7 : 1;
    mgPieceVal = 1276;
    egPieceVal = 1380;
};

rook::rook(const rook& r) {
    this->position = r.position;
    this->pieceChar = r.pieceChar;
    this->color = r.color;
    this->moved = r.moved;
    this->bitboardIndex = bitboardIndex;
    this->mgPieceVal = r.mgPieceVal;
    this->egPieceVal = r.egPieceVal;
};

list<short*> rook::getLegalMoves(vector<vector<piece*>> positions) {
    return list<short*>{};
};