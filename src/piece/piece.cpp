#include "piece.h"
#include <list>
#include <vector>

using namespace std;
using namespace PIECE;

piece::piece() {
    position = {0,0};
    moved = false;
    pinned = false;
};

piece::piece(vector<short> position, short color) {
    this->position = position;
    this->color = color;
    moved = false;
    pinned = false;
};

piece::piece(const piece &p) {
    this->position = p.position;
    this->pieceChar = p.pieceChar;
    this->color = p.color;
    this->moved = p.moved;
    this->pinned = p.pinned;
};

piece::~piece() {};

vector<short> piece::getPosition() {
    return position;
};

char piece::getChar() {
    return pieceChar;
};

short piece::getColor() {
    return color;
};

bool piece::getMoved() {
    return moved;
};

short piece::getBitboardIndex() {
    return bitboardIndex;
};

void piece::move(vector<short>position) {
    this->position = position;
};

short piece::getMgPieceVal() {
    return mgPieceVal;
};

short piece::getEgPieceVal() {
    return egPieceVal;
}

bool piece::getPinned() {
    return pinned;
}

void piece::flipPinned() {
    pinned = !pinned;
}

piece_enum piece::getPieceType() {
    return pieceType;
}

// redefine
list<vector<short>> piece::getLegalMoves(const vector<vector<piece*>>& positions) {
    return list<vector<short>>{};
};