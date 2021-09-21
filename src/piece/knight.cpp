#include "piece.h"
#include <vector>

using namespace std;
using namespace PIECE;

knight::knight() {
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
};

vector<vector<short>> knight::getLegalMoves(vector<vector<short>> positions) {
    return {{0, 0}};
};