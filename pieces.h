#ifndef PIECES_H
#define PIECES_H

#include <string>
#include <cstdlib>

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

    bool exposed_king(int location[2], int king[2], std::string bw){ //make sure no pieces are on the path (depends on piece)
        int y = location[0] - king[0]; int x = location[1] - king[1];
        std::string type = "";
        y /= abs(y); x /= abs(x);

        if((y==1||y==-1) && (x==-1||x==1)){
            type = "bishop";
        }
        else{
            type = "rook";
        }

        piece* find_piece = layout[y][x];
        while(y < 8 && x < 8){
            if(find_piece != NULL && find_piece->color != bw){
                if(find_piece->myName == type || find_piece->myName == "queen"){
                    return true;
                }
            }
            y += y; x += x;
        }
        return false;
    }

    void update_coord(int y, int x){ //make sure current location is updated
        piece* temp = layout[coord[0]][coord[1]];
        delete layout[coord[0]][coord[1]];
        coord[0] = y; coord[1] = x;
        layout[y][x] = temp; 
    } 
};

class king: public piece{
public:
    king(){
        myName = "king";
    }
    void move(int location[2]);
    void update_coord(int x, int y);
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