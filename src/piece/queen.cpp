#include "piece.h"
#include <list>
#include <vector>

using namespace std;
using namespace PIECE;

queen::queen(): piece() {
    pieceChar = 'Q';
    color = 0;
    bitboardIndex = 5;
    mgPieceVal = 2538;
    egPieceVal = 2682;
    pieceType = piece_enum::QUEEN;
};

queen::queen(vector<short> position, short color): piece(position, color) {
    pieceChar = (color > 0) ? 'q' : 'Q';
    bitboardIndex = (color > 0) ? 11 : 5;
    mgPieceVal = 2538;
    egPieceVal = 2682;
    pieceType = piece_enum::QUEEN;
};

queen::queen(const queen& q) {
    this->position = q.position;
    this->pieceChar = q.pieceChar;
    this->color = q.color;
    this->moved = q.moved;
    this->bitboardIndex = q.bitboardIndex;
    this->mgPieceVal = q.mgPieceVal;
    this->egPieceVal = q.egPieceVal;
    this->pinned = q.pinned;
    this->pieceType = q.pieceType;
};

list<vector<short>> queen::getLegalMoves(const vector<vector<piece*>>& positions) {
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
    maxDistance = (distDown < distRight) ? distDown : distRight;
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