#ifndef __OTHELLO_BOARD_H_
#define __OTHELLO_BOARD_H_
//用于规则库判定的8个方向
const int dirNum=8;
const int dir[dirNum][2]={{0,-1},{1,0},{0,1},{-1,0},//上、右、下、左
                {1,-1},{1,1},{-1,1},{-1,-1}};//右上、右下、左下、左上

struct Point
{
    int x;
    int y;
    Point(int x=0,int y=0)
    {
        this->x=x;
        this->y=y;
    }
};
enum State{kWhite=-1,kEmpty=0,kBlack=1};

//棋盘的行数与列数
const int row=8;
const int col=8;

class Board
{
public:
    Board();
    int cal_score(const State);//eff
    State get_state(Point p)
    {
        return board[p.x][p.y];
    }
    //
    void ruler(const State,Point);//othello规则判断
    void Init();
    bool set_board(const Point,const State);
private:
    State board[row][col];
};

#endif // __OTHELLO_BOARD_H_


//
