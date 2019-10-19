//
//  sLinkString.cpp
//  2333
//
//  Created by Steven on 2019/10/18.
//  Copyright © 2019 Steven. All rights reserved.
//

#include "sLinkString.h"
#include "iostream"

using namespace std;

template <class elemType>
sLinkString<elemType>::sLinkString()
{
    head = new node;//指向节点类型的指针
    currentLength = 0;
}

//使用数组构造
template <class elemType>
sLinkString<elemType>::sLinkString(elemType *arr)
{
    head = new node;
    int i;
    //将数组的第i位赋值给对应的节点
    for(i = 0; arr[i] != '\0'; ++i)
        insert(i, arr[i]);
    currentLength = i;
}

//clear
template <class elemType>
void sLinkString<elemType>::clear()
{
    node *p = head->next, *q;
    head->next = NULL;
    while (p != NULL)//删除链表中的所有结点
    {
        q = p->next;
        delete p;
        p = q;
    }
    currentLength = 0;
}

//move 返回指向第i个节点的指针，第-1个节点是头节点，第0个节点是头节点的下一个节点
template <class elemType>
typename sLinkString<elemType>::node * sLinkString<elemType>::move(int i) const
{
    node *p = head;//指针初始化为头指针，指向头节点
    while(i-- >= 0) p = p->next;
    return p;
}

//insert 在第i个节点上插入，头节点下一个节点为0节点
template <class elemType>
void sLinkString<elemType>::insert(int i, const elemType &x)
{
    node *pos;
    pos = move(i - 1);
    pos->next = new node(x,pos->next);
    ++currentLength;
}

//remove
template <class elemType>
void sLinkString<elemType>::remove(int i)
{
    node *pos, *delp;
    pos = move(i - 1);
    delp = pos->next;
    pos->next = delp->next;// 绕过delp
    delete delp;
    --currentLength;
}

//search
template <class elemType>
int sLinkString<elemType>::search(const elemType &x) const {
    node *p = head->next;
    int i = 0;
    while (p != NULL && p->data != x) {p = p->next; ++i;}
    if (p == NULL) return -1;
    else return i;
}

//visit
template <class elemType>
elemType sLinkString<elemType>::visit(int i) const
{
    return move(i)->data;
}

//traverse
template <class elemType>
void sLinkString<elemType>::traverse() const
{
    node *p = head->next;
    while (p != NULL) {
        cout << p->data;
        p=p->next;
    }
    cout << endl;
}
//template <class elemType>
//sLinkString<elemType> & sLinkString<elemType>::getSuffix(const sLinkString<elemType> & string1, const sLinkString<elemType> & string2, sLinkString<elemType> & result)
//{
//    for(int i = 0;
//        string1.move(string1.length() - i)->data == string2.move(string2.length() - i)->data;
//        ++i)
//        result.insert(i, string1.move(string1.length() - i)->data);
//    return & result;
//}
