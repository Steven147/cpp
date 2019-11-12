#include <iostream>
#include "priorityQueue.cpp"
using namespace std;

int minBoxSize(int N, int* items, int capacity) {
    priorityQueue<int> myQueue(items, N);
    int nowItem;
    findBags myBags(N, capacity);
    while(!myQueue.isEmpty())
    {
        nowItem = myQueue.deQueue();
        myBags.switchToFirstBag();
        while(myBags.NowBagCapacity() < nowItem)
            myBags.switchToNextBag();
        myBags.packItem(nowItem);
    }
    return myBags.getTotelNumber();
}

int main() {
    /* initialize */
    int N;
    cin>>N;
    int* items = new int[N];
    for(int i=0;i<N;i++) {
        cin>>items[i];
    }
    int capacity;
    cin>>capacity;

    /* test */
    cout<<minBoxSize(N, items, capacity)<<endl;

    /* free memory */
    delete []items;
    return 0;
}
