#include "linearList.h"
#include <iostream>

///////////////////////////////////////////
//                                       //
//              LiuYuanchi               //
//                                       //
///////////////////////////////////////////


//NULL好像会报错？

//顺序表
//.............................................................................................

//初始化顺序表
                   //容量         初始长度     值
sequenceList::sequenceList(
              int listsize, int curNumberOfItem, float p[]) 

             :maxCapcity(listsize),  //固定了表最长长度
              curNumberOfItem(curNumberOfItem)//构造函数部分
             
{
    len = curNumberOfItem; //目前的表长即是初始值
    myList = new float[listsize];

    for (int i = 0; i < len; i++)
    {
        myList[i] = p[i];
    }// 将变量放入表中
}

//销毁顺序表。
sequenceList::~sequenceList()
{
    delete[] myList;
}

//添加元素data,添加元素顺序表尾，
//成功返回true，失败返回false。
bool sequenceList::addItem(const float& data)
{
    if (curNumberOfItem >= maxCapcity)
    {
       //throw -1;
       return false;//判断是否还有空位插入data。
    }
    
    else {
        myList[curNumberOfItem] = data;//插入data。
        len++;//增加顺序表长度。
        return true;
    }

}


//插入元素data,插入元素到index位置，
//成功返回true，失败返回false。
int sequenceList::insertItem(int index, const float& data)
{
    if (curNumberOfItem == maxCapcity ||
        index < 0 || 
        index >= maxCapcity) 
        return -1;
       //Err: 顺序表不可插入
    
    else {

        for (int i = len - 1; i >= index; i--)
        {
            myList[i + 1] = myList[i];
        }
        //插入点后的元素 从后向前 往后移。

        len++;//增加线性表长度。
        myList[index] = data;//插入data。
        
        return index;
    }
}

//删除元素data,返回删除位置，找不到返回-1
int sequenceList::deleteItem(const float& data)
{
    for (int i = 0; i < len; i++)
    {
        if (myList[i] == data)
        {
            for (int j = i; j < len; j++)
            {
                myList[j] = myList[j + 1];
                //以后一个数的值来覆盖前一个数从而删除data。
            }

            len--;//减小线性表长度。
            return i;
        }
        

    }
     return -1;
}

//查找元素（按序号找num）, 成功返回true，值放在val中，失败返回false
bool sequenceList::locate(const int& dat, float& val)
{
    if (dat > len - 1)
       return false;//Err:超出顺序表范围。
    
    else
    {
        val = myList[dat];//值放入val中。
        return true;
    }

}

//查找元素（按值找location），返回找到位置，找不到返回-1
int sequenceList::locate(const float& location)
{
    for (int i = 0; i < len; i++)//遍历寻找location。
    {
        if (myList[i] == location)
            return i;
    }
    return -1;
}
void sequenceList::reverse()//倒序排列元素（使用原空间）。
{
    for (int i = 0; i < len / 2; i++)
    //奇数中间那个数不变，头尾交换位置，实现倒序排列。
    {
        float temp = myList[i];//用中间量存储。
        myList[i] = myList[len - i - 1];
        myList[len - 1 - i] = temp;
    }
}

void sequenceList::print()//按序输出元素。
{
    std::cout << len << ":";
    for (int i = 0; i < len; i++)
    {
        std::cout << myList[i];
        if(i!=len-1)std::cout<< ",";
    }
    std::cout << std::endl;
}


//链表
//............................................................................

//得到index位置的指针域。

//初始化
linkList::linkList(int size, float link[])
{
    firstNode = new listNode;
    len = size;
    listNode* now = firstNode;
    for (int i = 0; i < len; i++)
    {
        now->next = new listNode;
        now->next->data = link[i];//data赋值
        now = now->next;
    }
}

//销毁单链表。
linkList::~linkList()
{
    listNode *tmp=firstNode->next;
    for(int i=0;i<len;i++){
        listNode *q;
        q = tmp->next;
        delete tmp;
        tmp = q;
    }
}


//插入元素
bool linkList::headInsertItem(const float& dat)
{
    listNode* temp = new listNode;
    if (temp == nullptr) return false;
    //判断非空。
    temp->data = dat;
    temp->next = firstNode->next;
    firstNode->next = temp;
    len++;
    //单链表元素增加。
    return true;
}

//插入元素(尾）
bool linkList::tailInsertItem(const float& dat)
{
    listNode* temp = new listNode;
    if (temp == nullptr) return false;
    listNode* now = firstNode;
    while (now->next != nullptr)
    {
        now = now->next;
    }
    temp->data = dat;
    now->next = temp;
    len++;
    return true;
}


//插入元素
int linkList::insertItem(int index, const float& dat)
{
    listNode* now = firstNode;
    listNode* temp = new listNode;
    if (temp == nullptr)return -1;
    for (int i = 0; i < index; i++)//找到插入的位置。
    {
        now = now->next;
    }
    temp->data = dat;//完成数据域。
    temp->next = now->next;
    now->next = temp;//完成指针域。
    len++;
    return index;
}


//删除元素num,返回删除位置，找不到返回-1。
int linkList::deleteItem(const float& dat)
{
    listNode* now = firstNode;
    listNode* temp;
    for (int i = 0; i < len; i++)
    {
        now = now->next;
        if (now->next->data == dat)
        {
            listNode* temp = now->next;
            now->next = now->next->next;//将结点从单链表中移出。
            delete now->next;//删除结点。
            len--;//单链表元素减一。
            return i + 1;
        }
    }
    return -1;


}

//查找元素（按序号找index）,成功返回true，值放在num中，失败返回false。
bool linkList::locate(const int& index, float& dat)
{
    if (index >= len)return false;
    listNode* now = firstNode;

    for (int i = 0; i <= index; i++)
    {
        now = now->next;
    }
    dat = now->data;
    return true;

}


//查找元素（按值找num）,返回找到位置，找不到返回-1。
int linkList::locate(const float& dat)
{
    
    listNode* now = firstNode;
  
    for (int i = 0; i < len; i++)//用循环查值。
    {
        now = now->next;
        if (now->data == dat)
        {
            
            return i;
        }

    }
    return -1;
}


//递增排序。
void linkList::ascendingOrder()
{
    if (len <= 1) return;
    float a;
    listNode* temp;
    for (int i = 1; i < len; i++)
    {
        listNode* now = firstNode->next;
        for (int j = 0; j < len - i; j++)
        {
            temp = now;
            now = now->next;
            if (temp->data > now->data)
            {
                a = temp->data;
                temp->data = now->data;
                now->data = a;

            }
        }
    }
}

//倒序排列元素。
void linkList::reverse()
{
    for (int i = 0; i < len / 2; i++)
    {
        listNode* p1 = getPtr(i);
        listNode* p2 = getPtr(len - i - 1);
        float temp = p1->data;
        p1->data = p2->data;
        p2->data = temp;
    }
}

listNode* linkList::getPtr(int index)
{
    if (index >= len)
        return nullptr;
        //尾指针空了。
    listNode* now = firstNode;
    for (int i = 0; i <= index; i++)
        now = now->next;
        //遍历得到index。
    return now;
}

//按序输出元素。
void linkList::print()
{
    int n = len;
    if (len == 0)return;
    listNode* now = new listNode;
    now = firstNode->next;
    std::cout << len << ":";

    while (now!=nullptr)
    {

        std::cout << now->data;
        if (now->next!=nullptr)
            std::cout << ",";
        now = now->next;
    }
    std::cout << "\n";


}


//读入A和B两个线性表,递减次序排列存放在A线性表中。
void merge(linkList& A, linkList& B)
{

    listNode* p = A.getPtr(A.len - 1);
    p->next = B.firstNode->next;
    A.len += B.len;
    //扩充A。
    float a;
    listNode* temp;
    for (int i = 1; i < A.len; i++)
    {
        listNode* now = A.firstNode->next;
        for (int j = 0; j < A.len - i; j++)
        {
            temp = now;
            now = now->next;
            if (temp->data < now->data)
            {
                a = temp->data;
                temp->data = now->data;
                now->data = a;

            }
        }
    }
   

}
