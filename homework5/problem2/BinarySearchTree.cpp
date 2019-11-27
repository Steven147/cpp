#include "BinarySearchTree.h"


template <class KEY, class OTHER>
BinarySearchTree<KEY, OTHER>::BinarySearchTree()
{ }

template <class KEY, class OTHER>
BinarySearchTree<KEY, OTHER>::~BinarySearchTree()
{ }



template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::insert( const SET<KEY,OTHER> & x )
{ insert( x, root ); }
template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::insert( const SET<KEY,OTHER> & x, BinaryNode *&t )
{
    if( t == nullptr ) t = new BinaryNode( x, nullptr, nullptr );
    else if( x.key < t->data.key ) insert( x, t->left );
    else if( t->data.key < x.key ) insert( x, t->right );
}

template <class KEY, class OTHER> void BinarySearchTree<KEY,OTHER>::remove( const KEY & x )
{ remove( x, root ); }

template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::remove( const KEY & x, BinaryNode * & t )
{
    if( t == nullptr ) return;
    if ( x < t->data.key ) remove( x, t->left );
    else if( t->data.key < x ) remove( x, t->right );
    else if( t->left != nullptr && t->right != nullptr )
    { //有两个孩子
        BinaryNode *tmp = t->right;
        while (tmp->left != nullptr) tmp = tmp->left; t->data = tmp->data;
        remove( t->data.key, t->right );
    }
    else
    {//被删结点是叶结点或只有一个孩子
        BinaryNode *oldNode = t;
        t = ( t->left != nullptr ) ? t->left : t->right;
        delete oldNode;
    }
}

template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::midOrder(SET<KEY, OTHER>* Order, BinaryNode *t) const
{
    
    if (t == nullptr) return;
    midOrder(Order, t->left);
    int i;
    for(i = 0; (Order+i)->key != 0; ++i);
    *(Order+i) = t->data;
    midOrder(Order, t->right);
}

template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::midOrder(SET<KEY, OTHER>* Order) const
{ midOrder(Order, root); }


template <class KEY, class OTHER>
KEY BinarySearchTree<KEY, OTHER>::iBiggestKey(KEY i, KEY N) const
{
    SET<KEY, OTHER>* Order = new SET<KEY, OTHER>[N];
    for(int i = 0; i < N; ++i) (Order+N-i)->key = 0;
    midOrder(Order, root);
    int Key = (Order+N-i)->key;
    delete [] Order;
    return Key;
}

template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::deleteRange(KEY min, KEY max, KEY N)
{
    SET<KEY, OTHER>* Order = new SET<KEY, OTHER>[N];
    for(int i = 0; i < N; ++i) (Order+N-i)->key = 0;
//    SET<KEY, OTHER> Order[10] ={0,};
    midOrder(Order, root);
    for(int i = 0; i < N; ++i)
        if((Order + i)->key >= min and (Order + i)->key <= max) remove((Order + i)->key);
    delete [] Order;
    SET<KEY, OTHER> Order2[10] ={0,};
    midOrder(Order2, root);
}

template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::deleteDown(KEY max, KEY N)
{
    SET<KEY, OTHER>* Order = new SET<KEY, OTHER>[N];
    for(int i = 0; i < N; ++i) (Order+N-i)->key = 0;
//    SET<KEY, OTHER> Order[10] ={0,};
    midOrder(Order, root);
    for(int i = 0; i < N; ++i)
        if((Order + i)->key < max) remove((Order + i)->key);
    delete [] Order;
//    SET<KEY, OTHER> Order2[10] ={0,};
//    midOrder(Order2, root);
}

template <class KEY, class OTHER>
void BinarySearchTree<KEY, OTHER>::deleteUp(KEY min, KEY N)
{
    SET<KEY, OTHER>* Order = new SET<KEY, OTHER>[N];
    for(int i = 0; i < N; ++i) (Order+N-i)->key = 0;
//    SET<KEY, OTHER> Order[10] ={0,};
    midOrder(Order, root);
    for(int i = 0; i < N; ++i)
        if((Order + i)->key > min) remove((Order + i)->key);
    delete [] Order;
//    SET<KEY, OTHER> Order2[10] ={0,};
//    midOrder(Order2, root);
}


template <class KEY, class OTHER>
SET<KEY, OTHER> * BinarySearchTree<KEY, OTHER>::find(
const KEY &x ) const { return find( x, root ); }
template <class KEY, class OTHER>
SET<KEY, OTHER> *BinarySearchTree<KEY, OTHER>::find(
const KEY & x, BinaryNode *t ) const { if ( t == nullptr || t->data.key == x )
return (SET<KEY, OTHER> *) t;
if( x < t->data.key ) return find( x, t->left ); else return find( x, t->right );
}
