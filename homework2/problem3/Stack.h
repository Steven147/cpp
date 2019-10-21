//
//  Stack1.hpp
//  2333
//
//  Created by Steven on 2019/10/20.
//  Copyright © 2019 Steven. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

#include <stdio.h>
#include "fstream"
#include "iostream"

using namespace std;

//栈的抽象类
template <class elemType>
class stack
{
public:
    virtual bool isEmpty() const = 0;
    virtual void push(const elemType &x) = 0;
    virtual elemType pop() = 0;
    virtual elemType top() const = 0;
    virtual ~stack() {}
};

template <class elemType>
class seqStack: public stack<elemType>
{
    friend void mid2last(elemType * items, seqStack<elemType> & myStack)
    {
        for(int i = 0; *(items + i) != '\0'; ++i)
        {
            if( *(items + i) >= '0' and *(items + i) <= '9' and *(items + i + 1) >= '0' and *(items + i + 1) <= '9') {
                cout << *(items + i) << *(items + i + 1) << ' ';
                ++i;
            }
            else if ( *(items + i) >= '0' and *(items + i) <= '9' and !(*(items + i + 1) >= '0' and *(items + i + 1) <= '9')) cout << *(items + i) << ' ';
            else if(*(items + i) == '(') myStack.push(*(items + i));
            else if(*(items + i) == ')')
            {
                while(myStack.top() != '(') cout << myStack.pop() << ' ';
                myStack.pop();
            }
            
            else if( *(items + i) == '+' or *(items + i) == '-' or *(items + i) == '*' or *(items + i) == '/')
            {
                while(  (*(items + i) == '+' or *(items + i) == '-')
                      and
                      (myStack.top() == '*' or myStack.top() == '/')  ) cout << myStack.pop() << ' ';
                
                while(  (*(items + i) == '*' or *(items + i) == '/') and (myStack.top() == '*' or myStack.top() == '/')) cout << myStack.pop() << ' ';
                myStack.push(*(items + i));
            }
            
        }
        while(!myStack.isEmpty()) cout << myStack.pop() << ' ';
    }
private:
    elemType *elem; int top_p;
    int maxSize;
    void doubleSpace();
public:
    seqStack(int initSize = 10) ;
    ~seqStack();
    bool isEmpty() const;
    void push(const elemType &x) ;
    elemType pop();
    elemType top() const;
    
};


class noFile {}; //输入文件不存在

//括号配对类：对象初始化时传给它一个源文件名
class balance
{
private:
    ifstream fin;//待检查的文件流
    int currentLine;//正在处理行的的行号
    int Errors; //已发现的错误数
    struct Symbol { char Token; int TheLine;}; //栈元素
    enum CommentType { SlashSlash, SlashStar }; //注释
    
    bool CheckMatch(char Symb1, char Symb2, int Line1, int Line2 )
    { if ( (Symb1 == '(' && Symb2 != ')')
          || (Symb1 == '[' && Symb2 != ']') ||(Symb1 == '{' && Symb2 != '}')) {
//        cout << "发现第" << Line2 << "的符号"
//        << Symb2 << "与第" << Line1
//        << "的符号" << Symb1 << "不匹配\n";
        return false; }
        else return true; }

    char GetNextSymbol()
    { char ch;
        while ( (ch = NextChar()) ) { if ( ch == '/') {
            ch = NextChar();
            if ( ch == '*' ) SkipComment( SlashStar );
            else if ( ch == '/' ) SkipComment( SlashSlash );
            else PutBackChar ( ch); }
        else if (ch == '\\' || ch == '"') SkipQuote( ch); else if(ch=='{'||ch=='['|| ch=='('||ch==')'
                                                                  || ch == ']' || ch == '}') return ch;
        }
        return NULL; // 文件结束。
    }
    void PutBackChar(char ch){ fin.putback(ch) ;
        if ( ch == '\n') currentLine --; }
    void SkipComment(enum CommentType type){ char ch, flag;
        if ( type == SlashSlash ) {
            while ( (ch = NextChar()) && ( ch != '\n') )
                return;
        }
        //处理/*...*/的情况
        flag = ' ';
        while( (ch = NextChar() ) != NULL){
            if(flag=='*'&&ch=='/') return;
            flag = ch; }
        Errors++;
        cout << "Comment is unterminated!" << endl; }
    void SkipQuote(char type) { char ch;
        while ((ch = NextChar()) ) { if (ch == type) return;
        else if (ch == '\n') { Errors++;
            cout << "missing closing quote at line " << currentLine << endl;
            return; }
        else if (ch == '\\') ch = NextChar(); //跳过转义字符
        }
    }
    char NextChar(){ char ch;
        if ((ch = fin.get()) == EOF) return NULL; if ( ch == '\n') currentLine++;
        return ch;}
public:
    balance(const char *s)
    {
        fin.open(s);
//        char str[20];
//        fin >> str;
        if (!fin) throw noFile();
        currentLine = 1;
        Errors = 0;
    }
    
    int CheckBalance() //检查输入流对象中的括号是否匹配
    {
        struct Symbol node;
        seqStack<Symbol> st;
        char LastChar, Match;  //LastChar为读入的符号，Match为栈顶的符号
        
        while( (LastChar = GetNextSymbol()) )
        {
            switch ( LastChar )
            {
                case '(': case '[': case '{': node.Token = LastChar; node.TheLine = currentLine; st.push(node); break;
                case ')': case ']': case '}':
                    if (st.isEmpty())
                    {
                        Errors++;
//                        cout << "在第" << currentLine
//                        << "有一个多余的 " << LastChar << endl;
                        
                    }
                    else
                    {
                        node = st.pop(); Match = node.Token;
                        if (!CheckMatch( Match, LastChar, node.TheLine, currentLine)) ++Errors;
                    }
                    break;
            }
        }
        while( !st.isEmpty()) { Errors++;
            node = st.pop();
//            cout << "第" << node.TheLine
//            << "行的符号" << node.Token
//            << "不匹配\n";
            
        }
        return Errors;
    }
};

#endif /* Stack_hpp */
