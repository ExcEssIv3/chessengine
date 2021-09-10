#include "board.h"
#include <iostream>
#include <tuple>

using namespace std;
using namespace BOARD;

board::board() {
    fenString = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";
}

board::board(string fenString) {
    this->fenString = fenString;
    short indices[] = {0, 0};
    string::iterator it;
    for (it = fenString.begin(); it != fenString.end(); it++) {
        
    }
}

