# 数据结构 C++编程 g++/Ubuntu环境编译

## 程序测试环境

[g++入门教程](https://cloud.tencent.com/developer/article/1176744)

为了保证能正确通过我们提供的测试用例，以Linux平台的g++编译器（Windows平台g++编译器也不必担心）和Problem 3为例，测试过程的编译运行情况举例将如下：

``` terminal
test@ubuntu:~/problem3$ g++ binaryTree.cpp main.cpp -o problem3
test@ubuntu:~/problem3$ ./problem3
```

## 多文件编译

[C语言基础：多文件编译](https://blog.csdn.net/walle2018/article/details/79765330)

1. include命令，将目标文件完完整整的复制过来，没有任何其他的作用

```C
//myhead.h
#ifndef __myhead_h
#define __myhead_h
void fn();
#endif
//main.cpp
#include "myhead.h"
void main(){
    fn();
    return 0;
}

//等价于合写的main.cpp
void fn();
int main(){
    fn();
    return 0;
}
```

2. 链接命令？

``` c
/* ioput.h 输入输出部分头文件*/ 
#include <stdio.h>
//读取用户输入的年份
int input_year(void);
//读取用户输入的月份
int input_month(void);
//显示日历
void output_days(int year, int month, int week, int is_leap_year);
```

```c 
/* ioput.c 输入输出部分实现文件，包含输入输出部分头文件*/
#include "ioput.h"
//读取用户输入的年份
int input_year(void)
{ 
    
}
//读取用户输入的月份
int input_month(void)
{ 

}
//显示日历
void output_days(int year, int month, int week, int is_leap_year)
{ 

}
```

```c
/* calc.h 计算部分头文件，包含输入输出部分头文件*/
#include "ioput.h"
//蔡勒公式计算星期，只适合于1582年10月15日之后的日期
int calc_week(int year, int month, int day);
//计算闰年
int calc_leap_year(int year);
//日历核心函数
void calc_core(void);
```

```c
/* calc.c 计算部分实现文件，包含计算部分头文件*/
#include "calc.h"

//蔡勒公式计算星期，只适合于1582年10月15日之后的日期
int calc_week(int year, int month, int day)
{
	
}
//计算闰年
int calc_leap_year(int year)
{
	
}
//日历核心函数
void calc_core(void)
{
	
}
```
```c
/* main.c 程序入口*/
#include "calc.h"
int main(int argc, char *argv[])
{
	calc_core();
	return 0;
}

```