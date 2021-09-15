#include "piece.h"
#include <map>
using namespace std;

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

pieceTypes getPieceByShort(short piece) {
    pieceTypes types[] = {
        pieceTypes::P,
        pieceTypes::R,
        pieceTypes::N,
        pieceTypes::B,
        pieceTypes::K,
        pieceTypes::Q,
        pieceTypes::p,
        pieceTypes::r,
        pieceTypes::n,
        pieceTypes::b,
        pieceTypes::k,
        pieceTypes::q,
        pieceTypes::empty
    };
    return types[piece];
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