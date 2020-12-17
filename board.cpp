//chess board

#include <iostream>
#include "pieces.h"

extern piece* layout[8][8];
extern int bk_pos[2];
extern int wk_pos[2];

void board_setup(){
    king* bk, wk;
    queen* bq, wq;
    rook* br1, wr1, br2, wr2;
    bishop* bb1, wb1, bb2, wb2;
    knight* bn1, wn1, bn2, wn2;
    pawn* bp1, bp2, bp3, bp4, bp5, bp6, bp7, bp8;
    pawn* wp1, wp2, wp3, wp4, wp5, wp6, wp7, wp8;
}