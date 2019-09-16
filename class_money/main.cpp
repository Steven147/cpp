/*
 编程实现货币的加减运算，要求：
 定义一个类RMB ，包含元、角、分三个数据成员，编写友元函数重载运算符‘+’ 和 ‘-’，以实现货币的加减运算
 如：
 
 input RMB1(yuan jiao fen)：1 2 7
 input RMB2(yuan jiao fen)：6 3 4
 Sum：7.61 yuan
 Difference：-5.07 yuan
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
    //空构造函数（存在bug）
    Money()
    {
        yuan = 0;
        jiao = 0;
        fen = 0;
        //yuan, jiao, fen = 0, 0, 0;
    }
};
//加法重载
Money operator + (const Money & left, const Money & right)
{
    Money tmp;
    tmp.fen += left.fen + right.fen;
    if(tmp.fen > 9)
    {
        tmp.fen -= 10;
        ++ tmp.jiao;
    }
    tmp.jiao += left.jiao + right.jiao;
    if(tmp.jiao > 9)
    {
        tmp.jiao -= 10;
        ++ tmp.yuan;
    }
    tmp.yuan += left.yuan + right.yuan;
    return tmp;
}
//减法重载
Money operator - (const Money & left, const Money & right)
{
    Money tmp;
    if (
        (left.yuan > right.yuan) or
        (left.yuan == right.yuan and left.jiao > right.jiao) or
        (left.jiao == right.jiao and left.fen > right.fen)
        )
    {
        tmp.fen += left.fen - right.fen;
        if(tmp.fen < 0)
        {
            tmp.fen += 10;
            -- tmp.jiao;
        }
        tmp.jiao += left.jiao - right.jiao;
        if(tmp.jiao < 0)
        {
            tmp.jiao += 10;
            -- tmp.yuan;
        }
        tmp.yuan += left.yuan - right.yuan;
    }
    else
    {
        tmp.fen -= left.fen - right.fen;
        if(tmp.fen < 0)
        {
            tmp.fen += 10;
            -- tmp.jiao;
        }
        tmp.jiao -= left.jiao - right.jiao;
        if(tmp.jiao < 0)
        {
            tmp.jiao += 10;
            -- tmp.yuan;
        }
        tmp.yuan -= left.yuan - right.yuan;
        
        tmp.yuan = -tmp.yuan;
    }
    return tmp;
}
//输入重载
istream & operator >> (istream & is, Money & obj)
{
    char now = ' ';
    int money[3] = {0, 0, 0};
    for (int i = 0; now != '\n'; ++i)
    {
        now = is.get();
        if (now >= '0' and now <= '9')
        {
            money[i] = now - '0';
        }
        else -- i;
    }
    obj.yuan = money[0];
    obj.jiao = money[1];
    obj.fen = money[2];
    
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
