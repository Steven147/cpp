#include "binaryTree.h"
#include <iostream>
using namespace std;


//队列的链表实现
template <class elemType>
class linkQueue
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
    linkQueue()
    { front = rear = NULL; }
    ~linkQueue()
    {
        node *tmp;
        while (front != NULL)
        {
            tmp = front;
            front = front->next;
            delete tmp;
        }
    }
    bool isEmpty() const
    { return front == NULL; }
    void enQueue(const elemType &x)
    {
        if (rear == NULL)
            front = rear = new node(x);
        else
            rear = rear->next = new node(x);
    }
    elemType deQueue()
    {
        node *tmp = front;
        elemType value = front->data;
        front = front->next;
        if (front == NULL) rear = NULL;
        delete tmp;
        return value;
    }
    elemType getHead() const
    { return front->data; }
};



//二叉树成员函数实现
template <class T>
bool binaryTree<T>::isEmpty() const
{ return root == NULL; }

template <class T>
T binaryTree<T>::Root(T flag) const
{
    if (root == NULL) return flag;
    else return root->data;
}

template<class T>
void binaryTree<T>::clear(binaryTree<T>::Node* &t)
{
    if (t == NULL) return;
    clear(t->left); clear(t->right);
    delete t;
    t = NULL;
}

template<class T>
void binaryTree<T>::clear()
{ clear(root); }

template <class T>
binaryTree<T>::~binaryTree()
{ clear(root); }

//template<class T>
//void binaryTree<T>::preOrder(binaryTree<T>::Node *t) const
//{
//    if (t == NULL) return;
//    cout << t->data << ' ';
//    preOrder(t->left);
//    preOrder(t->right);
//}

template<class T>
void binaryTree<T>::preOrder(T* Order, binaryTree<T>::Node *t) const
{
    if (t == NULL) return;
    int i;
    for(i = 0; *(Order+i) != 0; ++i);
    *(Order+i) = t->data;
    preOrder(Order, t->left);
    preOrder(Order, t->right);
}

template<class T>
void binaryTree<T>::preOrder(T* Order) const
{ preOrder(Order, root); }

//template<class T>
//void binaryTree<T>::midOrder(binaryTree<T>::Node *t) const
//{
//    if (t == NULL) return;
//    midOrder(t->left);
//    cout << t->data << ' ';
//    midOrder(t->right);
//}

template<class T>
void binaryTree<T>::midOrder(T* Order, binaryTree<T>::Node *t) const
{
    
    if (t == NULL) return;
    midOrder(Order, t->left);
    int i;
    for(i = 0; *(Order+i) != 0; ++i);
    *(Order+i) = t->data;
    midOrder(Order, t->right);
}

template<class T>
void binaryTree<T>::midOrder(T* Order) const
{ midOrder(Order, root); }



//template<class T>
//void binaryTree<T>::postOrder(binaryTree<T>::Node *t) const
//{
//    if (t == NULL) return;
//    postOrder(t->left);
//    postOrder(t->right);
//    cout << t->data << ' ';
//}

template<class T>
void binaryTree<T>::postOrder(T* Order, binaryTree<T>::Node *t) const
{
    if (t == NULL) return;
    postOrder(Order, t->left);
    postOrder(Order, t->right);
    int i;
    for(i = 0; *(Order+i) != 0; ++i);
    *(Order+i) = t->data;
}



template<class T>
void binaryTree<T>::postOrder(T* Order) const
{ postOrder(Order, root); }





template <class T>
typename binaryTree<T>::Node* binaryTree<T>::find(T x, binaryTree<T>::Node *t) const
{
    Node *tmp;
    if (t == NULL) return NULL;
    if (t->data == x) return t;
    if ((tmp = find(x, t->left))) return tmp;
    else return find(x, t->right);
}

template <class T>
void binaryTree<T>::delLeft(T x)
{
    Node *tmp = find(x, root);
    if (tmp == NULL) return;
    clear(tmp->left);
}

template <class T>
void binaryTree<T>::delRight(T x)
{
    Node *tmp = find(x, root);
    if (tmp == NULL) return;
    clear(tmp->right);
}

template <class T>
T binaryTree<T>::lchild(T x, T flag) const
{
    Node * tmp = find(x, root);
    if (tmp == NULL || tmp->left == NULL) return flag;
    return tmp->left->data;
}

template<class T>
T binaryTree<T>::rchild(T x, T flag) const
{
    Node *tmp = find(x, root);
    if (tmp == NULL || tmp->right == NULL) return flag;
    return tmp->right->data;
}

template <class Type>
void binaryTree<Type>::createTree(Type num, Type** nodes)
{
    linkQueue<Node*> que;
    Node *tmp;
    root = new Node(nodes[0][0]);
    que.enQueue(root);
    
    for(int i = 0; i < num; ++i)
    {
        tmp = que.deQueue();
        int lpos = nodes[i][1], rpos = nodes[i][2];
        if(lpos != -1)
            que.enQueue(tmp->left = new Node(nodes[lpos][0]));
        if(rpos != -1)
            que.enQueue(tmp->right = new Node(nodes[rpos][0]));
    }

}
