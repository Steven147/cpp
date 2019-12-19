#include <iostream>

template <class TypeOfVer, class TypeOfEdge> 
class adjListGraph
{
public:
    adjListGraph(int vSize, const TypeOfVer d[]);
    void insert(TypeOfVer x, TypeOfVer y, TypeOfEdge w); 
    void remove(TypeOfVer x, TypeOfVer y);
    bool exist(TypeOfVer x, TypeOfVer y) const; ~adjListGraph();
    void dfs() const ;
private:
    struct edgeNode {//邻接表中存储边的结点类
        int end; //终点编号
        TypeOfEdge weight; //边的权值
        edgeNode *next; 
        edgeNode(int e, TypeOfEdge w, edgeNode *n = NULL) 
        { end = e; weight = w; next = n;}
    };
    struct verNode{ //保存顶点的数据元素类型
        TypeOfVer ver;  //顶点值
        verNode( edgeNode *h = NULL) //对应的单链表的头指针 
        { head = h; }
    };
    verNode *verList;
    int find(TypeOfVer v) const;
    void dfs(int start, bool visited[]) const;
};
