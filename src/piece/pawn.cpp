#include "piece.h"
#include <list>
#include <vector>

using namespace std;
using namespace PIECE;

pawn::pawn(): piece() {
    pieceChar = 'P';
    color = 0;
    bitboardIndex = 0;
    mgPieceVal = 128;
    egPieceVal = 213;
    pieceType = piece_enum::PAWN;
};

pawn::pawn(vector<short> position, short color): piece(position, color) {
    pieceChar = (color > 0) ? 'p' : 'P';
    bitboardIndex = (color > 0) ? 6 : 0;
    mgPieceVal = 128;
    egPieceVal = 213;
    pieceType = piece_enum::PAWN;
};

pawn::pawn(const pawn& p) {
    this->position = p.position;
    this->pieceChar = p.pieceChar;
    this->color = p.color;
    this->moved = p.moved;
    this->bitboardIndex = p.bitboardIndex;
    this->mgPieceVal = p.mgPieceVal;
    this->egPieceVal = p.egPieceVal;
    this->pinned = p.pinned;
    this->pieceType = p.pieceType;
};

list<vector<short>> pawn::getLegalMoves(const vector<vector<piece*>>& positions) {
    list<vector<short>> legalMoves;
    short oppositeColor = (color == 0) ? 1 : 0;

    if (color == 0 && position[0] < 7) {
        if (positions[position[0] + 1][position[1]]->getColor() == -1) {
            legalMoves.emplace_back(vector<short>({static_cast<short>(position[0] + 1), position[1]}));
            if (position[0] < 6 && !moved && positions[position[0] + 2][position[1]]->getColor() == -1) {
                legalMoves.emplace_back(vector<short>({static_cast<short>(position[0] + 2), position[1]}));
            }
        }
        if (position[1] < 7) {
            if (positions[position[0] + 1][position[1] + 1]->getColor() == oppositeColor) {
                legalMoves.emplace_back(vector<short>({static_cast<short>(position[0] + 1), static_cast<short>(position[1] + 1)}));
            }
        }
        if (position[1] > 0) {
            if (positions[position[0] + 1][position[1] - 1]->getColor() == oppositeColor) {
                legalMoves.emplace_back(vector<short>({static_cast<short>(position[0] + 1), static_cast<short>(position[1] - 1)}));
            }
        }
    } else if (position[0] > 0) {
        if (positions[position[0] - 1][position[1]]->getColor() == -1) {
            legalMoves.emplace_back(vector<short>({static_cast<short>(position[0] - 1), position[1]}));
            if (position[0] > 1 && !moved && positions[position[0] - 2][position[1]]->getColor() == -1) {
                legalMoves.emplace_back(vector<short>({static_cast<short>(position[0] - 2), position[1]}));
            }
        }
        if (position[1] < 7) {
            if (positions[position[0] - 1][position[1] + 1]->getColor() == oppositeColor) {
                legalMoves.emplace_back(vector<short>({static_cast<short>(position[0] - 1), static_cast<short>(position[1] + 1)}));
            }
        }
        if (position[1] > 0) {
            if (positions[position[0] - 1][position[1] - 1]->getColor() == oppositeColor) {
                legalMoves.emplace_back(vector<short>({static_cast<short>(position[0] - 1), static_cast<short>(position[1] - 1)}));
            }
        }
    }
    return legalMoves;
};