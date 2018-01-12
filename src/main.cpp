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
bool input(Player& py,Board& b)
{
    Point p=py.input_pos();//检查是否越界
    if(p.x!=-1 && p.y!=-1)
    {
        if(!py.get_move(b,p))
        {
            cout<<"The position should not be empty!"<<endl;
            return false;
        }
        b.ruler(py.state,p);
    }
    else
        py.skip_move();
    system("cls");
    draw_game(b);
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
        /*if(!input(py_A,b))//游戏逻辑稍有问题
            input(py_A,b);
        if(!input(py_B,b))
            input(py_B,b);*/
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

