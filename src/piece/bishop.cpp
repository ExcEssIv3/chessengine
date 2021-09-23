#include "piece.h"
#include <vector>
#include <list>

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

list<short*> bishop::getLegalMoves(vector<vector<piece*>> positions) {
    list<short*> legalPositions{};
    short maxSteps = 0;
    short numSteps = 0;
    // up left
    if (7 - position[0] > position[1]) {
        maxSteps = position[1];
    } else {
        maxSteps = position[0];
    }

    for (short i = 1; i < maxSteps; i++) {
        // evaluates true if the next piece is a friendly piece
        if (positions[position[0] + i][position[1] - i]->getColor() == color) {
            break;
        }
        short newPosition[] = {position[0] + i, position[1] - i};
        legalPositions.push_back(newPosition);
        // evaluates true if the next piece is an enemy piece
        if (positions[position[0] + i][position[1] - i]->getColor() != -1) {
            break;
        }
    }
    // up right
    if (7 - position[0] > 7 - position[1]) {
        maxSteps = position[1];
    } else {
        maxSteps = position[0];
    }

    for (short i = 1; i < maxSteps; i++) {
        // evaluates true if the next piece is a friendly piece
        if (positions[position[0] + i][position[1] + i]->getColor() == color) {
            break;
        }
        short newPosition[] = {position[0] + i, position[1] - i};
        legalPositions.push_back(newPosition);
        // evaluates true if the next piece is an enemy piece
        if (positions[position[0] + i][position[1] + i]->getColor() != -1) {
            break;
        }
    }
    // down left
    if (position[0] > position[1]) {
        maxSteps = position[1];
    } else {
        maxSteps = position[0];
    }

    for (short i = 1; i < maxSteps; i++) {
        // evaluates true if the next piece is a friendly piece
        if (positions[position[0] - i][position[1] - i]->getColor() == color) {
            break;
        }
        short newPosition[] = {position[0] + i, position[1] - i};
        legalPositions.push_back(newPosition);
        // evaluates true if the next piece is an enemy piece
        if (positions[position[0] - i][position[1] - i]->getColor() != -1) {
            break;
        }
    }
    // down right
    if (position[0] > 7 - position[1]) {
        maxSteps = position[1];
    } else {
        maxSteps = position[0];
    }

    for (short i = 1; i < maxSteps; i++) {
        // evaluates true if the next piece is a friendly piece
        if (positions[position[0] - i][position[1] + i]->getColor() == color) {
            break;
        }
        short newPosition[] = {position[0] + i, position[1] - i};
        legalPositions.push_back(newPosition);
        // evaluates true if the next piece is an enemy piece
        if (positions[position[0] - i][position[1] + i]->getColor() != -1) {
            break;
        }
    }
    return legalPositions;
}