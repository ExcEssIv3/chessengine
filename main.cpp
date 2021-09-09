#include <iostream>
#include <vector>
#include "board.h"
using namespace std;

int main() {
    board::mailbox testBoard = board::mailbox();
    testBoard.printBoard();
    testBoard.getBitboard().printBitboard();
}