#include "piece.h"
#include <list>
#include <vector>

using namespace std;
using namespace PIECE;

rook::rook(): piece() {
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
    this->pinned = r.pinned;
};

list<vector<short>> rook::getLegalMoves(const vector<vector<piece*>>& positions) {
    list<vector<short>> legalPositions;
    short distUp = 7 - position[0];
    short distLeft = position[1];
    short distDown = position[0];
    short distRight = 7 - position[1];

    short oppositeColor = (color == 0) ? 1 : 0;

    // up
    for (int i = 1; i <= distUp; i++) {
        if (positions[position[0] + i][position[1]]->getColor() == color) {
            break;
        }
        legalPositions.emplace_back(vector<short>({static_cast<short>(position[0] + i), position[1]}));
        if (positions[position[0] + i][position[1]]->getColor() == oppositeColor) {
            break;
        }
    }

    // down
    for (int i = 1; i <= distDown; i++) {
        if (positions[position[0] - i][position[1]]->getColor() == color) {
            break;
        }
        legalPositions.emplace_back(vector<short>({static_cast<short>(position[0] - i), position[1]}));
        if (positions[position[0] - i][position[1]]->getColor() == oppositeColor) {
            break;
        }
    }

    // left
    for (int i = 1; i <= distLeft; i++) {
        if (positions[position[0]][position[1] - i]->getColor() == color) {
            break;
        }
        legalPositions.emplace_back(vector<short>({position[0], static_cast<short>(position[1] - i)}));
        if (positions[position[0]][position[1] - i]->getColor() == oppositeColor) {
            break;
        }
    }

    // right
    for (int i = 1; i <= distRight; i++) {
        if (positions[position[0]][position[1] + i]->getColor() == color) {
            break;
        }
        legalPositions.emplace_back(vector<short>({position[0], static_cast<short>(position[1] + i)}));
        if (positions[position[0]][position[1] + i]->getColor() == oppositeColor) {
            break;
        }
    }

    return legalPositions;
};