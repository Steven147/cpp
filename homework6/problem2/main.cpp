# include <iostream>

void sort1(int* array, int length);
void sort2(int* array, int length);
int find(int* sortedArray, int length, int sum, int** resultArray);

int main(){
    //初始化
    int length, sum,
    *array1, *array2,
    *resultArray[2];
    std::cin >> length;
    array1 = new int[length];
    array2 = new int[length];
    
    resultArray[0] = new int[length];//储存较小的数字
    resultArray[1] = new int[length];//储存较大的数字

    //输入。
    for(int i = 0; i < length; ++i){
        std::cin >> *(array1 + i);
        *(array2 + i) = *(array1 + i);
    }
    std::cin >> sum;

    //寻找方法1
    sort1(array1, length);//排序1
    int num1 = find(array1, length, sum, resultArray);
    for(int i = 0; i < num1; ++i){//输出
        std::cout << '(' << *(resultArray[0] + i) << ',' << *(resultArray[1] + i) << ')';
    }
    std::cout << std::endl;

    //寻找方法2
    sort2(array2, length);//排序2
    int num2 = find(array2, length, sum, resultArray);
    for(int i = 0; i < num2; ++i){//输出
        std::cout << '(' << *(resultArray[0] + i) << ',' << *(resultArray[1] + i) << ')';
    }
    std::cout << std::endl;

    //析构
    delete [] array1;
    delete [] array2;
    delete [] resultArray[0];
    delete [] resultArray[1];
    return 0;
}

//简单插入排序 两层嵌套，时间复杂度为O(N^2)
void sort1(int* array, int length)
{ 
    int now;
    //从前往后遍历，将每个值插到左边序列中
    for(int i = 1; i < length; ++i)
    {
        int pos = i;
        //将值存下来
        now = array[i];
        //将前方大值往后移
        for(int j = i-1; j >= 0; --j)
        {
            if(array[j] > now)
            {
                array[j+1] = array[j];
                pos = j;
            }
        }
        //将存入的值填入
        array[pos] = now;
    }
}
//堆排序 时间复杂度为O(NlogN)
void sort2(int* array, int length)
{
    class priorityQueue
    {
    private:
        int currentSize;
        int *array;
        int maxsize;
        
    //    void doubleSpace();
        void buildHeap()
        {
            for (int i = currentSize/2; i > 0; --i) {
                percolateDown(i);
            }
        }
        void percolateDown(int hole)
        {
            int child;
            int tmp= array[hole];
            while(hole*2 <= currentSize){
                child = hole * 2;
                if(child != currentSize && array[child+1] < array[child]) ++child;
                if (array[child] < tmp) {
                    array[hole] = array[child];
                    hole = child;
                }
                else break;
            }
            array[hole] = tmp;
        }
        
    public:
        priorityQueue(int capacity = 100)
        {
            array = new int [capacity];
            maxsize = capacity;
            currentSize = 0;
        }
        priorityQueue(const int* data, int size):
        maxsize(size + 10), currentSize(size)
        {
            array = new int [maxsize];
            for(int i = 0; i < size; ++i)
                array[i+1] = data[i];
            buildHeap();
        }
        ~priorityQueue(){
            delete [] array;
        }
        void enQueue(const int &x)
        {
            //if(surrentSize == maxsize - 1) doubleSpace();
            int hole = ++ currentSize;
            while (hole > 1 && x < array[hole/2]) {
                array[hole] = array[hole/2];
                hole /= 2;
            }
            array[hole] = x;
        }
        int deQueue()
        {
            int minItem = array[1];
            array[1] = array[currentSize--];
            percolateDown(1);
            return minItem;
        }
    };
    priorityQueue myQueue(array, length);
    for(int i = 0; i < length; ++i) array[i] = myQueue.deQueue();
}

int find(int* sortedArray, int length, int sum, int** resultArray)
{
    int *small = &sortedArray[0], *big = &sortedArray[length-1], hasFound = 0;
    //和大，将大值缩小，和小，将小值放大
    while(*small <= *big){
        if(*small + *big == sum) {
            resultArray[0][hasFound] = *small;
            resultArray[1][hasFound] = *big;
            ++hasFound;
            ++small;
        }
        else if(*small + *big > sum) --big;
        else ++small;
    }
    return hasFound;
}
