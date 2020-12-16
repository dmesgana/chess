//Mesgana Dinare
//December 14, 2020
//because i'm bored :/

#include <iostream>
#include <string>
#include "pieces.h"

         /******************* KING **************************/
bool king::illegal(int location[2]){
    
}

void king::move(int location[2]){
    //makes sure no OOB errors
    if(location[0] > 8 || location[0] < 0 || location[1] > 8 || location[1] < 0){
        printf("out of bounds");
        return;
    }
    //used to determine if the king made a
    //move thats bigger than on in any direction
    int diff[2] = {this->coord[0] - location[0], this->coord[1] - location[1]};
    if(diff[0] == 1 && (diff[1] == 1 || diff[0] == 0 || diff[1] == -1) || 
            diff[0] == 0 && (diff[1] == 1 || diff[1] == -1) || 
                diff[0] == -1 && (diff[1] == 1 || diff[0] == 0 || diff[1] == -1))
    {
    //tries to take a piece
        if(layout[location[0]][location[1]] != NULL){
            bool killed = kill(location);
        }
        
    //move in danger (not done rn cuz idk)

        this->update_coord(location[0], location[1]);
        printf("success");
        return;
    }
    printf("cannot move there");
    return;
}

         /******************* QUEEN **************************/
void queen::move(int location[2]){

}

         /******************* ROOK **************************/
void rook::move(int location[2]){

}

         /******************* BISHOP **************************/
void bishop::move(int location[2]){

}

         /******************* KNIGHT **************************/
void knight::move(int location[2]){

}

         /******************* PAWN **************************/
void pawn::move(int location[2]){
    //makes sure no OOB errors
    if(location[0] > 8 || location[0] < 0 || location[1] > 8 || location[1] < 0){
        printf("out of bounds");
        return;
    }

    //different colored pawns go in different directions (kinda racist tbh)
    int diff[2] = {this->coord[0] - location[0], this->coord[1] - location[1]};

    if(diff[1] > 1 || diff[1] == 0 || diff[1] < -1){return;} //makes sure the pawn cannot transport

    if(this->color == "white"){
        if(diff[0] == 0 && diff[1] == 1){
            if(layout[location[0]][location[1]] != NULL){
                update_coord(location[0], location[1]);
            }
            return;
        }

        if(layout[location[0]][location[1]] != NULL){
            bool killed = this->kill(location);
            return;
        }
    }

    else if(this->color == "black"){
        if(diff[0] == 0 && diff[1] == -1){
            if(layout[location[0]][location[1]] != NULL){
                update_coord(location[0], location[1]);
            }
            return;
        }

        if(layout[location[0]][location[1]] != NULL){
            bool killed = this->kill(location);
            return;
        }
    }
}