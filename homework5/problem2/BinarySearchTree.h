#ifndef h
#define h

#include <iostream>

template <class KEY, class OTHER>
struct SET {
    KEY key;
    OTHER other;
};

template <class KEY, class OTHER>
class dynamicSearchTable {
public:
    virtual SET<KEY, OTHER> *find(const KEY &x) const = 0;
    virtual void insert(const SET<KEY, OTHER> &x) = 0;
    virtual void remove(const KEY &x) = 0;
    virtual ~dynamicSearchTable() {};
};

template <class KEY, class OTHER>
class BinarySearchTree: public dynamicSearchTable<KEY,OTHER>
{
private:
    struct BinaryNode
    {
        SET<KEY, OTHER> data;
        BinaryNode *left;
        BinaryNode *right;
        BinaryNode(const SET<KEY, OTHER> & thedata, BinaryNode *lt= nullptr, BinaryNode *rt= nullptr ) :
        data( thedata ), left( lt ), right( rt ) {}
    };
    BinaryNode *root;

public:
    BinarySearchTree( );
    ~BinarySearchTree( );
    SET<KEY, OTHER> *find(const KEY &x) const;
    void insert( const SET<KEY, OTHER> &x );
    void remove( const KEY &x );
    void midOrder(SET<KEY, OTHER>* Order) const;
    KEY iBiggestKey(KEY i, KEY N) const;
    void deleteRange(KEY min, KEY max, KEY N);
    void deleteDown(KEY max, KEY N);
    void deleteUp(KEY min, KEY N);

    
private:
    void insert( const SET<KEY, OTHER> & x, BinaryNode *&t );
    void remove( const KEY &x, BinaryNode *&t );
    void midOrder(SET<KEY, OTHER>* Order, BinaryNode *t) const;
    SET<KEY, OTHER> *find(const KEY &x, BinaryNode *t ) const;
//    void makeEmpty( BinaryNode *t );
};

#endif
