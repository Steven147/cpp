#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>

template<class T>
class binaryTree
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
//    void preOrder(Node *t) const;
//    void midOrder(Node *t) const;
//    void postOrder(Node *t) const;

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
    void preOrder(T* Order) const;
    void midOrder(T* Order) const;
    void postOrder(T* Order) const;
    void preOrder(T* Order, Node *t) const;
    void midOrder(T* Order, Node *t) const;
    void postOrder(T* Order, Node *t) const;
    
//    void levelOrder() const;
//    void createTree(T flag);
    void createTree(T num, T** nodes);
//    T parent(T x, T flag) const { return flag; }
};



    
    
    
    
#endif
