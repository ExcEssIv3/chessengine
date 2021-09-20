#include <iostream>
#include <vector>
#include "board/board.h"
#include "piece/piece.h"
using namespace std;
using namespace BOARD;

int main() {
    board testboard = board("rnbq2nr/1ppkpp1p/3p3b/p5p1/3PP3/1PN1KP2/P1P1N1PP/R1BQ1B1R b - c4 5 10");
    cout << testboard.getFenString() << endl;;
    testboard.printMailbox();
    // cout << endl;
    // testboard.printBitboard();
    cout << "Next: " << testboard.getNext() << endl;
    vector<bool>::iterator it;
    cout << "Castling: ";
    // for (it = testboard.getCastling().begin(); it < testboard.getCastling().end(); it.) {
    for (int i = 0; i < 4; i++) {
        cout << testboard.getCastling()[i] << " ";
    }
    cout << endl;
    cout << "En Passant: " << testboard.getEnPassant()[0] << " " << testboard.getEnPassant()[1] << endl;
    cout << "Clock: " << testboard.getHalfmoveClock() << " " << testboard.getFullmoveClock() << endl;

    testboard.movePiece({0,2},{2,0});
    testboard.printMailbox();
    cout << testboard.getFenString() << endl;
}