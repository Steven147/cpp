#ifndef sLinkList_h
#define sLinkList_h
#endif /* sLinkList_hpp */
#include "iostream"
using namespace std;

//线性表的抽象类
template <class elemType>
class list
{ public:
    virtual void clear() = 0;
    virtual int length() const = 0;
    virtual void insert(int i, const elemType &x) = 0; virtual void remove(int i) = 0;
    virtual int search(const elemType &x) const = 0 ; virtual elemType visit(int i) const = 0;
    virtual void traverse() const = 0;
    virtual ~list() {};
};

//单链表类定义
template <class elemType>
class sLinkList:public list<elemType>
{
    friend istream & operator >> (istream & is, sLinkList & obj);
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
    sLinkList();
    sLinkList(elemType *arr);
    void clear() ;
    void insert(int i, const elemType &x);
    void remove(int i);
    int search(const elemType &x) const ;
    elemType visit(int i) const;
    void traverse() const ;
    int erase(const elemType &x, const elemType &y);
    
    ~sLinkList() {clear(); delete head; }
    int length() const
    {
        return currentLength;
    }
};
