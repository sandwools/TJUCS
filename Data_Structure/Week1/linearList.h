
//完成顺序表的类。
class sequenceList
{
private:
    const int  LIST_SIZE;   //链表最大值
    const int HIGH;         //欲加入的长度
    float* seq;             //建表
    int len = HIGH;         //目前长度

    float* myList;
    int curNumberOfItem;
    int maxCapcity;

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
    listNode* first;
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