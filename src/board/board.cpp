#include "board.h"
#include "../piece/piece.h"
#include "../piece/piecehelpers.h"
#include <sstream>
#include <string>
#include <regex>

using namespace std;
using namespace BOARD;
using namespace PIECE;

// used for checking if is a piece character
regex validator("P|p|R|r|N|n|B|b|K|k|Q|q");

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

board::~board() {};

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

vector<short> board::getEnPassant() {
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
    updateFenString();
    return fenString;
};

// throws exceptions if invalid fenstring
void board::setFenString(string newString) {
    
    vector<vector<piece*>> positions(8, vector<piece*>(8, nullptr));

    short indices[] = {7, 0};
    short i = 0;
    short loc = 0;
    
    while (i < 64) {
        if (regex_match(string({fenString[loc]}), validator)) {
            positions[indices[0]][indices[1]] = getPieceByChar(fenString[loc], {indices[0],indices[1]});
            indices[1]++;
            i++;
            loc++;
        } else if (isdigit(fenString[loc])) {
            for (int j = 0; j < fenString[loc] - '0'; j++) {
                positions[indices[0]][indices[1] + j] = new PIECE::empty({indices[0], static_cast<short>(indices[1] + j)});
            }
            indices[1] += fenString[loc] - '0';
            i += fenString[loc] - '0';
            loc++;
        } else if (fenString[loc] == '/') {
            loc++;
            indices[1] = 0;
            indices[0]--;
        } else {
            string exception = "Invalid character in fenString: " + fenString[loc];
            throw exception;
        }
        // if (indices[0] < 0 || indices[1] >= 8) {
        //     cout << "0: " << indices[0] << " 1: " << indices[1] << endl;
        // }
    }

    arrayRepresentation = mailbox(positions);
    bitRepresentation = arrayRepresentation.getBitboard();

    stringstream ss = stringstream();
    ss << fenString.substr(loc);

    string nextEval;

    // check whose turn is next
    ss >> nextEval;
    next = !(nextEval.compare("b"));
    nextEval.clear();

    // check castling availability
    if (ss.eof()) throw "FenString reached end early";
    ss >> nextEval;
    if (!nextEval.compare("-")) {
        castling = { false, false, false, false };
    } else {
        if (nextEval.find('K') >= 0) {
            castling[0] = true;
        }
        if (nextEval.find('Q') >= 0) {
            castling[1] = true;
        }
        if (nextEval.find('k') >= 0) {
            castling[2] = true;
        }
        if (nextEval.find('q') >= 0) {
            castling[3] = true;
        }
    }
    nextEval.clear();

    // check en passant
    if (ss.eof()) throw "FenString reached end early";
    ss >> nextEval;
    if (nextEval.compare("-")) {
        // -97 shifts ascii code over to 0 for a, 1 for b etc.
        enPassant = { static_cast<short>((nextEval[0]) - 97), static_cast<short>(nextEval[1] - '0' - 1) };
    } else {
        enPassant = {8, 8};
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

void board::printMailbox() {
    arrayRepresentation.printBoard();
}

void board::printBitboard() {
    bitRepresentation.printBitboard();
}

void board::movePiece(vector<short> startIndex, vector<short> finalIndex) {
    short index = arrayRepresentation.getPieceAtIndex(startIndex)->getBitboardIndex();
    arrayRepresentation.movePiece(startIndex, finalIndex);
    bitRepresentation.movePiece(
        index,
        startIndex[0] * 8 + startIndex[1],
        finalIndex[0] * 8 + finalIndex[1]
    );
}

void board::updateFenString() {
    stringstream newFen = stringstream();
    for (int i = 7; i > -1; i--) {
        int numEmptySpaces = 0;
        for (int j = 0; j < 8; j++) {
            if (arrayRepresentation.getBoard()[i][j]->getColor() == -1) {
                numEmptySpaces++;
            } else {
                if (numEmptySpaces > 0) {
                    newFen << numEmptySpaces;
                    numEmptySpaces = 0;
                }
                newFen << arrayRepresentation.getBoard()[i][j]->getChar();
            }
        }
        if (numEmptySpaces > 0) {
            newFen << numEmptySpaces;
            numEmptySpaces = 0;
        }
        if (i > 0) {
            newFen << '/';
        }
    }
    
    // marking next move
    if (next) {
        newFen << " b ";
    } else {
        newFen << " w ";
    }

    // marking castling
    if (!(castling[0] || castling[1] || castling[2] || castling[3])) {
        newFen << '-';
    } else {
        if (castling[0]) {
            newFen << 'K';
        }
        if (castling[1]) {
            newFen << 'Q';
        }
        if (castling[2]) {
            newFen << 'k';
        }
        if (castling[3]) {
            newFen << 'q';
        }
    }

    // en passant
    if (enPassant[0] == 8 && enPassant[1] == 8) {
        newFen << " - ";
    } else {
        newFen << " " << static_cast<char>(enPassant[0] + 97);
        newFen << enPassant[1] << " ";
    }

    // clocks
    newFen << halfmoveClock << " " << fullmoveClock;
    fenString = newFen.str();
};