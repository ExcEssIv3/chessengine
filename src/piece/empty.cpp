#include "piece.h"
#include <vector>

using namespace std;
using namespace PIECE;

empty::empty(vector<short> position){
    this->position = position;
};

empty::empty(const empty& r) {
    this->position = r.position;
};