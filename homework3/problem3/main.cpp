#include<iostream>
// #include "binaryTree.h"
using namespace std;

void preorder_tranversal(int num, int** nodes, int* preOrder) {
    // 请实现本函数
    // 函数逻辑请用二叉树类实现，并在本文件中引入相关头文件
}

void midorder_tranversal(int num, int** nodes, int* midOrder) {
    // 请实现本函数
    // 函数逻辑请用二叉树类实现，并在本文件中引入相关头文件
}

void postorder_tranversal(int num, int** nodes, int* postOrder) {
    // 请实现本函数
    // 函数逻辑请用二叉树类实现，并在本文件中引入相关头文件
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