/*
 Problem 3
 编程实现中缀算术表达式转后缀算术表达式。(注：先要对算术表达式进行符号平衡检查）
 
 输入描述
 
 第一行输入中缀算数表达式，数字均为int类型，运算符只考虑加减乘除四则运算和小括号，不考虑int中的负数。
 
 输出描述
 
 第一行输出后缀算数表达式。
 
 输入举例
 
 5*(7-2*3)+10/4
 注意：输入中数字和运算符之间可能不存在空格，需自行分割。
 输出举例
 
 5 7 2 3 * - * 10 4 / +
 注意：输出的数值和运算符之间均用空格分隔。
 注意:输入输出前面不要添加多余前缀，如“input:”、“output:”等内容
 需要提交的文件
 
 须包括Stack.cpp、Stack.h、main.cpp三个文件。
 
 其中，main.cpp文件中需要包含 "main" 函数。程序执行将在此文件开始并结束。
 */

#include "Stack.h"
#include "Stack.cpp"

int main()
{
    ifstream min;
    ofstream mout;
    
    mout.open("File");
    char str[30];
    cin >> str;
    mout << str;
    mout.close();
    
    balance myBalance("File");
    if(myBalance.CheckBalance() > 0) return -1;
    
    seqStack<char> myStack;
    mid2last(str, myStack);
    
    return 0;
}

