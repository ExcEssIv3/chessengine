#ifndef MAILBOX_H
#define MAILBOX_H

#include "../piece/piece.h"
#include <iostream>
#include <vector>
#include <tuple>
#include <map>
#include <bitset>
using namespace PIECE;
using namespace std;

namespace BOARD {

    class bitboard {
        
        // TODO: fenString regex validation

        public:
            bitboard();
            bitboard(vector<vector<piece*>> mailbox);
            ~bitboard();
            // flips bit in a bitboard, not an actual move just an update
            void updateBitboard(piece* p, const vector<short>& position);
            vector<bitset<64>> getBitboard();
            vector<vector<piece*>> generateMailbox();
            void printBitboard();
            // this one is slow, use one with piece paramter if possible
            void movePiece(short startIndex, short finalIndex);
            void movePiece(short bitboardIndex, short startIndex, short finalIndex);
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
            mailbox(vector<vector<piece*>> positions);
            vector<vector<piece*>> getBoard();
            bitboard getBitboard();
            piece* getPieceAtIndex(const vector<short>& index);
            void printBoard(bool showThreatened, vector<vector<bool>> threatened);
            void movePiece(const vector<short>& startIndex, const vector<short>& finalIndex, const bool& isEnPassant, const bool& isCastle);
            list<vector<short>> getLegalMovesAtIndex(const vector<short>& index, const vector<short>& enPassantIndex, const vector<vector<bool>>& threatened);
        private:
            vector<vector<piece*>> board = vector<vector<piece*>>(8, vector<piece*>(8, new piece()));
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
            // prints mailbox, if showThreatened = true color needs to be 0 | 1
            void printMailbox(bool showThreatened = false, short color = -1);
            void printBitboard();
            void movePiece(vector<short> startIndex, vector<short> finalIndex);
            list<vector<short>> getLegalMovesAtIndex(const vector<short>& index);
            piece* getPieceAtIndex(vector<short> position);
            mailbox getMailbox();
            vector<vector<bool>> getWhiteThreatened();
            vector<vector<bool>> getBlackThreatened();
            void updateWhiteThreatened();
            void updateBlackThreatened();
        private:
            void updateFenString();
            bool next = 0;
            // 4 boolean vector representing KQkq (uppercase = white)
            vector<bool> castling = vector<bool>(4, 0);
            vector<short> enPassant = {8, 8};
            short halfmoveClock = 0;
            int fullmoveClock = 0;
            string fenString;

            vector<vector<bool>> whiteThreatened = vector<vector<bool>>(8, vector<bool>(8, 0));
            vector<vector<bool>> blackThreatened = vector<vector<bool>>(8, vector<bool>(8, 0));

            // board representations
            bitboard bitRepresentation;
            mailbox arrayRepresentation;
    };

};

#endif