#include "priorityQueue.h"

template <class Type>
void priorityQueue<Type>::enQueue( const Type & x ) {
    //if( currentSize == maxSize - 1 ) doubleSpace();
    // 向上过滤
    int hole = ++currentSize;
    for( ; hole > 1 && x < array[ hole / 2 ]; hole /= 2 )
        array[ hole ] = array[ hole / 2 ];
    array[ hole ] = x;
}

template <class Type>
Type priorityQueue<Type>::deQueue() {
    Type minItem;
    minItem = array[ 1 ];
    array[ 1 ] = array[ currentSize-- ];
    percolateDown( 1 );
    return minItem;
}

template <class Type>
void priorityQueue<Type>::percolateDown( int hole )
{
    int child;
    Type tmp = array[ hole ];//将待处理的值存下来
    for( ; hole * 2 <= currentSize; hole = child )//如果空洞在内
    {
        child=hole*2;
        if( child != currentSize && array[ child + 1 ] < array[ child ] )//找到小孩子
            child++;
        if( array[ child ] < tmp ) array[ hole ] = array[ child ];//如果孩子小，把孩子上移
        else break;
    }
    array[ hole ] = tmp;//将值填入新的洞中
}

template <class Type>
priorityQueue<Type>::priorityQueue( const Type *items, int size )
: maxSize(size + 10 ), currentSize(size)
{
    array = new Type[maxSize];
    for( int i = 0; i < size; i++ )
        array[ i + 1 ] = items[ i ];//从一开始储存，数组下标和堆下标对应
    buildHeap();
}

template <class Type>
void priorityQueue<Type>::buildHeap( )
{
    for(int i=currentSize/2;i>0;i--)
        percolateDown( i );
}

template <class Type>
int priorityQueue<Type>::findMin(int x)
{
    int min = 0;
    for(int i = 1; i <= maxSize; ++i)
    {
        if(*(array + i) >= x)
        {
            if(min == 0) min = i;
            if(*(array + i) < *(array + min)) min = i;
        }
    }
    return min;
}

template <class Type>
void priorityQueue<Type>::decreaseKey(int i, int value)
{
    *(array + i) -= value;
    buildHeap();
}

template <class Type>
int* priorityQueue<Type>::getArray()
{
    return array+1;
}
