#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>

template<class T>
class bTree
{
public:
    virtual void clear() = 0;
    virtual bool isEmpty() const = 0;
    virtual T Root(T flag) const = 0;
    virtual T parent(T x, T flag) const = 0;
    virtual T lchild(T x, T flag) const = 0;
    virtual T rchild(T x, T flag) const = 0;
    virtual void delLeft(T x) = 0;
    virtual void delRight(T x) = 0;
    virtual void preOrder() const = 0;
    virtual void midOrder() const = 0;
    virtual void postOrder() const= 0;
    virtual void levelOrder() const = 0;
};

template <class elemType> class queue
{
public:
    virtual bool isEmpty() = 0;
    virtual void enQueue(const elemType &x) = 0;
    virtual elemType deQueue() = 0;
    virtual elemType getHead() = 0;
    virtual ~queue() {}
};

template<class T>
class binaryTree : public bTree<T>
{
    friend void printTree(const binaryTree &t, T flag);
private:
    //二叉树的结点类
    struct Node
    {
        Node *left , *right ;
        T data;
        Node() : left(NULL), right(NULL) { }
        Node(T item, Node *L = NULL, Node * R =NULL ):
        data(item), left(L), right(R) {}
        ~Node(){}
    };
    Node *root;
    
private:
    Node *find(T x, Node *t ) const;
    void clear(Node *&t) ;
    void preOrder(Node *t) const;
    void midOrder(Node *t) const;
    void postOrder(Node *t) const;

public:
    binaryTree() : root(NULL) {}
    binaryTree(T x) { root = new Node(x); }
    ~binaryTree();
    void clear() ;
    bool isEmpty() const;
    T Root(T flag) const;
    T lchild(T x, T flag) const;
    T rchild(T x, T flag) const;
    void delLeft(T x) ;
    void delRight(T x);
    void preOrder() const;
    void midOrder() const;
    void postOrder() const;
//    void levelOrder() const;
    void createTree(T flag);
    T parent(T x, T flag) const { return flag; }
};


template <class elemType>
class linkQueue: public queue<elemType>
{
private:
    struct node
    {
        elemType data;
        node *next;
        node(const elemType &x, node *N = NULL)
        { data = x; next = N;}
        node():next(NULL) {}
        ~node() {}
    };
    node *front, *rear;
public:
    linkQueue();
    ~linkQueue();
    bool isEmpty() const
    { return front == NULL; }
    void enQueue(const elemType &x)
    {
        if (rear == NULL)
            front = rear = new node(x);
        else
            rear = rear->next = new node(x);
    }
    elemType deQueue() ;
    elemType getHead() const;
};
    
    
    
    
#endif
