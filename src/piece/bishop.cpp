#include "piece.h"
#include <vector>

using namespace std;
using namespace PIECE;

bishop::bishop() {
    pieceChar = 'B';
    color = 0;
    bitboardIndex = 2;
    mgPieceVal = 825;
    egPieceVal = 915;
};

bishop::bishop(vector<short> position, short color): piece(position, color) {
    pieceChar = (color > 0) ? 'b' : 'B';
    bitboardIndex = (color > 0) ? 8 : 2;
    mgPieceVal = 825;
    egPieceVal = 915;
};

bishop::bishop(const bishop& b) {
    this->position = b.position;
    this->pieceChar = b.pieceChar;
    this->color = b.color;
    this->moved = b.moved;
    this->bitboardIndex = b.bitboardIndex;
    this->mgPieceVal = b.mgPieceVal;
    this->egPieceVal = b.egPieceVal;
};

vector<vector<short>> bishop::getLegalMoves(vector<vector<short>> positions) {
    return {{0,0}};
}