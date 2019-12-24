# include "adjListGraph.h"

template <class elemType>
seqStack<elemType>::seqStack(int initSize)
{ elem = new elemType[initSize]; maxSize = initSize ; top_p = -1; }

template <class elemType>
seqStack<elemType>:: ~seqStack()
{ delete [] elem; }

template <class elemType>
bool seqStack<elemType>:: isEmpty() const
{ return top_p == -1; }

template <class elemType>
void seqStack<elemType>::push(const elemType &x)
{
    if (top_p == maxSize - 1) doubleSpace();
    elem[++top_p] = x;
}

template <class elemType>
elemType seqStack<elemType>::pop()
{ return elem[top_p--]; }

template <class elemType>
elemType seqStack<elemType>::top() const
{ return elem[top_p]; }

template <class elemType>
void seqStack<elemType>::doubleSpace()
{
    elemType *tmp = elem;
    elem = new elemType[2 * maxSize]; for (int i = 0; i < maxSize; ++i)
        elem[i] = tmp[i]; maxSize *= 2; delete [] tmp;
}
template <class elemType>
int seqStack<elemType>::getLength(){return top_p + 1;}
template <class elemType>
elemType* seqStack<elemType>::getElem() {return elem;}



template <class elemType> linkQueue<elemType>::linkQueue() {
front = rear = NULL; }

template <class elemType>
void linkQueue<elemType>::enQueue(const elemType &x)
{
if (rear == NULL)
front = rear = new node(x); else
rear = rear->next = new node(x); }



template <class elemType>
elemType linkQueue<elemType>::deQueue() {node *tmp = front;
    elemType value = front->data; front = front->next;
    if (front == NULL) rear = NULL; delete tmp;
    return value;
    
    
}


template <class elemType>
bool linkQueue<elemType>::isEmpty()
{
return front == NULL; }
template <class elemType>
elemType linkQueue<elemType>::getHead()
{
return front->data; }



template <class elemType> linkQueue<elemType>::~linkQueue() {
    
node *tmp;
while (front != NULL) {
tmp = front;
    front = front->next; delete tmp;}}




template <class TypeOfVer, class TypeOfEdge> 
adjListGraph<TypeOfVer, TypeOfEdge>::adjListGraph(int vSize, const TypeOfVer d[]) 
{
    Vers = vSize; 
    Edges = 0;
    verList = new verNode[vSize];
    for (int i = 0; i < Vers; ++i) 
        verList[i].ver = d[i]; 
}

template <class TypeOfVer, class TypeOfEdge> 
adjListGraph<TypeOfVer, TypeOfEdge>::~adjListGraph() 
{ 
    int i;
    edgeNode *p;
    for (i = 0; i < Vers; ++i)
        while ((p = verList[i].head) != NULL) 
        { 
            verList[i].head = p->next;
            delete p;
        }
    delete [] verList;
}


template <class TypeOfVer, class TypeOfEdge> 
void adjListGraph<TypeOfVer, TypeOfEdge>::insert(TypeOfVer x, TypeOfVer y, TypeOfEdge w) 
{
    int u = find(x), v = find(y);
    verList[u].head = new edgeNode(v, w, verList[u].head); 
    ++Edges;
}
 

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer,TypeOfEdge>::remove(TypeOfVer x,TypeOfVer y)
{
    int u = find(x), v = find(y); 
    edgeNode *p = verList[u].head, *q;
    if (p == NULL) return; //结点u没有相连的边
    if (p->end == v) { //单链表中的第一个结点就是被删除的边
        verList[u].head = p->next; 
        delete p; 
        --Edges;
        return;
    }
    while (p->next !=NULL && p->next->end != v) 
        p = p->next;
    if (p->next != NULL) 
    {
        q = p->next; 
        p->next = q->next; 
        delete q; 
        --Edges; 
    }
}

template <class TypeOfVer, class TypeOfEdge> 
bool adjListGraph<TypeOfVer, TypeOfEdge> ::exist(TypeOfVer x, TypeOfVer y) const
{
    int u = find(x), v = find(y);
    edgeNode *p = verList[u].head;
    while (p !=NULL && p->end != v) p = p->next;
    if (p == NULL) return false; 
    else return true; 
}

template <class TypeOfVer, class TypeOfEdge> 
int adjListGraph<TypeOfVer, TypeOfEdge>::find(TypeOfVer v) const
{
    for (int i = 0; i < Vers; ++i)
        if (verList[i].ver == v) return i;
    return -1;
} 

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::dfs() const
{
    bool *visited = new bool[Vers];
    for (int i=0; i < Vers; ++i) 
        visited[i] = false;
    cout << "当前图的深度优先遍历序列为:" << std::endl;
    for (int i = 0; i < Vers; ++i) {
        if (visited[i] == true) continue; 
        dfs(i, visited);
        cout << endl;
    } 
}

template <class TypeOfVer, class TypeOfEdge> 
void adjListGraph<TypeOfVer, TypeOfEdge>::dfs(int start, bool visited[]) const
{
    edgeNode *p = verList[start].head; 
    cout << verList[start].ver << '\t';
    visited[start] = true;
    while (p != NULL){  
        if (visited[p->end] == false) dfs(p->end, visited);
        p = p->next; 
    }
}




template <class TypeOfVer, class TypeOfEdge> 
bool adjListGraph<TypeOfVer, TypeOfEdge>::findRoad(int start, int end, int *road, int &length)
{
    bool *visited = new bool[Vers];
    for (int i=0; i < Vers; ++i)
        visited[i] = false;
    seqStack<verNode> myStack;
    //将初始点进栈
    myStack.push(verList[start]);
    
    //选一个子节点，进栈，直到没得选，或者找到终点
    for(bool found = false;!myStack.isEmpty() and !found;)
    {
        edgeNode *p = myStack.top().head;//p为指向后继的指针
        
        //对栈顶结点的后继而言，在没找到目标前，在还存在后继前，对第一个可以访问的后继进栈，
        //如果有后继但都不符合要求
        while(p!= nullptr and !found)
        {
            int succeed = p->end;
            //如果后继符合，将后继进栈，并且指针指向后继；gg否则找下一个后继
            if(!visited[succeed]){
                myStack.push(verList[succeed]);
                p = myStack.top().head;
            }
            else p = p->next;
            found = (succeed == end); //找到目标就直接跳出
        }
        //出栈,并对出栈结点进行标记，直到顶部结点有后继
        while(p == nullptr and !found and !myStack.isEmpty()){
            int now = myStack.pop().ver;
            visited[now] = true;
            p = myStack.top().head;
        }
    }
    //逐个出栈直到栈为空
    if(!myStack.isEmpty()){
        int i = 0;
        while(!myStack.isEmpty()){
            road[i++] = myStack.pop().ver;
        }
        length = i;
        return true;
    }
    else return false;
}



template <class TypeOfVer, class TypeOfEdge>
bool adjListGraph<TypeOfVer, TypeOfEdge>::hasLoop()
{
    bool *visited = new bool[Vers];
    for (int i=0; i < Vers; ++i) visited[i] = false;
    for (int i = 0; i < Vers; ++i) {
        bool result = dfs2(i, visited);
        if (result) return true;
        else for (int i = 0; i < Vers; ++i) visited[i] = false;
    }
    return false;
}

template <class TypeOfVer, class TypeOfEdge>
bool adjListGraph<TypeOfVer, TypeOfEdge>::dfs2(int start, bool visited[]) //start结点开始搜索会不会碰到已搜过结点
{
    edgeNode *p = verList[start].head;
    visited[start] = true;
    while (p != NULL){
        if (visited[p->end] == true) return true; //后继结点是已搜过结点
        else if(dfs2(p->end, visited)) return true; //当后继结点碰到已搜过结点
        else p = p->next;
    }
    visited[start] = false;
    return false;
}




template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::topSort() const
{
    linkQueue<int> q;
    edgeNode *p;
    int current, *inDegree = new int[Vers];
    for (int i = 0; i < Vers; ++i) inDegree[i] = 0;
    for (int i = 0; i < Vers; ++i){
        for (p = verList[i].head; p != NULL; p = p->next)
            ++inDegree[p->end];
    }
    for (int i = 0; i < Vers; ++i)
        if (inDegree[i] == 0) q.enQueue(i);
    
    while( !q.isEmpty( ) ){
        current = q.deQueue( );
        cout << verList[current].ver << ' ';
        for (p = verList[current].head; p != NULL; p = p->next)
            if( --inDegree[p->end] == 0 )
                q.enQueue( p->end );
    }
    cout << endl;
     
}

template class adjListGraph<int, int>;
