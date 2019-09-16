//class Money 向量类
#include <iostream>
using namespace std;

const int maxDigit = 10;

class Money
{
    friend istream & operator >> (istream & is, Money & obj);
    friend ostream & operator << (ostream & os, const Money & obj);
private:
    int group[maxDigit], digit;
public:
    //空构造函数（存在bug）
    Money()
    {
        //group = {0};
        digit = 1;
    }
    //构造函数
    Money(int grp[], int dgt)
    {
        digit = dgt;
        for (int i = 0; i < dgt; ++i)
        {
            group[i] = grp[i];
        }
    }
    //拷贝构造函数
    Money(const Money & obj)
    {
        digit = obj.digit;
        for (int i = 0; i < obj.digit; ++i)
        {
            group[i] = obj.group[i];
        }
    }
    //加法重载
    Money operator + (const Money & rightV)
    {
        Money result = rightV; //调用了一次拷贝构造函数
        for (int i = 0; i < digit; ++i)
        {
            result.group[i] = group[i] + rightV.group[i];
        }
        return result;
    }
    //减法重载
    Money operator - (const Money & rightV)
    {
        Money result = rightV; //调用了一次拷贝构造函数
        for (int i = 0; i < digit; ++i)
        {
            result.group[i] = group[i] - rightV.group[i];
        }
        return result;
    }
    //内积重载
    int operator * (const Money & rightV)
    {
        int result = 0;
        for (int i = 0; i < digit; ++i)
        {
            result += group[i] * rightV.group[i];
        }
        return result;
    }
};

//输入重载，【输入方案不好，无法按需输入】
istream & operator >> (istream & is, Money & obj)
{
    bool flag = true; char flag2;
    for (int i = 0; flag; ++i)
    {
        obj.group[i] = is.get() - 48;
        flag2 = is.get();
        if (flag2 == '\n') flag = false;
    }
    return is;
}
//输出重载
ostream & operator << (ostream & os, const Money & obj)
{
    os << '(';
    for (int i = 0; i < obj.digit; ++i) os << obj.group[i] << ',';
    os << ')';
    return os;
}

int main()
{
    cout << "Hello world!" << endl;
    int g1[] = {1, 2, 3}, g2[] = {4, 5, 6};
    Money v1(g1, 3), v2(g2, 3),
        v3(g2, 3);  //输入对应的对象，输入的向量维数须在这里指定（bug）
    cout << v1 << v2 << endl;
    cout << "v1 + v2 : " << v1 + v2 << endl;
    cout << "v1 - v2 : " << v1 - v2 << endl;
    cout << "v1 * v2 : " << v1 * v2 << endl;
    cout << "input Money（单个空格分开数字，最后一个数字后直接回车，维数只能为3）: " << endl;
    cin >> v3;
    cout << "v3' : " << v3 << endl;
    cout << "v1 + v3 : " << v1 + v3 << endl;
    return 0;
}
