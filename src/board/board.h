#ifndef MAILBOX_H
#define MAILBOX_H

#include "piece.h"
#include <iostream>
#include <vector>
#include <tuple>
#include <map>
#include <bitset>
using namespace std;

// TODO: investigate bitsets

    
namespace BOARD {

    // TODO: print statement for board containing extra game information and mailbox

    class bitboard {
        
        // TODO: fenString regex validation

        public:
            bitboard();
            bitboard(vector<vector<pieceTypes>> mailbox);
            ~bitboard();
            // flips bit in a bitboard, not an actual move just an update
            void updateBitboard(pieceTypes piece, vector<short> position);
            vector<bitset<64>> getBitboard();
            vector<vector<pieceTypes>> generateMailbox();
            void printBitboard();
            // this one is slow, use one with piece paramter if possible
            void movePiece(short startIndex, short finalIndex);
            void movePiece(pieceTypes piece, short startIndex, short finalIndex);
            private:
            // bitboard order:
            // white {pawn, rook, knight, bishop, queen, king}
            // black {pawn, rook, knight, bishop, queen, king}
            //mimics pieceTypes, should be able to reference bitboard through bitboard[pieceType]
            vector<bitset<64>> board = vector<bitset<64>>(12, 0);
    };

    class mailbox {
        public:            
            mailbox();
            mailbox(bitboard boardRepresentation);
            ~mailbox();
            mailbox(vector<vector<pieceTypes>> positions);
            vector<vector<pieceTypes>> getBoard();
            bitboard getBitboard();
            pieceTypes getPieceAtIndex(vector<short> index);
            void printBoard();
            void movePiece(vector<short> startIndex, vector<short> finalIndex);
        private:
            vector<vector<pieceTypes>> board = vector<vector<pieceTypes>>(8, vector<pieceTypes>(8, pieceTypes::empty));
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
            vector<short> getEnPassant();
            short getHalfmoveClock();
            void incrementHalfmoveClock();
            void resetHalfmoveClock();
            int getFullmoveClock();
            void incrementFullmoveClock();
            string getFenString();
            void setFenString(string newString);
            void resetBoard();
            void printMailbox();
            void printBitboard();
            void movePiece(vector<short> startIndex, vector<short> finalIndex);
        private:
            void updateFenString();
            bool next = 0;
            // 4 boolean vector representing KQkq (uppercase = white)
            vector<bool> castling = { false, false, false, false };
            vector<short> enPassant = {8, 8};
            short halfmoveClock = 0;
            int fullmoveClock = 0;
            string fenString;

            // board representations
            bitboard bitRepresentation;
            mailbox arrayRepresentation;
    };

};

#endif