

//单链表类定义
class sLinkList:public list<elemType> 
{ 
    private:
        struct node { //单链表中的结点类 elemType data;
            node *next;
            node(const elemType &x, node *n = NULL)
            { data = x; next = n;} node( ):next(NULL) {} ~node() {}
        };
        node *head; //头指针
        int currentLength; //表长 
        node *move(int i) const; //返回第i个结点的地址
    
    public: 
        sLinkList() ;
        ~sLinkList() {clear(); delete head; }
        void clear() ;
        int length() const 
        {return currentLength;} 
        void insert(int i, const elemType &x); 
        void remove(int i);
        int search(const elemType &x) const ; 
        elemType visit(int i) const;
        void traverse() const ;
};
