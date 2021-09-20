#include "piece.h"
#include <map>
using namespace std;
using namespace PIECE;

char getPieceChar(pieceTypes p) {
    map<pieceTypes, char> m {
        { pieceTypes::P, 'P' },
        { pieceTypes::R, 'R' },
        { pieceTypes::N, 'N' },
        { pieceTypes::B, 'B' },
        { pieceTypes::K, 'K' },
        { pieceTypes::Q, 'Q' },
        { pieceTypes::p, 'p' },
        { pieceTypes::r, 'r' },
        { pieceTypes::n, 'n' },
        { pieceTypes::b, 'b' },
        { pieceTypes::k, 'k' },
        { pieceTypes::q, 'q' },
        { pieceTypes::empty, ' ' }
    };

    return m[p];
};

pieceTypes getPieceByChar(char p) {
    map<char, pieceTypes> m {
        { 'P', pieceTypes::P },
        { 'R', pieceTypes::R },
        { 'N', pieceTypes::N },
        { 'B', pieceTypes::B },
        { 'K', pieceTypes::K },
        { 'Q', pieceTypes::Q },
        { 'p', pieceTypes::p },
        { 'r', pieceTypes::r },
        { 'n', pieceTypes::n },
        { 'b', pieceTypes::b },
        { 'k', pieceTypes::k },
        { 'q', pieceTypes::q },
        { ' ', pieceTypes::empty }
    };

    return m[p];
};

piece* getPieceByShort(short pieceShort) {
    piece types[] = {
        piece({0,0}, 'P', 0),
        piece({0,0}, 'R', 0),
        piece({0,0}, 'N', 0),
        piece({0,0}, 'B', 0),
        piece({0,0}, 'K', 0),
        piece({0,0}, 'Q', 0),
        piece({0,0}, 'p', 1),
        piece({0,0}, 'r', 1),
        piece({0,0}, 'n', 1),
        piece({0,0}, 'b', 1),
        piece({0,0}, 'k', 1),
        piece({0,0}, 'q', 1),
        piece({0,0}, ' ', -1)
    };
    
    return new piece(types[pieceShort]);
};

bool isValidChar(char p) {
    map<char, pieceTypes> m {
        { 'P', pieceTypes::P },
        { 'R', pieceTypes::R },
        { 'N', pieceTypes::N },
        { 'B', pieceTypes::B },
        { 'K', pieceTypes::K },
        { 'Q', pieceTypes::Q },
        { 'p', pieceTypes::p },
        { 'r', pieceTypes::r },
        { 'n', pieceTypes::n },
        { 'b', pieceTypes::b },
        { 'k', pieceTypes::k },
        { 'q', pieceTypes::q }
    };

    return m.contains(p);
};

piece::piece() {
    position = {0,0};
    pieceChar = ' ';
    color = -1;
    moved = false;
    type = pieceTypes::empty;
};

piece::piece(vector<short>position, char pieceChar, short color) {
    this->position = position;
    this->pieceChar = pieceChar;
    this->color = color;
    moved = false;
    type = getPieceByChar(pieceChar);
};

piece::piece(const piece &p) {
    this->position = p.position;
    this->pieceChar = p.pieceChar;
    this->color = p.color;
    this->moved = p.moved;
    this->type = p.type;
};

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

pieceTypes piece::getPieceType() {
    return type;
};

void piece::move(vector<short>position) {
    this->position = position;
};

// redefine
vector<vector<short>> getLegalMoves(vector<vector<short>>) {
    return {{0,0}, {0,1}};
};