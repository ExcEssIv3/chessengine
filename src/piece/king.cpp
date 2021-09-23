#include "piece.h"
#include <list>
#include <vector>

using namespace std;
using namespace PIECE;

king::king() {
    pieceChar = 'K';
    color = 0;
    bitboardIndex = 4;
    mgPieceVal, egPieceVal = 65535;
};

king::king(vector<short> position, short color): piece(position, color) {
    pieceChar = (color > 0) ? 'k' : 'K';
    bitboardIndex = (color > 0) ? 10 : 4;
    mgPieceVal, egPieceVal = 65535;
};

king::king(const king& k) {
    this->position = k.position;
    this->pieceChar = k.pieceChar;
    this->color = k.color;
    this->moved = k.moved;
    this->bitboardIndex = k.bitboardIndex;
    this->mgPieceVal = k.mgPieceVal;
    this->egPieceVal = k.egPieceVal;
};

list<short*> king::getLegalMoves(vector<vector<piece*>> positions) {
    return list<short*>{};
};