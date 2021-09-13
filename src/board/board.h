#ifndef MAILBOX_H
#define MAILBOX_H

#include <iostream>
#include <vector>
#include <tuple>
#include <map>
using namespace std;

// TODO: investigate bitsets

    
namespace BOARD {

    // enum of pieces for readability   

    // TODO: build datastructure for this of some kind
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
    
    // char getPieceChar(pieceTypes piece);
    // pieceTypes getPieceByChar(char piece);
    // bool isValidChar(char piece);
    
    // TODO: print statement for board containing extra game information and mailbox
    

    class bitboard {
        
        // TODO: fenString regex validation

        public:
            bitboard();
            bitboard(vector<vector<pieceTypes>> mailbox);
            ~bitboard();
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
            ~mailbox();
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
            ~board();
            // 0 for white
            bool getNext();
            void flipNext();
            // 4 boolean vector representing KQkq (uppercase = white)
            vector<bool> getCastling();
            void setCastling(vector<bool> castling);
            // piece position for en passant, holds [8,8] if n/a
            tuple<short, short> getEnPassant();
            short getHalfmoveClock();
            void incrementHalfmoveClock();
            void resetHalfmoveClock();
            int getFullmoveClock();
            void incrementFullmoveClock();
            string getFenString();
            void setFenString(string newString);
            void resetBoard();
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