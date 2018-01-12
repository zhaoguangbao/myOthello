#ifndef __PLAYER_H_

#define __PLAYER_H_

#include "board.h"
#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

class Player
{
public:
    string name;
    State state;
    //ÏÂÆå
    bool get_move(Board& b,Point p)
    {
        return b.set_board(p,this->state);
    }
    //Ìø²½
    void skip_move(){}
    Player(string name,State s)
    {
        this->name=name;
        state=s;
    }
    //
    Point input_pos()
    {
        Point p;
        cout<<"Hi,"<<name<<" please intput the position"
            <<endl<<"Input \"-1 -1\" for skipping the step:";
        cin>>p.x>>p.y;
        return p;
    }
};


#endif // __PLAYER_H_
