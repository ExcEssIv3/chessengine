#include <iostream>
#include <vector>
#include "./board/board.h"
using namespace std;
using namespace BOARD;

int main() {
    board testboard = board("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
    testboard.printMailbox();
    cout << endl;
    testboard.printBitboard();
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
}