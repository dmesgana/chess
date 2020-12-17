//Mesgana Dinare
//December 14, 2020
//because i'm bored :/

#include <iostream>
#include <string>
#include "pieces.h"

         /******************* KING **************************/
bool king::illegal(int location[2]){
    //king moves into danger
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
        
    //not move in danger (not done rn cuz idk) **implement**

        this->update_coord(location[0], location[1]);
        printf("success");
        return;
    }
    printf("cannot move there");
    return;
}

         /******************* QUEEN **************************/
void queen::move(int location[2]){
    //makes sure no OOB errors
    if(location[0] > 8 || location[0] < 0 || location[1] > 8 || location[1] < 0){
        printf("out of bounds");
        return;
    }

    int diff[2] = {this->coord[0] - location[0], this->coord[1] - location[1]};

}

         /******************* ROOK **************************/
void rook::move(int location[2]){
    //makes sure no OOB errors
    if(location[0] > 8 || location[0] < 0 || location[1] > 8 || location[1] < 0){
        printf("out of bounds");
        return;
    }

    int diff[2] = {this->coord[0] - location[0], this->coord[1] - location[1]};
    if((diff[0] != 0) != (diff[1] != 0)){
        printf("illegal rook move");
        return;
    }

    //makes sure rooks don't jump over pieces
    int i = 0;
    int dir = 0;
    bool up = false;
    piece* temp;
    if(i == diff[1]){dir = diff[0]; up = true;}
    else dir = diff[1];
    while(i != dir){
        if(up){
            //down
            if(dir < 0){
                temp = layout[location[0]+i+1][location[1]];
                i++;
            }
            //up
            else{
                temp = layout[location[0]+i-1][location[1]];
                i--;
            }
        }
        
        else{
            //right
            if(dir > 0){
                temp = layout[location[0]][location[1]+i+1];
                i++;
            }
            //left
            else{
               temp = layout[location[0]][location[1]+i-1];
                i--; 
            }
        }

        if(temp != NULL){
            printf("piece in the way");
            return;
        }
    }
    //exposed king **implement**

    //kill

    this->update_coord(location[0], location[1]);
}

         /******************* BISHOP **************************/
void bishop::move(int location[2]){
    //makes sure no OOB errors
    if(location[0] > 8 || location[0] < 0 || location[1] > 8 || location[1] < 0){
        printf("out of bounds");
        return;
    }

    int diff[2] = {this->coord[0] - location[0], this->coord[1] - location[1]};
    if(location[0] != location[1]){
        printf("illegal bishop move");
        return;
    }

    //no jumping over pieces

    //kill

    //exposed king **implement**

    this->update_coord(location[0], location[1]);
}

         /******************* KNIGHT **************************/
void knight::move(int location[2]){
    //makes sure no OOB errors
    if(location[0] > 8 || location[0] < 0 || location[1] > 8 || location[1] < 0){
        printf("out of bounds");
        return;
    }

    int diff[2] = {this->coord[0] - location[0], this->coord[1] - location[1]};
    if((diff[0] != 1 || diff[0] != -1 &&  diff[1] != 2 || diff[1] != -2) ||
        (diff[0] != 2 || diff[0] != -2 && diff[1] != 1 || diff[1] != -1))
        {
            printf("not a legal knight move");
            return;
        }
    
    //exposed king  **implement**

    this->update_coord(location[0], location[1]);
}

         /******************* PAWN **************************/
void pawn::move(int location[2]){
    //makes sure no OOB errors
    if(location[0] > 8 || location[0] < 0 || location[1] > 8 || location[1] < 0){
        printf("out of bounds");
        return;
    }

    int diff[2] = {this->coord[0] - location[0], this->coord[1] - location[1]};


    if(diff[1] > 1 || diff[1] < -1 || diff[0] > 1 || diff[0] == 0 || diff[0] < -1){return;} //makes sure the pawn cannot transport

    //exposed king **implement**

    //different colored pawns go in different directions (kinda racist tbh)
    if(this->color == "white"){
        //one move up
        if(diff[0] == 1 && diff[1] == 0){
            if(layout[location[0]][location[1]] != NULL){
                this->update_coord(location[0], location[1]);
            }
            return;
        }

        //kill
        if(layout[location[0]][location[1]] != NULL){
            bool killed = this->kill(location);
            return;
        }

        //first time move double jump ++
    }

    else if(this->color == "black"){
        //one move up
        if(diff[0] == -1 && diff[1] == 0){
            if(layout[location[0]][location[1]] != NULL){
                this->update_coord(location[0], location[1]);
            }
            return;
        }

        //kill
        if(layout[location[0]][location[1]] != NULL){
            bool killed = this->kill(location); 
            return;
        }

        //first time move double jump --
    }
}