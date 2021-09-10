#include "board.h"
#include <iostream>
#include <tuple>
#include <map>
#include <sstream>
#include <string>

using namespace std;
using namespace BOARD;

board::board() {
    fenString = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
    arrayRepresentation = mailbox();
    bitRepresentation = arrayRepresentation.getBitboard();
}

// throws exception if invalid fenString
board::board(string fenString) {
    this->fenString = fenString;


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

    vector<vector<pieceTypes>> positions(8, vector<pieceTypes>(8, pieceTypes::empty));

    short indices[] = {0, 0};
    short i = 0;
    short loc = 0;
    
    while (i < 64) {
        if (m.contains(fenString[loc])) {
            positions[indices[0]][indices[1]] = m[fenString[loc]];
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
    if (ss.eof) throw "FenString reached end early";
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
    if (ss.eof) throw "FenString reached end early";
    ss >> nextEval;
    if (!nextEval.compare("-")) {
        // -97 shifts ascii code over to 0 for a, 1 for b etc.
        enPassant = make_tuple(nextEval[0] - 97, nextEval[1]);
    } else {
        enPassant = make_tuple(8, 8);
    }
    nextEval.clear();

    // shift into moveclocks

    if (ss.eof) throw "FenString reached end early";
    ss >> halfmoveClock;
    if (ss.eof) throw "FenString reached end early";
    ss >> fullmoveClock;
};

