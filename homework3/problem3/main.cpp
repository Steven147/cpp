/*
 Problem 3
二叉树以顺序存储的方式存储在一个三元数组中，要求编程实现二叉树的遍历。
 每个节点的存储格式为[Data,L,R]，Data代表节点的值（这里设为整数），
 L表示左子节点的下标编号，R表示右子节点的下标编号，编号从0开始，
 若该节点无左子节点或右子节点，则对应信息上的编号为-1。(30')

输入描述
第1行输入节点个数num，个数为正整数。
第2到num+1行，分别输入第1到num个节点的相关信息[Data,L,R]。

输出描述
输出共3行，第一行输出前序遍历节点各个节点数据的值，
第二行输出中序遍历节点各个节点数据的值，第三行输出后序遍历节点各个节点数据的值，各节点数据之间以空格分隔。


输入输出测试

3
100 -1 1
30 2 -1
-5 -1 -1
100 30 -5
100 -5 30
-5 30 100
Program ended with exit code: 0
 
8
1 1 2
2 3 4
3 -1 5
4 -1 -1
5 -1 -1
6 6 -1
7 -1 7
8 -1 -1
1 2 4 5 3 6 7 8
4 2 5 1 3 7 8 6
4 5 2 8 7 6 3 1
Program ended with exit code: 0
 
11
1 1 2
2 3 4
7 5 -1
3 -1 -1
4 6 7
8 -1 8
5 -1 -1
6 -1 -1
9 9 -1
10 -1 10
11 -1 -1
1 2 3 4 5 6 7 8 9 10 11 
3 2 5 4 6 1 8 10 11 9 7 
3 5 6 4 2 11 10 9 8 7 1 
 
 */

#include "binaryTree.cpp"
#include <iostream>
using namespace std;

void preorder_tranversal(int num, int** nodes, int* preOrder) {
    // 请实现本函数
    // 函数逻辑请用二叉树类实现，并在本文件中引入相关头文件
    binaryTree<int> myTree;
    myTree.createTree(num, nodes);
    for(int i = 0; i < num; ++i) *(preOrder + i) = 0;
    myTree.preOrder(preOrder);
}

void midorder_tranversal(int num, int** nodes, int* midOrder) {
    // 请实现本函数
    // 函数逻辑请用二叉树类实现，并在本文件中引入相关头文件
    binaryTree<int> myTree;
    myTree.createTree(num, nodes);
    for(int i = 0; i < num; ++i) *(midOrder + i) = 0;
    myTree.midOrder(midOrder);
}

void postorder_tranversal(int num, int** nodes, int* postOrder) {
    // 请实现本函数
    // 函数逻辑请用二叉树类实现，并在本文件中引入相关头文件
    binaryTree<int> myTree;
    myTree.createTree(num, nodes);
    for(int i = 0; i < num; ++i) *(postOrder + i) = 0;
    myTree.postOrder(postOrder);
}

// main cannot be modified
int main(){
    
    // initialize
    int num;
    cin>>num;
    int **nodes = new int*[num];
    for(int i =0; i < num; i++) {
        nodes[i] = new int[3];
    }
    for(int i = 0;i < num; i++){
        for(int j = 0;j < 3;j++){
            cin>>nodes[i][j];
        }
    }

    //use preOrder, midOrder, postOrder store the results
    int *preOrder = new int[num];
    int *midOrder = new int[num];
    int *postOrder = new int[num];

    // should be finished
    preorder_tranversal(num, nodes, preOrder);
    midorder_tranversal(num, nodes, midOrder);
    postorder_tranversal(num, nodes, postOrder);

    // output the results
    // print preOrder results
    for(int i = 0;i < num; i++){
        cout<<preOrder[i]<<' ';
    }
    cout<<endl;
    // print midOrder results
    for(int i = 0;i < num; i++){
        cout<<midOrder[i]<<' ';
    }
    cout<<endl;
    // print postOrder results
    for(int i = 0;i < num; i++){
        cout<<postOrder[i]<<' ';
    }
    cout<<endl;

    // free memory
    for (int i = 0; i < num; i++)
    {
        delete []nodes[i];
        nodes[i] = NULL;
    }
    delete []nodes;
    nodes = NULL;
    delete []preOrder;
    preOrder = NULL;
    delete []midOrder;
    midOrder = NULL;
    delete []postOrder;
    postOrder = NULL;

    return 0;
}
