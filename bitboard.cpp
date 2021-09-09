#include "board.h"
#include <tuple>
#include <vector>
#include <bitset>

using namespace board;
using namespace std;

bitboard::bitboard() {
    board = {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
    };
}

bitboard::bitboard(vector<vector<pieceTypes>> mailbox) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (mailbox[i][j] != pieceTypes::empty) {
                short positionConversion = i * 8 + j;
                board[static_cast<int>(mailbox[i][j])] ^= 1UL << positionConversion;
            }
        }
    }
};

void bitboard::updateBitboard(pieceTypes piece, tuple<short, short> position) {
    short positionConversion = get<0>(position) * 8 + get<1>(position);
    board[static_cast<int>(piece)] ^= 1UL << positionConversion;
};

vector<unsigned long long> bitboard::getBitboard() {
    return board;
};

vector<vector<pieceTypes>> bitboard::generateMailbox() {
    vector<vector<pieceTypes>> mailbox(8, vector<pieceTypes>(8, pieceTypes::empty));

    for(int i = 0; i < 12; i++) {
        
        //TODO: fix this garbage, certain checking every bit is not the fastest solution
        //TODO: think of a better way to differentiate row and column too, this shit makes me feel dirty

        short row = 0;
        short column = 0;

        while(board[i]) {
            if (board[i] & 1) {
                mailbox[row][column] = pieceTypes(i);
            }
            board[i] >>= 1;
            if (column < 7) {
                column++;
            } else {
                column = 0;
                row++;
            }
        }
    }

    return mailbox;
};

void bitboard::printBitboard() {
    for (int i = 0; i < 12; i++) {
        bitset<64> bits(board[i]);
        cout << bits << endl;
    }
}