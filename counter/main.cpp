/*
 1. 对报警计数器函数进行修改，要求：
 可对输入时设定的报警值（非负）进行报警。计数器从0开始计数，到达报警值时发出警告。
 如：
 Warning value：5
 1
 2
 3
 4
 Warning：5！
 */

#include <iostream>
#include <time.h>
using namespace std;

void delay(int sec)
{
    time_t start_time, cur_time; // 变量声明
    time(&start_time);
    do { time(&cur_time);
    } while((cur_time - start_time) < sec );
}

int main()
{
    int number = 0;
    cout << "please enter a integer: ";
    cin >> number; //将数字读入
    
    char next = cin.get();//读取末尾标识符
    if (
        (next != '\n' and
         next != '\t' and
         next != ' ') or
        number <= 0
        )//若输入不符合要求，或数字为负
    {
        cout << "Error!" << endl;
        return -1;
    }
    else
    {
        for (int i = 1; i <= number; ++i)
        {
            delay(1);
            if (i == number) cout << "Warning: " << number << " !" << endl;
            else cout << i << endl;
        }
        return 0;
    }
}
