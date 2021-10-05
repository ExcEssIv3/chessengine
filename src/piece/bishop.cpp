#include "piece.h"
#include <iostream>
#include <vector>
#include <list>

using namespace std;
using namespace PIECE;

bishop::bishop(): piece() {
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
    this->pinned = b.pinned;
};

list<vector<short>> bishop::getLegalMoves(const vector<vector<piece*>>& positions) {
    list<vector<short>> legalPositions;
    short distUp = 7 - position[0];
    short distLeft = position[1];
    short distDown = position[0];
    short distRight = 7 - position[1];

    short maxDistance = 0;
    short oppositeColor = (color == 0) ? 1 : 0;

    // up left
    maxDistance = (distUp < distLeft) ? distUp : distLeft;
    for (short i = 1; i <= maxDistance; i++) {
        if (positions[position[0] + i][position[1] - i]->getColor() == color) {
            break;
        }
        legalPositions.emplace_back(vector<short>({static_cast<short>(position[0] + i), static_cast<short>(position[1] - i)}));
        if (positions[position[0] + i][position[1] - i]->getColor() == oppositeColor) {
            break;
        }
    }

    // up right
    maxDistance = (distUp < distRight) ? distUp : distRight;
    for (short i = 1; i <= maxDistance; i++) {
        if (positions[position[0] + i][position[1] + i]->getColor() == color) {
            break;
        }
        legalPositions.emplace_back(vector<short>({static_cast<short>(position[0] + i), static_cast<short>(position[1] + i)}));
        if (positions[position[0] + i][position[1] + i]->getColor() == oppositeColor) {
            break;
        }
    }

    // down right
    maxDistance = (distDown < distRight) ? distUp : distRight;
    for (short i = 1; i <= maxDistance; i++) {
        if (positions[position[0] - i][position[1] + i]->getColor() == color) {
            break;
        }
        legalPositions.emplace_back(vector<short>({static_cast<short>(position[0] - i), static_cast<short>(position[1] + i)}));
        if (positions[position[0] - i][position[1] + i]->getColor() == oppositeColor) {
            break;
        }
    }

    // down left
    maxDistance = (distDown < distLeft) ? distDown : distLeft;
    for (short i = 1; i <= maxDistance; i++) {
        if (positions[position[0] - i][position[1] - i]->getColor() == color) {
            break;
        }
        legalPositions.emplace_back(vector<short>({static_cast<short>(position[0] - i), static_cast<short>(position[1] - i)}));
        if (positions[position[0] - i][position[1] - i]->getColor() == oppositeColor) {
            break;
        }
    }

    return legalPositions;
}