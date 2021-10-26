#include <iostream>
#include <vector>
#include <list>
#include "board/board.h"
#include "piece/piece.h"
using namespace std;
using namespace BOARD;
using namespace PIECE;

int main() {
    board testboard = board("8/1r1r1r2/8/1r1q1r2/8/1r1r1r2/8/8 w - - 0 1");
    list<vector<short>> moves = testboard.getLegalMovesAtIndex({4, 3});

    for (list<vector<short>>::iterator it = moves.begin(); it != moves.end(); it++) {
        vector<short> move = *it;
        cout << move[0] << " " << move[1] << endl;
    }
    // testboard.printMailbox();

}
