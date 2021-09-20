#include "piece.h"
#include <vector>

using namespace std;
using namespace PIECE;

rook::rook() {
    pieceChar = 'R';
    color = 0;
    bitboardIndex = 1;
};

rook::rook(vector<short> position, short color): piece(position, color) {
    pieceChar = (color > 0) ? 'r' : 'R';
    bitboardIndex = (color > 0) ? 7 : 1;
};

rook::rook(const rook& r) {
    this->position = r.position;
    this->pieceChar = r.pieceChar;
    this->color = r.color;
    this->moved = r.moved;
    this->bitboardIndex = bitboardIndex;
};

vector<vector<short>> rook::getLegalMoves(vector<vector<short>> positions) {
    return {{0, 0}};
};