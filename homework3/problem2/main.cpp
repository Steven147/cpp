/*
 Problem 2
 设计一个函数，在一个N*N迷宫中找出从起点到终点的最短路径，起点坐标为(0,0)、终点坐标为(N-1,N-1)。迷宫以一个二维数组maze来表示，以0代表可行，1代表障碍。 (30')

 输入描述

 第1行输入迷宫maze的大小N，N为大于2的正整数；

 输入的第2到N+1行分别为迷宫第1到N行的数据，数据为0或1。

 输出描述

 输出共1行。按照从起点到终点的行走顺序，输出从起点到终点的最短路径，路径以坐标形式表示，输出应包含起点坐标和终点坐标；
 如不存在最短路径，输出Not found；如果存在多条最短路径，只需要输出其中一条。

 注意：输入输出逻辑在附件代码中已给定，请不要修改。

 输入输出自测
 
 5
 0 0 1 1 0
 1 0 0 1 1
 0 0 0 0 1
 0 1 1 0 1
 0 0 0 0 0
 (0,0)(0,1)(1,1)(1,2)(2,2)(2,3)(3,3)(4,3)(4,4)
 Program ended with exit code: 0

 6
 0 0 0 0 0 0
 1 1 1 1 1 0
 0 0 0 0 0 0
 0 1 1 1 1 1
 0 0 0 1 0 0
 1 1 0 0 0 0
 (0,0)(0,1)(0,2)(0,3)(0,4)(0,5)(1,5)(2,5)(2,4)(2,3)(2,2)(2,1)(2,0)(3,0)(4,0)(4,1)(4,2)(5,2)(5,3)(5,4)(5,5)
 Program ended with exit code: 0
 
 4
 0 0 0 0
 0 0 0 0
 0 0 0 0
 0 0 0 0
 (0,0)(0,1)(0,2)(0,3)(1,3)(2,3)(3,3)
 Program ended with exit code: 0
 
 4
 0 0 0 0
 0 0 0 0
 0 0 1 1
 0 0 1 0
 Not found
 Program ended with exit code: 0
 
 
 */
#include<iostream>
// #include "Queue.h"
#include "Stack.cpp"
using namespace std;

int thisLength = 0;

void savePath(seqStack<point*> &pointSeq, int** path, int& path_length)
{
    if(path[0] == NULL)
    {
        path[0] = new int[path_length];
        path[1] = new int[path_length];
        thisLength = path_length;
    }
    
    point** p = pointSeq.getElem();//p指向栈数组，数组中存放指向点的指针
    if(path_length <= thisLength)
    {
        for(int i = 0; i < path_length; ++i)
        {
            path[0][i] = (*(p + i))->getRow();
            path[1][i] = (*(p + i))->getColumn();
        }
        thisLength = path_length;
    }
    else path_length = thisLength;
}

bool find_shortest_path(int** maze, int N, int** path, int& path_length) {
    seqStack<point*> pointSeq(N*N);
    point* p = new point(0, 0, N, maze);
    pointSeq.push(p);

    while(true)
    {
        int option = pointSeq.top()->NearOptions();
        //如果有返回一个可用的方向
        if(option == 0)
            p = new point(pointSeq.top()->getRow()+1, pointSeq.top()->getColumn(), N, maze);
        else if(option == 1)
            p = new point(pointSeq.top()->getRow(), pointSeq.top()->getColumn()+1, N, maze);
        else if(option == 2)
            p = new point(pointSeq.top()->getRow()-1, pointSeq.top()->getColumn(), N, maze);
        else if(option == 3)
            p = new point(pointSeq.top()->getRow(), pointSeq.top()->getColumn()-1, N, maze);
        //如果没有可用的方向，退回上一点进行下一次尝试
        else
        {
            //到达末尾就输出,然后继续操作
            if(pointSeq.top()->isFinal())
            {
                path_length = pointSeq.getLength();
                savePath(pointSeq, path, path_length);
            }
            
            //将所在点删除
            p = pointSeq.pop();
            delete p;
            
            //没有上一点则结束函数
            if(pointSeq.isEmpty())
            {
                if(path_length != 0) return true;
                else
                {
                    path[0] = new int;
                    path[1] = new int;
                    return false;
                }
            }
            //重新判断上一点
            else p = pointSeq.pop()->nextOption();
        }
        pointSeq.push(p);
    }
}

// main cannot be modified
int main() {
    // initialize
    int N;
    cin>>N;
    int **maze = new int*[N];
    for(int i =0; i < N; i++) {
        maze[i] = new int[N];
    }
    for(int i = 0;i < N; i++){
        for(int j = 0;j < N;j++){
            cin>>maze[i][j];
        }
    }

    // path should be an array of size [2][path_length]
    int **path = new int*[2];
    int path_length = 0;

    // should be finished
    if(find_shortest_path(maze, N, path, path_length)){
        for(int i = 0;i < path_length; i++){
            //path[0][i]: row
            //path[1][i]: column
            cout<<'('<<path[0][i]<<','<<path[1][i]<<')';
        }
        cout<<endl;
    }else{
        cout<<"Not found"<<endl;
    }

    // free memory
    for (int i = 0; i < N; i++)
    {
        delete []maze[i];
        maze[i] = NULL;
    }
    delete []maze;
    maze = NULL;
    for (int i = 0; i < 2; i++)
    {
        delete []path[i];
        path[i] = NULL;
    }
    delete []path;
    path = NULL;

    return 0;
}

