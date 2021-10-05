#include "piece.h"
#include <list>
#include <vector>

using namespace std;
using namespace PIECE;

knight::knight(): piece() {
    pieceChar = 'N';
    color = 0;
    bitboardIndex = 3;
    mgPieceVal = 781;
    egPieceVal = 854;
};

knight::knight(vector<short> position, short color): piece(position, color) {
    pieceChar = (color > 0) ? 'n' : 'N';
    bitboardIndex = (color > 0) ? 9 : 3;
    mgPieceVal = 781;
    egPieceVal = 854;
};

knight::knight(const knight& n) {
    this->position = n.position;
    this->pieceChar = n.pieceChar;
    this->color = n.color;
    this->moved = n.moved;
    this->bitboardIndex = n.bitboardIndex;
    this->mgPieceVal = n.mgPieceVal;
    this->egPieceVal = n.egPieceVal;
    this->pinned = n.pinned;
};

list<vector<short>> knight::getLegalMoves(const vector<vector<piece*>>& positions) {
    return list<vector<short>>{};
};