#ifndef h
#define h


template <class Type>
class priorityQueue
{
private:
    int currentSize;
    Type *array;
    const int maxSize;
    
    void buildHeap();
    void percolateDown( int hole );
    
public:
    priorityQueue( int capacity = 100 )
    { array = new Type[capacity]; maxSize = capacity; currentSize = 0;}
    ~priorityQueue()
    { delete [] array; }
    bool isEmpty() const
    { return currentSize == 0; }
    Type getHead() { return array[1]; }
    
    priorityQueue( const Type data[], int size );
    void enQueue( const Type & x );
    Type deQueue();

    
    int findMin(int x);
    void decreaseKey(int i, int value);
    int* getArray();
};

#endif
