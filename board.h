#ifndef MAILBOX_H
#define MAILBOX_H

#include <iostream>
#include <vector>
using namespace std;

// TODO: create actual class destructor/constructor esque functions
// TODO: setup to take in game string things from that video
// TODO: investigate bitsets

    // enum of pieces for readability   
    enum class pieceTypes {
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
        bking,
        empty
    };

namespace board {

    class bitboard {
        
        public:
            // flips bit in a bitboard, not an actual move just an update
            // tuple reads row, column
            bitboard();
            bitboard(vector<vector<pieceTypes>> mailbox);
            void updateBitboard(pieceTypes piece, tuple<short, short> position);
            vector<unsigned long long> getBitboard();
            vector<vector<pieceTypes>> generateMailbox();
            void printBitboard();
            private:
            // bitboard order:
            // white {pawn, rook, knight, bishop, queen, king}
            // black {pawn, rook, knight, bishop, queen, king}
            //mimics pieceTypes, should be able to reference bitboard through bitboard[pieceType]
            vector<unsigned long long> board = vector<unsigned long long>(12, 0);

            

    };

    class mailbox {
        public:            
            mailbox();
            mailbox(bitboard boardRepresentation);
            // accepts pointer because pointer can point to null for no piece
            mailbox(vector<vector<pieceTypes>> positions);
            vector<vector<pieceTypes>> getBoard();
            bitboard getBitboard();
            void printBoard();
        private:
            bitboard boardRepresentation;
            vector<vector<pieceTypes>> board = vector<vector<pieceTypes>>(8, vector<pieceTypes>(8, pieceTypes::empty));
            char getPieceChar(pieceTypes piece);
            // any null pointer is assumed no piece
            // pieceTypes* parseBitboard();
    };

}

#endif