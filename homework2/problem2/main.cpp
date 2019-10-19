/*
Problem 2
假定用带头结点的单链表保存单词，当两个单词有相同的后缀时，则可以共享后缀存储空间。
 要求编程找出两个单词共同后缀的起始位置，并输出共同后缀的值（两个单词均不为空值，字母均视为小写）。
并分析该程序的时间复杂度和空间复杂度。
 
输入输出测试

lOaDiNg
BeInG
ing
Program ended with exit code: 0

homewoRk
worK
work
Program ended with exit code: 0

useless
NAMELESS
eless
Program ended with exit code: 0
 */

#include "sLinkString.cpp"

int main()
{
    sLinkString<char> myString1, myString2, myString3;
    int iniString;
    
    do//获取第一个单词
    {
        iniString = cin.get();
        if(iniString >= 'a' && iniString <= 'z') myString1.insert(myString1.length(), iniString);
        else if(iniString >= 'A' && iniString <= 'Z') myString1.insert(myString1.length(), iniString - 'A' + 'a');
    }
    while(iniString != '\n');
    do//获取第二个单词
    {
        iniString = cin.get();
        if(iniString >= 'a' && iniString <= 'z') myString2.insert(myString2.length(), iniString);
        else if(iniString >= 'A' && iniString <= 'Z') myString2.insert(myString2.length(), iniString - 'A' + 'a');
    }
    while(iniString != '\n');
    
    getSuffix(myString1, myString2, myString3);
    
    myString3.traverse();
    
    return 0;
}

