#include <iostream>
#include <vector>
#include "board.h"
using namespace std;

int main() {
    BOARD::mailbox testBoard = BOARD::mailbox();
    testBoard.printBoard();
    testBoard.getBitboard().printBitboard();
}