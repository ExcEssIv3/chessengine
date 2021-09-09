#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <tuple>
using namespace std;

namespace board {

    class bitboard {
        
        public:
            // bitboard(unsigned long long board[12]);

            // flips bit in a bitboard, not an actual move just an update
            // tuple reads row, column
            void updateBitboard(short piece, tuple<short, short> position);
            unsigned long long getBitboard(); 

            protected:
            // bitboard order:
            // white {pawn, rook, knight, bishop, queen, king}
            // black {pawn, rook, knight, bishop, queen, king}
            //mimics pieceTypes, should be able to reference bitboard through bitboard[pieceType]
            unsigned long long board[12] = {
                0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
            };

            

    };
   
    
    class board {
        public:

            // enum of pieces for readability   
            enum pieceTypes {
                wpawn,
                wrook,
                wknight,
                wbishop,
                wqueen,
                wking,
                bpawn,
                brook,
                bknight,
                bbishop,
                bqueen,
                bking
            };
            board();
            board(unsigned long long bitboard[12]);
            // accepts pointer because pointer can point to null for no piece
            board(pieceTypes *positions[8][8]);
            string printBoard();
        private:
            bitboard boardRepresentation;
            char getPositionChar();
            // any null pointer is assumed no piece
            pieceTypes* parseBitboard();
    };

}

#endif