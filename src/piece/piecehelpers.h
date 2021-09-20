#ifndef PIECEHELPERS_H
#define PIECEHELPERS_H

#include "piece.h"
#include <vector>
using namespace std;
using namespace PIECE;

piece* getPieceByShort(short p, vector<short> position={0,0});
piece* getPieceByChar(char p, vector<short>position={0,0});

#endif