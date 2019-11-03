# 数据结构 C++编程 g++/Ubuntu环境编译

## 程序测试环境

[g++入门教程](https://cloud.tencent.com/developer/article/1176744)

为了保证能正确通过我们提供的测试用例，以Linux平台的g++编译器（Windows平台g++编译器也不必担心）和Problem 3为例，测试过程的编译运行情况举例将如下：

``` t
test@ubuntu:~/problem3$ g++ binaryTree.cpp main.cpp -o problem3
test@ubuntu:~/problem3$ ./problem3

```

## 多文件编译

[C语言基础：多文件编译](https://blog.csdn.net/walle2018/article/details/79765330)

``` c
/* ioput.h */
#include <stdio.h>
//读取用户输入的年份
int input_year(void);
//读取用户输入的月份
int input_month(void);
//显示日历
void output_days(int year, int month, int week, int is_leap_year);
 
 
/* ioput.c */
#include "ioput.h"
//读取用户输入的年份
int input_year(void)
{ }
//读取用户输入的月份
int input_month(void)
{ }
//显示日历
void output_days(int year, int month, int week, int is_leap_year)
{ }
 
 
/* calc.h */
#include "ioput.h"
//蔡勒公式计算星期，只适合于1582年10月15日之后的日期
int calc_week(int year, int month, int day);
//计算闰年
int calc_leap_year(int year);
//日历核心函数
void calc_core(void);
 
 
/* calc.c */
#include "calc.h"
//蔡勒公式计算星期，只适合于1582年10月15日之后的日期
int calc_week(int year, int month, int day)
{
	if (month <= 2)
	{
		month += 12;
		year--;
	}
	int century = year / 100;
	year %= 100;
	int days = (year + year / 4 + century / 4 - 2 * century + 26 * (month + 1) / 10 + day - 1) % 7;
	while (days < 0)
	{
		days += 7;
	}
	return days;
}
//计算闰年
int calc_leap_year(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		return 1;
	}
	return 0;
}
//日历核心函数
void calc_core(void)
{
	do
	{
		int year = input_year();
		if (year <= 1582)
		{
			break;
		}
		int month = input_month();
		if (month <= 0 || month >= 13)
		{
			break;
		}
		int is_leap_year = calc_leap_year(year);
		int week = calc_week(year, month, 1);
		month--;
		output_days(year, month, week, is_leap_year);
	}
	while (1);
}
 
/* main.c */
#include "calc.h"
int main(int argc, char *argv[])
{
	calc_core();
	return 0;
}

```