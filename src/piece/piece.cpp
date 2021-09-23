#include "piece.h"
#include <list>
#include <vector>

using namespace std;
using namespace PIECE;

piece::piece() {
    position = {0,0};
    moved = false;
};

piece::piece(vector<short> position, short color) {
    this->position = position;
    this->color = color;
    moved = false;
};

piece::piece(const piece &p) {
    this->position = p.position;
    this->pieceChar = p.pieceChar;
    this->color = p.color;
    this->moved = p.moved;
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

// redefine
list<short*> piece::getLegalMoves(vector<vector<piece*>> positions) {
    return list<short*>{};
};