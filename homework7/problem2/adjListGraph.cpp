# include "adjListGraph.h"

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
int adjListGraph<TypeOfVer, TypeOfEdge> ::find(TypeOfVer v) const
{
    for (int i = 0; i < Vers; ++i)
    if (verList[i].ver == v) return i;
} 

template <class TypeOfVer, class TypeOfEdge>
void adjListGraph<TypeOfVer, TypeOfEdge>::dfs() const
{
    bool *visited = new bool[Vers];
    for (int i=0; i < Vers; ++i) visited[i] = false;
    cout << "当前图的深度优先遍历序列为:" << endl; 
    for (i = 0; i < Vers; ++i) {
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