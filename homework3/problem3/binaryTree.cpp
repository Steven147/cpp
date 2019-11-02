#include "binaryTree.h"
using namespace std;

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

template <class T> binaryTree<T>::~binaryTree()
{ clear(root); }

template<class T>
void binaryTree<T>::preOrder(binaryTree<T>::Node *t) const
{
    if (t == NULL) return;
    cout << t->data << ' ';
    preOrder(t->left);
    preOrder(t->right);
}
template<class T>
void binaryTree<T>::preOrder() const
{ preOrder(root); }

template<class T>
void binaryTree<T>::midOrder(binaryTree<T>::Node *t) const
{
    if (t == NULL) return;
    midOrder(t->left);
    cout << t->data << ' ';
    midOrder(t->right);
}

template<class T>
void binaryTree<T>::midOrder() const
{ midOrder(root); }

template<class T>
void binaryTree<T>::postOrder(binaryTree<T>::Node *t) const
{
    if (t == NULL) return;
    postOrder(t->left);
    postOrder(t->right);
    cout << t->data << ' ';
}

template<class T>
void binaryTree<T>::postOrder() const
{ postOrder(root); }

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



template <class elemType>
linkQueue<elemType>::linkQueue()
{ front = rear = NULL; }


template <class elemType>
elemType linkQueue<elemType>::deQueue()
{
    node *tmp = front;
    elemType value = front->data;
    front = front->next;
    if (front == NULL) rear = NULL;
    delete tmp;
    return value;
}



template <class elemType>
elemType linkQueue<elemType>::getHead() const
{ return front->data; }


//template <class Type>
//void binaryTree<Type>::createTree(Type flag)
//{
//    linkQueue<Node*> que;
//    Node *tmp;
//    Type x, ldata, rdata;
//    //创建树，输入flag表示空
//    cout << "\n输入根结点:";
//    cin >> x;
//    root = new Node(x);
//    que.enQueue(root);
//    while (!que.isEmpty())
//    {
//        tmp = que.deQueue();
//        cout << "\n输入" << tmp->data << "的两个儿子(" << flag << "表示空结点):";
//        cin >> ldata >> rdata;
//        if (ldata != flag)
//        que.enQueue(tmp->left = new Node(ldata));
//        if (rdata != flag)
//        que.enQueue(tmp->right = new Node(rdata));
//    }
//    cout << "create completed!\n";
//}



