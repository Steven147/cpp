/*
 Problem 1
 在单链表类中增加一个功能erase(x, y), 删除表中所有值在 [x, y] 之间的结点。假设链表中结点数值类型是整形，要求编程返回删除相应结点后的链表长度和链表元素。并分析该程序的时间复杂度和空间复杂度。
 
 输入描述
 第一行输入链表List的结点元素值，元素之间用空格间隔，且均为int类型；
 第二行输入为x和y，分别表示需要删除结点元素的最小值和最大值。
 输出描述
 第一行输出删除相应结点后链表的长度；
 第二行输出删除相应结点后链表的所有元素，元素之间用空格间隔。
 
 测试结果
 10 2 71 8 4 35
 0 5
 4
 10 71 8 35
 Program ended with exit code: 0

 10 2 71 8 4 35 11
 3 11
 3
 2 71 35
 Program ended with exit code: 0
 
 10 0 2 71 8 4 35 11
 0 71
 0
 
 Program ended with exit code: 0
 
 10 0 2 71 8 4 35 11
 2 2
 7
 10 0 71 8 4 35 11
 Program ended with exit code: 0
 
 10 0 2 71 8 4 35 11
 5 6
 8
 10 0 2 71 8 4 35 11
 Program ended with exit code: 0
 
 
 需要提交的文件须包括sLinkList.cpp、sLinkList.h、main.cpp三个C++文件和problem1.pdf。
 
 其中，main.cpp文件中需要包含 "main" 函数。程序执行将在此文件开始并结束。problem1.pdf中对该程序的时间复杂度和空间复杂度进行分析。
 */

#include "sLinkList.cpp"
using namespace std;

int main()
{
    int iniList, i = 0;
    int range[3] = {0, 0, '\0'};
    sLinkList<int> myList;
    bool flag = true;//判断是否读到回车
    
    //对单链表进行初始化
    while (flag and cin >> iniList)
    {
        myList.insert(myList.length(), iniList);
        flag = cin.get()!='\n';//读到回车则下一次循环前跳出
    }
    flag = true;
    
    //储存所需范围
    while (flag and cin >> iniList)
    {
        range[i] = iniList;
        ++i;
        flag = cin.get()!='\n';
    }
    //去除范围内的值，并且返回处理后链表的长度
    cout << myList.erase(range[0], range[1]) << endl;
    myList.traverse();//遍历
    
    return 0;
}

