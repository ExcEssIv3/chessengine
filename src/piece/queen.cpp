#include "piece.h"
#include <vector>

using namespace std;
using namespace PIECE;

queen::queen() {
    pieceChar = 'Q';
    color = 0;
    bitboardIndex = 5;
    mgPieceVal = 2538;
    egPieceVal = 2682;
};

queen::queen(vector<short> position, short color): piece(position, color) {
    pieceChar = (color > 0) ? 'q' : 'Q';
    bitboardIndex = (color > 0) ? 11 : 5;
    mgPieceVal = 2538;
    egPieceVal = 2682;
};

queen::queen(const queen& q) {
    this->position = q.position;
    this->pieceChar = q.pieceChar;
    this->color = q.color;
    this->moved = q.moved;
    this->bitboardIndex = q.bitboardIndex;
    this->mgPieceVal = q.mgPieceVal;
    this->egPieceVal = q.egPieceVal;
};

vector<vector<short>> queen::getLegalMoves(vector<vector<short>> positions) {
    return {{0, 0}};
};