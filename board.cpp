#include "board.h"
#include <iostream>
#include <tuple>
#include <map>
#include <sstream>
#include <string>

using namespace std;
using namespace BOARD;

char getPieceChar(pieceTypes piece) {
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
        { pieceTypes::q, 'k' },
        { pieceTypes::empty, ' ' }
    };

    return m[piece];
}

pieceTypes getPieceByChar(char piece) {
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

    return m[piece];
}

bool isValidChar(char piece) {
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

    return m.contains(piece);
}

board::board() {
    fenString = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    arrayRepresentation = mailbox();
    bitRepresentation = arrayRepresentation.getBitboard();
}

// throws exception if invalid fenString
board::board(string fenString) {
    this->fenString = fenString;
    setFenString(fenString);
};

bool board::getNext() {
    return next;
};

void board::flipNext() {
    next = !next;
};

vector<bool> board::getCastling() {
    return castling;
};

void board::setCastling(vector<bool> castling) {
    this->castling = castling;
};

tuple<short, short> board::getEnPassant() {
    return enPassant;
};

short board::getHalfmoveClock() {
    return halfmoveClock;
};

void board::incrementHalfmoveClock() {
    halfmoveClock++;
};

void board::resetHalfmoveClock() {
    halfmoveClock = 0;
};

int board::getFullmoveClock() {
    return fullmoveClock;
};

void board::incrementFullmoveClock() {
    fullmoveClock++;
};

string board::getFenString() {
    return fenString;
};

// throws exceptions if invalid fenstring
void board::setFenString(string newString) {
    

    vector<vector<pieceTypes>> positions(8, vector<pieceTypes>(8, pieceTypes::empty));

    short indices[] = {0, 0};
    short i = 0;
    short loc = 0;
    
    while (i < 64) {
        if (isValidChar(fenString[loc])) {
            positions[indices[0]][indices[1]] = pieceTypes(fenString[loc]);
            indices[0]++;
            i++;
        } else if (isdigit(fenString[loc])) {
            indices[0] += fenString[loc];
            i += fenString[loc];
        } else if (fenString[loc] == '/') {
            loc++;
            indices[0] = 0;
            indices[1]++;
        } else {
            string exception = "Invalid character in fenString: " + fenString[loc];
            throw exception;
        }
    }

    arrayRepresentation = mailbox(positions);
    bitRepresentation = arrayRepresentation.getBitboard();

    stringstream ss = stringstream();
    ss << fenString.substr(loc);

    string nextEval;

    // check whose turn is next
    ss >> nextEval;
    next = (nextEval.compare("b"));
    nextEval.clear();

    // check castling availability
    if (ss.eof()) throw "FenString reached end early";
    ss >> nextEval;
    if (nextEval.compare("-")) {
        castling = { false, false, false, false };
    } else {
        if (nextEval.find('K') > -1) {
            castling[0] = true;
        }
        if (nextEval.find('Q') > -1) {
            castling[1] = true;
        }
        if (nextEval.find('k') > -1) {
            castling[2] = true;
        }
        if (nextEval.find('q') > -1) {
            castling[3] = true;
        }
    }
    nextEval.clear();

    // check en passant
    if (ss.eof()) throw "FenString reached end early";
    ss >> nextEval;
    if (!nextEval.compare("-")) {
        // -97 shifts ascii code over to 0 for a, 1 for b etc.
        enPassant = make_tuple(nextEval[0] - 97, nextEval[1]);
    } else {
        enPassant = make_tuple(8, 8);
    }
    nextEval.clear();

    // shift into moveclocks

    if (ss.eof()) throw "FenString reached end early";
    ss >> halfmoveClock;
    if (ss.eof()) throw "FenString reached end early";
    ss >> fullmoveClock;
};

// TODO: set this function after doing real oop
void board::resetBoard() {
    return;
};

void board::updateFenString() {
    string newFen(92, ' ');
    short stringIndex = 0;;
    for (int i = 0; i < 8; i++) {
        int numEmptySpaces = 0;
        for (int j = 0; j < 8; j++) {
            if (arrayRepresentation.getBoard()[i][j] == pieceTypes::empty) {
                numEmptySpaces++;
            } else {
                if (numEmptySpaces > 0) {
                    newFen[stringIndex] = numEmptySpaces;
                    numEmptySpaces = 0;
                    stringIndex++;
                }
                newFen[stringIndex] = getPieceChar(arrayRepresentation.getBoard()[i][j]);
            }
        }
        if (numEmptySpaces > 0) {
            newFen[stringIndex] = numEmptySpaces;
            numEmptySpaces = 0;
            stringIndex++;
        }
        newFen[stringIndex] = '/';
        stringIndex = 0;
    }
    
    // marking next move
    // shifting spot one
    stringIndex++;
    newFen[stringIndex] = (next) ? 'b' : 'w';
    stringIndex++;

    // marking castling
    stringIndex++;
    if (!(castling[0] || castling[1] || castling[2] || castling[3])) {
        newFen[stringIndex] = '-';
        stringIndex++;
    } else {
        if (castling[0]) {
            newFen[stringIndex] = 'K';
            stringIndex++;
        }
        if (castling[1]) {
            newFen[stringIndex] = 'Q';
            stringIndex++;
        }
        if (castling[2]) {
            newFen[stringIndex] = 'k';
            stringIndex++;
        }
        if (castling[3]) {
            newFen[stringIndex] = 'q';
            stringIndex++;
        }
    }

    // en passant
    stringIndex++;
    if (get<0>(enPassant) == 8 && get<1>(enPassant) == 8) {
        newFen[stringIndex] = '-';
        stringIndex++;
    } else {
        newFen[stringIndex] = static_cast<char>(get<0>(enPassant) + 97);
        stringIndex++;
        newFen[stringIndex] = get<1>(enPassant);
        stringIndex++;
    }

    // might be a runtime error
    newFen.substr(0, stringIndex);

    // clocks
    stringstream ss = stringstream();
    ss << halfmoveClock << " " << fullmoveClock;
    newFen += ss.str();


}