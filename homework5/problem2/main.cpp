#include "BinarySearchTree.h"

const int charLength = 20;
SET<int, char*>* mySet;
int N, iBiggest, a, b, x, y;
BinarySearchTree<int, char*> myBST;

void operations()//清空myset，储存排序结果，输出
{
    for(int i = 0; i < N; ++i) (mySet+i)->key = 0;
    myBST.midOrder(mySet);
    for(int i = 0; (mySet+i)->key != 0; ++i)
        std::cout << (mySet+i)->key << ' ';
    std::cout << std::endl;
}


int main() {
    
    std::cin >> N;
    mySet = new SET<int, char*>[N];
    for(int i = 0; i < N; ++i) (mySet+i)->key = 0;
    for(int i = 0; i < N; ++i)
    {
        std::cin >> (mySet + i)->key;
        (mySet + i)->other = new char[charLength];
        std::cin >> (mySet + i)->other;
    }
    std::cin >> iBiggest >> a >> b >> x >> y;
    
    for(int i = 0; i < N; ++i)
        myBST.insert(*(mySet+i));
    std::cout << myBST.iBiggestKey(iBiggest, N) << std::endl;
    for(int i = 0; i < N; ++i) delete [] (mySet + i)->other;
    
    myBST.deleteRange(a, b, N);
    operations();
    
    myBST.deleteDown(x, N);
    operations();

    myBST.deleteUp(y, N);
    operations();
    
    return 0;
}
