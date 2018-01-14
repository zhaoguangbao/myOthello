#include "board.h"
#include "player.h"

#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::system;

//绘制游戏图像
void draw_game(Board& b)
{
    for(int i=0;i<row;i++)
    {
        cout<<i;
        for(int j=0;j<col;j++)
        {
            if(j==0)
                cout<<"---";
            else
                cout<<"+---";
        }
        cout<<"+"<<endl;
        for(int j=0;j<=col;j++)
        {
            if(kEmpty!=b.get_state(Point(i,j)) && j!=col)
            {
                if(b.get_state(Point(i,j))==kBlack)
                    cout<<"|☆ ";
                else
                    cout<<"|○ ";
            }
            else
                cout<<"|   ";
        }
        cout<<endl;
    }
    for(int i=0;i<col;i++)
        cout<<i<<"---";
    cout<<"+"<<endl;
}
//输入处理
bool input(Player& py,Board& b)//耦合
{
    Point p=py.input_pos();
    if(p.x!=-1 && p.y!=-1)
    {
        //输入Point越界处理
        try{
            if(!py.get_move(b,p))
            {
                cout<<"There are already pawns in this position."<<endl;
                return false;
            }
            else
            {
                b.ruler(py.state,p);
                system("cls");
                draw_game(b);
            }
        }
        catch(error& e){
            cout<<py.name<<": "<<e.what()<<endl;
        }
    }
    else
    {
        cout<<py.name<<": skip the step"<<endl;
        py.skip_move();
    }
    return true;
}

int main()//test
{
    Player py_A("zhao",kBlack);
    Player py_B("zhang",kWhite);
    Board b;
    draw_game(b);
    while(true)
    {
        int score=0;
        input(py_A,b);
        score=b.cal_score(kBlack);
        cout<<py_A.name<<" score: "<<score<<endl;
        input(py_B,b);
        score=b.cal_score(kWhite);
        cout<<py_B.name<<" score: "<<score<<endl;
    }
    return 0;
}

