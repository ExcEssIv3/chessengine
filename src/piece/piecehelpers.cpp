#include "piece.h"
#include "piecehelpers.h"

using namespace PIECE;

piece* getPieceByShort(short p, vector<short> position) {
    switch(p) {
        case 0:
            return new pawn(position, 0);
        case 1:
            return new rook(position, 0);
        case 2:
            return new knight(position, 0);
        case 3:
            return new bishop(position, 0);
        case 4:
            return new king(position, 0);
        case 5:
            return new queen(position, 0);
        case 6:
            return new pawn(position, 1);
        case 7:
            return new rook(position, 1);
        case 8:
            return new knight(position, 1);
        case 9:
            return new bishop(position, 1);
        case 10:
            return new king(position, 1);
        case 11:
            return new queen(position, 1);
        default:
            return nullptr;
    }
};

piece* getPieceByChar(char p, vector<short> position) {
    switch(p) {
        case 'P':
            return new pawn(position, 0);
        case 'R':
            return new rook(position, 0);
        case 'N':
            return new knight(position, 0);
        case 'B':
            return new bishop(position, 0);
        case 'K':
            return new king(position, 0);
        case 'Q':
            return new queen(position, 0);
        case 'p':
            return new pawn(position, 1);
        case 'r':
            return new rook(position, 1);
        case 'n':
            return new knight(position, 1);
        case 'b':
            return new bishop(position, 1);
        case 'k':
            return new king(position, 1);
        case 'q':
            return new queen(position, 1);
        default:
            return nullptr;
    }
};