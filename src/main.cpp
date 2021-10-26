#include <iostream>
#include <vector>
#include <list>
#include "board/board.h"
#include "piece/piece.h"
using namespace std;
using namespace BOARD;
using namespace PIECE;

int main() {
    board testboard = board("8/8/8/8/4p3/8/5P2/8 w - - 0 1");
    list<vector<short>> moves = testboard.getLegalMovesAtIndex({4, 5});

    for (list<vector<short>>::iterator it = moves.begin(); it != moves.end(); it++) {
        vector<short> move = *it;
        cout << move[0] << " " << move[1] << endl;
    }
    // testboard.printMailbox();
    testboard.movePiece(vector<short>({1, 5}), vector<short>({3, 5}));  
    testboard.movePiece(vector<short>({3, 4}), vector<short>({2, 5}));
    testboard.printMailbox();
    cout << testboard.getEnPassant()[0] << ", " << testboard.getEnPassant()[1] << endl;

}