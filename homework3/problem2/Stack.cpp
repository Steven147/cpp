#include "Stack.h"

template <class elemType>
seqStack<elemType>::seqStack(int initSize)
{ elem = new elemType[initSize]; maxSize = initSize ; top_p = -1; }

template <class elemType>
seqStack<elemType>:: ~seqStack()
{ delete [] elem; }

template <class elemType>
bool seqStack<elemType>:: isEmpty() const
{ return top_p == -1; }

template <class elemType>
void seqStack<elemType>::push(const elemType &x)
{
    if (top_p == maxSize - 1) doubleSpace();
    elem[++top_p] = x;
}

template <class elemType>
elemType seqStack<elemType>::pop()
{ return elem[top_p--]; }

template <class elemType>
elemType seqStack<elemType>::top() const
{ return elem[top_p]; }

template <class elemType>
void seqStack<elemType>::doubleSpace()
{
    elemType *tmp = elem;
    elem = new elemType[2 * maxSize]; for (int i = 0; i < maxSize; ++i)
        elem[i] = tmp[i]; maxSize *= 2; delete [] tmp;
}

class point
{
private:
    int row, column, n, start;
    int** maze;
    
public:
    point(int r, int c, int N, int** m, int s = 0): row(r), column(c), n(N), maze(m), start(s) { maze[row][column] = -1; }//经过的点标记-1
    ~point(){maze[row][column] = 0;}
    int NearOptions()//从某一个方向开始，返回第一个可用的路径，按下右上左的顺序（分别是0123，找不到返回-1）
    {
        if(start <= 0 and row <= n-2 and maze[row+1][column] == 0) return 0;//如果从下开始、有下一行、下方一位为0,则返回0
        else if(start <= 1 and column <= n-2 and maze[row][column+1] == 0) return 1;//右
        else if(start <= 2 and row >= 1 and maze[row-1][column] == 0) return 2;//上
        else if(start <= 3 and column >= 1 and maze[row][column-1] == 0) return 3;//左
        else return -1;
    }
    int getRow() {return row;}
    int getColumn() {return column;}
    bool isFinal() { return (row == n - 1 and column == n - 1); }
    point* nextOption()
    {
        start = this->NearOptions()+1;
        return this;
    }
};
