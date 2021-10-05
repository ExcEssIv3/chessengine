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

list<vector<short>> king::getLegalMoves(const vector<vector<piece*>>& positions) {
    list<vector<short>> legalPositions;
    bool upValid = position[0] < 7;
    bool downValid = position[0] > 0;
    bool rightValid = position[1] < 7;
    bool leftValid = position[1] > 0;
    if (upValid) {
        if(positions[static_cast<short>(position[0] + 1)][position[1]]->getColor() != color) {
            legalPositions.emplace_back(vector<short>({static_cast<short>(position[0] + 1), position[1]}));
        }
        if (leftValid && positions[static_cast<short>(position[0] + 1)][static_cast<short>(position[1] - 1)]->getColor() != color) {
            legalPositions.emplace_back(vector<short>({static_cast<short>(position[0] + 1), static_cast<short>(position[1] - 1)}));
        }
        if (rightValid && positions[static_cast<short>(position[0] + 1)][static_cast<short>(position[1] + 1)]->getColor() != color) {
            legalPositions.emplace_back(vector<short>({static_cast<short>(position[0] + 1), static_cast<short>(position[1] + 1)}));
        }
    }
    if (leftValid && positions[position[0]][static_cast<short>(position[1] - 1)]->getColor() != color) {
        legalPositions.emplace_back(vector<short>({static_cast<short>(position[0]), static_cast<short>(position[1] - 1)}));
    }
    if (downValid) {
        if(positions[static_cast<short>(position[0] - 1)][position[1]]->getColor() != color) {
            legalPositions.emplace_back(vector<short>({static_cast<short>(position[0] - 1), position[1]}));
        }
        if (leftValid && positions[static_cast<short>(position[0] - 1)][static_cast<short>(position[1] - 1)]->getColor() != color) {
            legalPositions.emplace_back(vector<short>({static_cast<short>(position[0] - 1), static_cast<short>(position[1] - 1)}));
        }
        if (rightValid && positions[static_cast<short>(position[0] - 1)][static_cast<short>(position[1] + 1)]->getColor() != color) {
            legalPositions.emplace_back(vector<short>({static_cast<short>(position[0] - 1), static_cast<short>(position[1] + 1)}));
        }
    }
    if (rightValid && positions[position[0]][static_cast<short>(position[1] + 1)]->getColor() != color) {
        legalPositions.emplace_back(vector<short>({position[0], static_cast<short>(position[1] + 1)}));
    }
    return legalPositions;
};