#ifndef MAILBOX_H
#define MAILBOX_H

#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

// TODO: create actual class destructor/constructor esque functions
// TODO: setup to take in game string things from that video
// TODO: investigate bitsets

    
namespace BOARD {

    // enum of pieces for readability   
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
    
    // TODO: print statement for board containing extra game information and mailbox
    

    class bitboard {
        
        // TODO: fenString regex validation

        public:
            bitboard();
            bitboard(vector<vector<pieceTypes>> mailbox);
            // flips bit in a bitboard, not an actual move just an update
            // tuple reads row, column
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
            // bitboard boardRepresentation;
            vector<vector<pieceTypes>> board = vector<vector<pieceTypes>>(8, vector<pieceTypes>(8, pieceTypes::empty));
            char getPieceChar(pieceTypes piece);
            // any null pointer is assumed no piece
            // pieceTypes* parseBitboard();
    };

    class board {
        public:
            board();
            board(string fenString);
            // 0 for white
            bool getNext();
            void flipNext();
            // 4 boolean vector representing KQkq (uppercase = white)
            vector<bool> getCastling();
            // 0 for kingside, 0 for white
            void setCastling(bool side, bool color);
            // piece position for en passant, holds [8,8] if n/a
            tuple<short, short> getEnPassant();
            short getHalfmoveClock();
            void incrementHalfmoveClock();
            void resetHalfmoveClock();
            int getFullmoveClock();
            void incrementFullmoveClock();
            string getFenString();
        private:
            void updateFenString();
            bool next = 0;
            // 4 boolean vector representing KQkq (uppercase = white)
            vector<bool> castling = vector<bool>(4, true);
            tuple<short, short> enPassant = make_tuple(8, 8);
            short halfmoveClock = 0;
            int fullmoveClock = 0;
            string fenString;

            // board representations
            bitboard bitRepresentation;
            mailbox arrayRepresentation;
    };

};

#endif