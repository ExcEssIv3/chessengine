#ifndef PIECE_H
#define PIECE_H

#include <vector>
using namespace std;

namespace PIECE {

    enum class pieceTypes {
        P,
        R,
        N,
        B,
        K,
        Q,
        p,
        r,
        n,
        b,
        k,
        q,
        empty
    };

    char getPieceChar(pieceTypes piece);
    pieceTypes getPieceByChar(char piece);
    // returns true if char represents a piece, false if invalid or empty
    bool isValidChar(char piece);
    class piece {

        public:
            // default constructor is empty
            piece();
            piece(vector<short> position, char pieceChar, short color);
            piece(const piece &p);
            vector<short> getPosition();
            char getChar();
            short getColor();
            bool getMoved();
            pieceTypes getPieceType();
            void move(vector<short> position);
            vector<vector<short>> getLegalMoves(vector<vector<short>> positions);
            // bool operator==(const pieceTypes& p);
            // bool operator!=(const pieceTypes& p);
        private:
            vector<short> position;
            char pieceChar;
            // 0 for white, 1 for black, -1 for empty
            short color;
            bool moved;
            pieceTypes type;
    };

    piece* getPieceByShort(short p);

};

#endif