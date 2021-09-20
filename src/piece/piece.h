#ifndef PIECE_H
#define PIECE_H

#include <vector>
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
            void move(vector<short> position);
            // returns legal moves unaware of things like check
            vector<vector<short>> getLegalMoves(vector<vector<short>> positions);
        protected:
            vector<short> position;
            char pieceChar;
            // 0 for white, 1 for black, -1 for empty
            short color;
            bool moved;
            unsigned short mgPieceVal;
            unsigned short egPieceVal;
            short bitboardIndex;
            // pieceTypes type;
    };

    class pawn: public piece {
        public:
            pawn();
            pawn(vector<short> position, short color);
            // might be possible to remove
            pawn(const pawn& p);
            vector<vector<short>> getLegalMoves(vector<vector<short>> positions);
        private:
            unsigned short mgPieceVal = 128;
            unsigned short egPieceVal = 213;
    };

    class rook: public piece {
        public:
            rook();
            rook(vector<short> position, short color);
            rook(const rook& r);
            vector<vector<short>> getLegalMoves(vector<vector<short>> positions);
        private:
            unsigned short mgPieceVal = 1276;
            unsigned short egPieceVal = 1380;
    };

    class knight: public piece {
        public:
            knight();
            knight(vector<short> position, short color);
            knight(const knight& k);
            vector<vector<short>> getLegalMoves(vector<vector<short>> positions);
        private:
            unsigned short mgPieceVal = 781;
            unsigned short egPieceVal = 854;
    };

    class bishop: public piece {
        public:
            bishop();
            bishop(vector<short> position, short color);
            bishop(const bishop& b);
            vector<vector<short>> getLegalMoves(vector<vector<short>> positions);
        private:
            unsigned short mgPieceVal = 825;  
            unsigned short egPieceVal = 915;  
    };

    class king: public piece {
        public:
            king();
            king(vector<short> position, short color);
            king(const king& k);
            vector<vector<short>> getLegalMoves(vector<vector<short>> positions);
        private:
            unsigned short mgPieceVal, egPieceVal = 65535;
    };

    class queen: public piece {
        public:
            queen();
            queen(vector<short> position, short color);
            queen(const queen& q);
            vector<vector<short>> getLegalMoves(vector<vector<short>> positions);
        private:
            unsigned short mgPieceVal = 2538;
            unsigned short egPieceVal = 2682;
    };

    class empty: public piece {
        public:
            empty();
            empty(vector<short> position);
            empty(const empty& e);
        private:
            vector<short> position = {};
            char pieceChar = ' ';
            short color = -1;
            bool moved = false;
            unsigned short mgPieceVal, egPieceVal = 0;
            short bitboardIndex = -1;
    };

};

#endif