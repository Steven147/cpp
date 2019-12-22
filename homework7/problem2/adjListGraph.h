#include <iostream>
#include <string>
using namespace std;

template <class TypeOfVer, class TypeOfEdge>
class graph
{
public:
    virtual void insert(TypeOfVer x, TypeOfVer y, TypeOfEdge w) = 0;
    virtual void remove(TypeOfVer x, TypeOfVer y) = 0;
    virtual bool exist(TypeOfVer x, TypeOfVer y) const = 0;
    int numOfVer() const {return Vers;}
    int numOfEdge() const {return Edges;}
protected:
    int Vers, Edges;
};

template <class TypeOfVer, class TypeOfEdge> 
class adjListGraph:public graph<TypeOfVer,TypeOfEdge>
{
public:
    adjListGraph(int vSize, const TypeOfVer d[]);
    void insert(TypeOfVer x, TypeOfVer y, TypeOfEdge w); 
    void remove(TypeOfVer x, TypeOfVer y);
    bool exist(TypeOfVer x, TypeOfVer y) const; 
    ~adjListGraph();
    void dfs() const ;
    bool findRoad(int start, int end, int *road, int &length);
    bool hasLoop();
    bool dfs2(int start, bool visited[]);
    void topSort() const;
    int Vers, Edges;
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
        edgeNode* head;
        verNode( edgeNode *h = NULL) //对应的单链表的头指针 
        { head = h; }
    };
    verNode *verList;
    int find(TypeOfVer v) const;
    void dfs(int start, bool visited[]) const;
    void dfsFindEnd(int start, bool visited[]) const;
    
};











template <class elemType>
class stack
{
public:
    virtual bool isEmpty() const = 0;
    virtual void push(const elemType &x) = 0;
    virtual elemType pop() = 0;
    virtual elemType top() const = 0;
    virtual ~stack() {}
};

template <class elemType>
class seqStack: public stack<elemType>
{
private:
    elemType *elem;
    int top_p;
    int maxSize;
    void doubleSpace();
public:
    seqStack(int initSize = 20) ;
    ~seqStack();
    bool isEmpty() const;
    void push(const elemType &x) ;
    elemType pop();
    elemType top() const;
    
    int getLength();
    elemType* getElem();
};












template <class elemType>
class queue
{ public:
virtual bool isEmpty() = 0;
virtual void enQueue(const elemType &x) = 0; virtual elemType deQueue() = 0;
virtual elemType getHead() = 0;
virtual ~queue() {}
};


template <class elemType>
class linkQueue: public queue<elemType>
{ private:
struct node {
elemType data;
node *next;
node(const elemType &x, node *N = NULL)
{ data = x; next = N;} node():next(NULL) {}
~node() {} };
node *front, *rear;
    public: linkQueue();
    ~linkQueue();
    bool isEmpty();
    void enQueue(const elemType &x) ;
    elemType deQueue();
    elemType getHead();
    
};
