#include <iostream>
#include <vector>
#include <list>
#include "board/board.h"
#include "piece/piece.h"
using namespace std;
using namespace BOARD;
using namespace PIECE;

int main() {
    board testboard = board("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
    // list<vector<short>> moves = testboard.getLegalMovesAtIndex({4, 3});

    // for (list<vector<short>>::iterator it = moves.begin(); it != moves.end(); it++) {
    //     vector<short> move = *it;
    //     cout << move[0] << " " << move[1] << endl;
    // }

    cout << endl << "White Threatened: " << endl;
    testboard.printMailbox(true, 0);

    cout << endl << "Black Threatened: " << endl;
    testboard.printMailbox(true, 1);

    // cout << endl << "White Threatened: " << endl;
    // for (int i = 0; i < 8; i++) {
    //     for (int j = 0; j < 8; j++) {
    //         if (testboard.getWhiteThreatened()[i][j]) {
    //             cout << i << " " << j << endl;
    //         }
    //     }
    // }

    // cout << endl << "Black Threatened: " << endl;
    // for (int i = 0; i < 8; i++) {
    //     for (int j = 0; j < 8; j++) {
    //         if (testboard.getBlackThreatened()[i][j]) {
    //             cout << i << " " << j << endl;
    //         }
    //     }
    // }
    // // testboard.printMailbox();

}
