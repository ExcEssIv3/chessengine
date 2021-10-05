#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include <list>
using namespace std;

namespace PIECE {
    class piece {

        public:
            // default constructor is empty piece
            piece();
            piece(vector<short> position, short color);
            piece(const piece &p);
            ~piece();
            vector<short> getPosition();
            char getChar();
            short getColor();
            bool getMoved();
            short getMgPieceVal();
            short getEgPieceVal();
            short getBitboardIndex();
            bool getPinned();
            void flipPinned();
            void move(vector<short> position);
            // returns legal moves unaware of things like check
            virtual list<vector<short>> getLegalMoves(const vector<vector<piece*>>& positions);
        protected:
            vector<short> position;
            char pieceChar;
            // 0 for white, 1 for black, -1 for empty
            short color;
            bool moved;
            unsigned short mgPieceVal;
            unsigned short egPieceVal;
            short bitboardIndex;
            bool pinned;
    };

    class pawn: public piece {
        public:
            pawn();
            pawn(vector<short> position, short color);
            // might be possible to remove
            pawn(const pawn& p);
            list<vector<short>> getLegalMoves(const vector<vector<piece*>>& positions);
    };

    class rook: public piece {
        public:
            rook();
            rook(vector<short> position, short color);
            rook(const rook& r);
            list<vector<short>> getLegalMoves(const vector<vector<piece*>>& positions);
    };

    class knight: public piece {
        public:
            knight();
            knight(vector<short> position, short color);
            knight(const knight& k);
            list<vector<short>> getLegalMoves(const vector<vector<piece*>>& positions);
    };

    class bishop: public piece {
        public:
            bishop();
            bishop(vector<short> position, short color);
            bishop(const bishop& b);
            list<vector<short>> getLegalMoves(const vector<vector<piece*>>& positions);
    };

    class king: public piece {
        public:
            king();
            king(vector<short> position, short color);
            king(const king& k);
            list<vector<short>> getLegalMoves(const vector<vector<piece*>>& positions);
    };

    class queen: public piece {
        public:
            queen();
            queen(vector<short> position, short color);
            queen(const queen& q);
            list<vector<short>> getLegalMoves(const vector<vector<piece*>>& positions);
    };

    class empty: public piece {
        public:
            empty();
            empty(vector<short> position);
            empty(const empty& e);
            list<vector<short>> getLegalMoves(const vector<vector<piece*>>& positions);
    };

};

#endif