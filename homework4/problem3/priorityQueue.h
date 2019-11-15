#ifndef h
#define h


template <class Type>
class priorityQueue
{
private:
    int currentSize;
    Type *array;
    int maxSize;
    //void doubleSpace();

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
};

class findBags
{
private:
    int* bagsCapacity;
    int totelNumber;//从一开始指示背包个数
    int nowBag;//从一开始指示背包位置
public:
    findBags(int N, int capacity):totelNumber(1), nowBag(1)
    {
        bagsCapacity = new int[N];
        for(int i = 0; i < N; ++i){
            *(bagsCapacity+i) = capacity;
        }
    }
    ~findBags(){delete bagsCapacity;}
    void switchToFirstBag(){nowBag = 1;}
    int NowBagCapacity(){return *(bagsCapacity+nowBag-1);}
    void packItem(int size){*(bagsCapacity+nowBag-1) -= size;}
    void switchToNextBag()
    {
        if(nowBag < totelNumber)
            nowBag++;
        else{
            nowBag++;
            totelNumber++;
        }
    }
    int getTotelNumber(){return totelNumber;}
};


#endif

