class sequenceList
{
private:
    float* myList;             //建表
    const int curNumberOfItem;         //欲加入的长度
    const int  maxCapcity;   //链表最大值
    int len = curNumberOfItem;         //目前长度


public:
    sequenceList(int, int, float[]);
    ~sequenceList();

    bool addItem(const float&);
    int insertItem(int index, const float&);
    int deleteItem(const float&);
    bool locate(const int&, float& val);
    int locate(const float&);
    void reverse();
    void print();
};



class linkList;
class listNode
{
    friend class linkList;
    friend void merge(linkList&, linkList&);
public:
    float data = 0.0;
    listNode* next = nullptr;

    listNode(){next = nullptr;}
    listNode(float nodeData, listNode* succ = nullptr);


};

//完成单链表的类
class linkList
{
private:
    
    listNode* firstNode;
    listNode* curNode;
    listNode* lastNode;

    listNode* getPtr(int index);
    int len;

public:
    linkList();
    linkList(int, float[]);
    ~linkList();

    bool headInsertItem(const float&);
    bool tailInsertItem(const float&);
    int insertItem(int index, const float&);
    int deleteItem(const float&);
    bool locate(const int&, float&);
    int locate(const float&);
    void ascendingOrder();
    void reverse();
    void print();
    friend void merge(linkList&, linkList&);

};

void merge(linkList&, linkList&);