//chess board

#include <iostream>
#include "pieces.h"

extern piece* layout[8][8];
extern int bk_pos[2];
extern int wk_pos[2];

void board_setup(){
    king *bk, *wk;
    queen *bq, *wq;
    rook *br1, *wr1, *br2, *wr2;
    bishop *bb1, *wb1, *bb2, *wb2;
    knight *bn1, *wn1, *bn2, *wn2;
    pawn *bp1, *bp2, *bp3, *bp4, *bp5, *bp6, *bp7, *bp8;
    pawn *wp1, *wp2, *wp3, *wp4, *wp5, *wp6, *wp7, *wp8;

    bk->color="black";
    bq->color="black";
    br1->color="black"; br2->color="black";
    bb1->color="black"; bb2->color="black";
    bn1->color="black"; bn2->color="black";
    bp1->color="black"; bp2->color="black"; bp3->color="black"; bp4->color="black";
    bp5->color="black"; bp6->color="black"; bp7->color="black"; bp8->color="black";

    wk->color="white";
    wq->color="white";
    wr1->color="white"; wr2->color="white";
    wb1->color="white"; wb2->color="white";
    wn1->color="white"; wn2->color="white";
    wp1->color="white"; wp2->color="white"; wp3->color="white"; wp4->color="white";
    wp5->color="white"; wp6->color="white"; wp7->color="white"; wp8->color="white";
}