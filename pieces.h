#ifndef PIECES_H
#define PIECES_H

#include <stdio.h>
#include <string>

piece* layout[8][8];

//basic piece class that has methods all pieces will need
class piece{
public:
    std::string myName;
    std::string color;
    int kill_count = 0; //to see which piece was used the most
    int coord[2]; //current location
    int dead = 0; //0 is alive, 1 is dead

    void kill(piece to_eat) //eat a piece
    {
        to_eat.dead = 1;
        this->kill_count++;
    }
    bool can_kill(int location[2]){
        piece* who = layout[location[0]][location[1]];
        if(who != NULL){
            if(who->color != this->color){
                this->kill(*who);
                return false;
            }
            return true;
        }
        return false;
    }
    void move(int location[2]); //move current piece (depends on piece) lefal move also

    bool illegal(int location[2]); //make sure no pieces are on the path (depends on piece)

    void update_coord(int x, int y){ //make sure current location is updated
        piece* temp = layout[coord[0]][coord[1]];
        delete layout[coord[0]][coord[1]];
        coord[0] = x; coord[1] = y;
        layout[x][y] = temp; 
    } 
};

class king: public piece{
public:
    king(){
        myName = "king";
    }
    void move(int location[2]);
    bool illegal(int location[2]);
};

class queen: public piece{
public:
    queen(){
        myName = "queen";
    }
    void move(int location[2]);
};

class rook: public piece{
public:
    rook(){
        myName = "rook";
    }
    void move(int location[2]);
};

class bishop: public piece{
public:
    bishop(){
        myName = "bishop";
    }
    void move(int location[2]);
};

class knight: public piece{
public:
    knight(){
        myName = "knight";
    }
    void move(int location[2]);
};

class pawn: public piece{
public:
    pawn(){
        myName = "pawn";
    }
    void move(int location[2]);
};
#endif