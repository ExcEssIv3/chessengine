#include "piece.h"
#include <vector>

using namespace std;
using namespace PIECE;

king::king() {
    pieceChar = 'K';
    color = 0;
    bitboardIndex = 4;
};

king::king(vector<short> position, short color): piece(position, color) {
    pieceChar = (color > 0) ? 'k' : 'K';
    bitboardIndex = (color > 0) ? 10 : 4;
};

king::king(const king& k) {
    this->position = k.position;
    this->pieceChar = k.pieceChar;
    this->color = k.color;
    this->moved = k.moved;
    this->bitboardIndex = bitboardIndex;
};

vector<vector<short>> king::getLegalMoves(vector<vector<short>> positions) {
    return {{0, 0}};
};