#ifndef Stack_h
#define Stack_h

#include <stdio.h>

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
private:
    elemType *elem;
    int top_p;
    int maxSize;
    void doubleSpace();
public:
    seqStack(int initSize = 10) ;
    ~seqStack();
    bool isEmpty() const;
    void push(const elemType &x) ;
    elemType pop();
    elemType top() const;
    
    int getLength() {return top_p + 1;}
    elemType* getElem() {return elem;}
};


#endif /* Stack_h */


