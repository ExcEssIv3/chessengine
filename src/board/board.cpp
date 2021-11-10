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

    updateWhiteThreatened();
    updateBlackThreatened();
};

// throws exception if invalid fenString
board::board(string fenString) {
    this->fenString = fenString;
    setFenString(fenString);

    updateWhiteThreatened();
    updateBlackThreatened();
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
        enPassant = { static_cast<short>(nextEval[1] - '0' - 1), static_cast<short>((nextEval[0]) - 97)  };
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

void board::printMailbox(bool showThreatened, short color) {
    if (showThreatened && color == -1) {
        throw "Cannot show threatened for empty color";
    } else if (showThreatened && color == 0) {
        arrayRepresentation.printBoard(showThreatened, whiteThreatened);
    } else if (showThreatened && color == 1) {
        arrayRepresentation.printBoard(showThreatened, blackThreatened);
    } else {
        arrayRepresentation.printBoard(showThreatened, vector<vector<bool>>());
    }
};

void board::printBitboard() {
    bitRepresentation.printBitboard();
};

void board::movePiece(vector<short> startIndex, vector<short> finalIndex) {
    short index = arrayRepresentation.getPieceAtIndex(startIndex)->getBitboardIndex();
    bool isEnPassant = false;
    bool isCastle = false;

    // en passant

    if (arrayRepresentation.getPieceAtIndex(startIndex)->getPieceType() == piece_enum::PAWN) {
        if (finalIndex == enPassant) {
            isEnPassant = true;
        }

        if (abs(startIndex[0] - finalIndex[0]) == 2) {
            if (startIndex[0] - finalIndex[0] > 0) {
                enPassant = {static_cast<short>(finalIndex[0] + 1), finalIndex[1]};
            } else {
                enPassant = {static_cast<short>(finalIndex[0] - 1), finalIndex[1]};
            }
        } else {
            enPassant = {8, 8};
        }
    } else {
        enPassant = {8, 8};
    }

    // castle 

    if (arrayRepresentation.getPieceAtIndex(startIndex)->getPieceType() == piece_enum::KING && abs(finalIndex[1] - startIndex[1]) > 1) {
        isCastle = true;
    }
    arrayRepresentation.movePiece(startIndex, finalIndex, isEnPassant, isCastle);
    bitRepresentation.movePiece(
        index,
        startIndex[0] * 8 + startIndex[1],
        finalIndex[0] * 8 + finalIndex[1]
    );
    if (arrayRepresentation.getPieceAtIndex(finalIndex)->getColor() == 0) {
        updateBlackThreatened();
    } else {
        updateWhiteThreatened();
    }
};

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

piece* board::getPieceAtIndex(vector<short> index) {
    return arrayRepresentation.getPieceAtIndex(index);
};

mailbox board::getMailbox() {
    return arrayRepresentation;
};

list<vector<short>> board::getLegalMovesAtIndex(const vector<short>& index) {
    if (arrayRepresentation.getBoard()[index[0]][index[1]]->getColor() == 0) {
        return arrayRepresentation.getLegalMovesAtIndex(index, enPassant, whiteThreatened);
    } else if (arrayRepresentation.getBoard()[index[0]][index[1]]->getColor() == 1) {
        return arrayRepresentation.getLegalMovesAtIndex(index, enPassant, blackThreatened);
    } else {
        // if color is -1, then it's an empty piece, no legal moves
        return list<vector<short>>({});
    }
};

vector<vector<bool>> board::getWhiteThreatened() {
    return whiteThreatened;
};

vector<vector<bool>> board::getBlackThreatened() {
    return blackThreatened;
};

void board::updateWhiteThreatened() {
    for (short i = 0; i < 8; i++) {
        for (short j = 0; j < 8; j++) {
            if (this->getPieceAtIndex(vector<short>({i, j}))->getColor() == 1) {
                list<vector<short>> moves = this->getLegalMovesAtIndex(vector<short>({i, j}));
                if (this->getPieceAtIndex(vector<short>({i, j}))->getPieceType() == piece_enum::PAWN) {
                    for (list<vector<short>>::iterator it = moves.begin(); it != moves.end(); it++) {
                        if (abs((*it)[1] - j) == 1 && !this->whiteThreatened[(*it)[0]][(*it)[1]]) {
                            this->whiteThreatened[(*it)[0]][(*it)[1]] = 1;
                        }
                    }
                } else {
                    for (list<vector<short>>::iterator it = moves.begin(); it != moves.end(); it++) {
                        if (!this->whiteThreatened[(*it)[0]][(*it)[1]]) {
                            this->whiteThreatened[(*it)[0]][(*it)[1]] = 1;
                        }
                    }
                }
            }
        }
    }
}

void board::updateBlackThreatened() {
    for (short i = 0; i < 8; i++) {
        for (short j = 0; j < 8; j++) {
            if (this->getPieceAtIndex(vector<short>({i, j}))->getColor() == 0) {
                list<vector<short>> moves = this->getLegalMovesAtIndex(vector<short>({i, j}));
                if (this->getPieceAtIndex(vector<short>({i, j}))->getPieceType() == piece_enum::PAWN) {
                    for (list<vector<short>>::iterator it = moves.begin(); it != moves.end(); it++) {
                        if (abs((*it)[1] - j) == 1 && !this->blackThreatened[(*it)[0]][(*it)[1]]) {
                            this->blackThreatened[(*it)[0]][(*it)[1]] = 1;
                        }
                    }
                } else {
                    for (list<vector<short>>::iterator it = moves.begin(); it != moves.end(); it++) {
                        if (!this->blackThreatened[(*it)[0]][(*it)[1]]) {
                            this->blackThreatened[(*it)[0]][(*it)[1]] = 1;
                        }
                    }
                }
            }
        }
    }
}