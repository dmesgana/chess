#ifndef PIECES_H
#define PIECES_H

#include <string>

piece* layout[8][8];
int bk_pos[2] = {5, 0};
int wk_pos[2] = {5, 8};

//basic piece class that has methods all pieces will need
class piece{
public:
    std::string myName;
    std::string color;
    int kill_count = 0; //to see which piece was used the most
    int coord[2]; //current location
    int dead = 0; //0 is alive, 1 is dead
    int kings_pos[2]; //position of the king

    bool kill(int location[2]){
        piece* who = layout[location[0]][location[1]];
        if(who->color != this->color){ //makes sure its not an ally
            who->dead = 1;
            this->kill_count++;
            this->update_coord(location[0], location[1]);
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