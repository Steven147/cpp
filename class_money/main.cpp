/*
 编程实现货币的加减运算，要求：
 定义一个类RMB ，包含元、角、分三个数据成员，编写友元函数重载运算符‘+’ 和 ‘-’，以实现货币的加减运算
 如：
 
 input RMB1(yuan jiao fen)：1 2 7
 input RMB2(yuan jiao fen)：6 3 4
 Sum：7.61 yuan
 Difference：-5.07 yuan
 
 -----------------------
 
 功能实现
 1.接受任意大小的元，角，分并自动化简为正常表达形式。
 （数字之间用空格隔开，回车键停止输入）
 2.采用满10进位、遇负借10实现加法和减法
 3.实现输出
 
 */
#include <iostream>
using namespace std;

//const int maxDigit = 10;

class Money
{
    friend istream & operator >> (istream & is, Money & obj);
    friend ostream & operator << (ostream & os, const Money & obj);
    friend Money operator + (const Money & left, const Money & right);
    friend Money operator - (const Money & left, const Money & right);
private:
    int yuan, jiao, fen;
public:
    Money()
    {
        yuan = 0;
        jiao = 0;
        fen = 0;
    }
    // 化简函数
    Money & Simplify()
    {
        while(fen > 9)
        {
            fen -= 10;
            ++ jiao;
        }
        while(jiao > 9)
        {
            jiao -= 10;
            ++ yuan;
        }
        return *this;
    }
};
//加法重载:满10进位
Money operator + (const Money & left, const Money & right)
{
    Money tmp;
    cout << left << '+' << right << '=';
    tmp.fen += left.fen + right.fen;
    while(tmp.fen > 9)
    {
        tmp.fen -= 10;
        ++ tmp.jiao;
    }
    tmp.jiao += left.jiao + right.jiao;
    while(tmp.jiao > 9)
    {
        tmp.jiao -= 10;
        ++ tmp.yuan;
    }
    tmp.yuan += left.yuan + right.yuan;
    return tmp;
}
//减法重载:有负借10
Money operator - (const Money & left, const Money & right)
{
    Money tmp;
    cout << left << '-' << right << '=';
    if (
        (left.yuan > right.yuan) or
        (left.yuan == right.yuan and left.jiao > right.jiao) or
        (left.jiao == right.jiao and left.fen > right.fen)
        )
    {
        tmp.fen += left.fen - right.fen;
        while(tmp.fen < 0)
        {
            tmp.fen += 10;
            -- tmp.jiao;
        }
        tmp.jiao += left.jiao - right.jiao;
        while(tmp.jiao < 0)
        {
            tmp.jiao += 10;
            -- tmp.yuan;
        }
        tmp.yuan += left.yuan - right.yuan;
    }
    else
    {
        tmp.fen -= left.fen - right.fen;
        while(tmp.fen < 0)
        {
            tmp.fen += 10;
            -- tmp.jiao;
        }
        tmp.jiao -= left.jiao - right.jiao;
        while(tmp.jiao < 0)
        {
            tmp.jiao += 10;
            -- tmp.yuan;
        }
        tmp.yuan -= left.yuan - right.yuan;
        
        tmp.yuan = -tmp.yuan;
    }
    return tmp;
}
//输入重载,自动化简
istream & operator >> (istream & is, Money & obj)
{
    char now = ' ';
    int money[3] = {0, 0, 0};
    for (int i = 0; now != '\n'; )//遇到回车键输出
    {
        now = is.get();//读一个字符
        
        if (now >= '0' and now <= '9')//将数字逐位存入
        {
            money[i] = money[i] * 10 + now - '0';
        }
        else if (now == ' ') ++i;//遇到空格读取下一位数字
    
    }
    obj.yuan = money[0];
    obj.jiao = money[1];
    obj.fen = money[2];
    
    obj.Simplify();
    
    return is;
}
//输出重载
ostream & operator << (ostream & os, const Money & obj)
{
    os << obj.yuan << '.' << obj.jiao << obj.fen;
    return os;
}

int main()
{
    Money RMB1, RMB2;
    cout << "input RMB1(yuan jiao fen)：";
    cin >> RMB1;
    cout << "input RMB2(yuan jiao fen)：";
    cin >> RMB2;
    
    cout << "Sum: " << RMB1 + RMB2 << " yuan" << endl;
    cout << "Difference: " << RMB1 - RMB2 << " yuan" << endl;
    return 0;
}
