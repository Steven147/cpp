//
//  sLinkString.h
//  2333
//
//  Created by Steven on 2019/10/18.
//  Copyright © 2019 Steven. All rights reserved.
//

#ifndef sLinkString_h
#define sLinkString_h

#endif /* sLinkString_h */
#include "iostream"

//线性表的抽象类
template <class elemType>
class list
{
public:
    virtual void clear() = 0;
    virtual int length() const = 0;
    virtual void insert(int i, const elemType &x) = 0;
    virtual void remove(int i) = 0;
    virtual int search(const elemType &x) const = 0 ;
    virtual elemType visit(int i) const = 0;
    virtual void traverse() const = 0;
    virtual ~list() {};
};

//单链表类定义
template <class elemType>
class sLinkString:public list<elemType>
{
    friend sLinkString<elemType> & getSuffix(const sLinkString<elemType> & string1, const sLinkString<elemType> & string2, sLinkString<elemType> & result)
    {
        for(int i = 1;
            string1.move(string1.length() - i)->data == string2.move(string2.length() - i)->data;
            ++i)
            result.insert(0, string1.move(string1.length() - i)->data);
        return result;
    }
private:
    struct node
    { //单链表中的结点类
        elemType data;
        node *next;
        node(const elemType &x, node *n = NULL)
        { data = x; next = n;}
        node():next(NULL) {}
        ~node() {}
    };
    node *head; //头指针
    int currentLength; //表长
    
    node * move(int i) const;//返回第i个结点的地址
public:
    sLinkString();
    sLinkString(elemType *);
    void clear() ;
    void insert(int, const elemType &);
    void remove(int );
    int search(const elemType &) const ;
    elemType visit(int) const;
    void traverse() const ;
    int erase(const elemType &, const elemType &);
    ~sLinkString()
    {
        clear();
        delete head;
    }
    int length() const
    {
        return currentLength;
    }
    
};


