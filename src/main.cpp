#include <iostream>
#include <vector>
#include <list>
#include "board/board.h"
#include "piece/piece.h"
using namespace std;
using namespace BOARD;
using namespace PIECE;

int main() {
    board testboard = board("8/3r4/8/r2R1r2/8/3r4/8/8 w - - 0 1");
    piece* testPiece = testboard.getPieceAtIndex({4, 3});
    list<vector<short>> moves = testPiece->getLegalMoves(testboard.getMailbox().getBoard());

    for (list<vector<short>>::iterator it = moves.begin(); it != moves.end(); it++) {
        vector<short> move = *it;
        cout << move[0] << " " << move[1] << endl;
    }

    // board testboard = board("rnbq2nr/1ppkpp1p/3p3b/p5p1/3PP3/1PN1KP2/P1P1N1PP/R1BQ1B1R b - c4 5 10");
    // board testboard = board();
    // cout << testboard.getFenString() << endl;
    // testboard.printMailbox();
    // // cout << endl;
    // // testboard.printBitboard();
    // cout << "Next: " << testboard.getNext() << endl;
    // vector<bool>::iterator it;
    // cout << "Castling: ";
    // // for (it = testboard.getCastling().begin(); it < testboard.getCastling().end(); it.) {
    // for (int i = 0; i < 4; i++) {
    //     cout << testboard.getCastling()[i] << " ";
    // }
    // cout << endl;
    // cout << "En Passant: " << testboard.getEnPassant()[0] << " " << testboard.getEnPassant()[1] << endl;
    // cout << "Clock: " << testboard.getHalfmoveClock() << " " << testboard.getFullmoveClock() << endl;

    // testboard.movePiece({0,2},{2,0});
    // testboard.printMailbox();
    // cout << testboard.getFenString() << endl;
}