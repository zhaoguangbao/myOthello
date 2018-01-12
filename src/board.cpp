#include "board.h"

Board::Board()
{
    Init();
}
void Board::Init()
{
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
            board[i][j]=kEmpty;
    board[row/2-1][col/2-1]=kBlack;
    board[row/2][col/2]=kBlack;
    board[row/2-1][col/2]=kWhite;
    board[row/2][col/2-1]=kWhite;
}

//eff 采用效率极低的方式实现的计分方式
int Board::cal_score(const State state)
{
    int score=0;
    for(int i=0;i<row;i++)
        for(int j=0;j<col;j++)
        {
            if(state==board[i][j])
                score++;
        }
    return score;
}

//越界检查
bool check_bound(const Point point)
{
    return (point.x<0 || point.y<0 || point.x>col-1 || point.y>row-1);
}

//规则库
//可利用栈进行改进
void Board::ruler(const State state,Point point)
{
    Point curP=point;
    for(int i=0;i<dirNum;i++)
    {
        curP.x=point.x+dir[i][0];
        curP.y=point.y+dir[i][1];
        if(check_bound(curP))
            return;
        while(-state==board[curP.x][curP.y])
        {
            curP.x+=dir[i][0];
            curP.y+=dir[i][1];
            if(check_bound(curP))
                return;
            if(state==board[curP.x][curP.y])
            {
                curP.x-=dir[i][0];
                curP.y-=dir[i][1];
                while(curP.x!=point.x || curP.y!=point.y)
                {
                    board[curP.x][curP.y]=state;
                    curP.x-=dir[i][0];
                    curP.y-=dir[i][1];
                }
                break;
            }
        }
    }
}
//设置棋盘状态
bool Board::set_board(const Point point,const State state)
{
    if(kEmpty==board[point.x][point.y])
    {
        board[point.x][point.y]=state;
        ruler(state,point);
        return true;
    }
    return false;
}

