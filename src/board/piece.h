#ifndef PIECE_H
#define PIECE_H

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
pieceTypes getPieceByShort(short piece);
bool isValidChar(char piece);

#endif