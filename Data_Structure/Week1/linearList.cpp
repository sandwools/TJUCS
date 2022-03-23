#include "linearList.h"
#include <iostream>

///////////////////////////////////////////
//                                       //
//              LiuYuanchi               //
//                                       //
///////////////////////////////////////////


//顺序表
//.............................................................................................

//初始化顺序表
                           //容量         初始长度     值
sequenceList::sequenceList(int listsize, int curNumberOfItem, float p[]) 
             :maxCapcity(listsize),  //固定了表最长长度
              curNumberOfItem(curNumberOfItem)//
             
{
    len = curNumberOfItem; //目前的表长即是初始值
    seq = new float[listsize];

    for (int i = 0; i < len; i++)
    {
        seq[i] = p[i];
    }// 将变量放入表中
}

//销毁顺序表。
sequenceList::~sequenceList()
{
    delete[] seq;
}

//添加元素data,添加元素顺序表尾，
//成功返回true，失败返回false。
bool sequenceList::addItem(const float& data)
{
    if (curNumberOfItem >= maxCapcity)
    {
       throw -1;
       return false;//判断是否还有空位插入data。
    }
    
    else {
        seq[curNumberOfItem] = data;//插入data。
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
            seq[i + 1] = seq[i];
        }
        //插入点后的元素 从后向前 往后移。
        
        seq[index] = data;//插入data。
        len++;//增加线性表长度。
        return index;
    }
}

//删除元素data,返回删除位置，找不到返回-1
int sequenceList::deleteItem(const float& data)
{
    for (int i = 0; i < len; i++)
    {
        if (seq[i] == data)
        {
            for (int j = i; j < len; j++)
            {
                seq[j] = seq[j + 1];//以后一个数的值来覆盖前一个数从而删除data。
            }

            len--;//减小线性表长度。
            return i;
        }
        

    }
     return -1;
}

//查找元素（按序号找num）, 成功返回true，值放在val中，失败返回false
bool sequenceList::locate(const int& num, float& val)
{
    if (num > len - 1)
       return false;//Err:超出顺序表范围。
    
    else
    {
        val = seq[num];//值放入val中。
        return true;
    }

}

//查找元素（按值找location），返回找到位置，找不到返回-1
int sequenceList::locate(const float& location)
{
    for (int i = 0; i < len; i++)//寻找location。
    {
        if (seq[i] == location)
            return i;
    }
    return -1;
}
void sequenceList::reverse()//倒序排列元素（使用原空间）。
{
    for (int i = 0; i < len / 2; i++)//从中间一分为二，设置中间量，头尾交换位置，实现倒序排列。
    {
        float temp = seq[i];//用中间量存储。
        seq[i] = seq[len - i - 1];
        seq[len - 1 - i] = temp;
    }
}
void sequenceList::print()//按序输出元素。
{
    std::cout << len << ":";//输出线性表中元素数量。
    for (int i = 0; i < len; i++)
    {
        std::cout << seq[i];
        if(i!=len-1)std::cout<< ",";
    }
    std::cout << std::endl;
}


//链表
//............................................................................

//得到index位置的指针域。
listNode* linkList::getPtr(int index)
{
    if (index >= len)
        return nullptr;//尾指针或是超出单链表范围位置的指针域均为空指针。
    listNode* now = first;
    for (int i = 0; i <= index; i++)
        now = now->next;//通过循环来得到index位置的指针域。
    return now;
}

linkList::linkList(int size, float link[])//初始化链表,初始化数组长度，初始化数组。
{
    first = new listNode;
    len = size;
    listNode* now = first;
    for (int i = 0; i < len; i++)
    {
        now->next = new listNode;
        now->next->data = link[i];
        now = now->next;
    }
}
linkList::~linkList()//销毁单链表。
{
    listNode *tmp=first->next;
    for(int i=0;i<len;i++){
        listNode *q;
        q = tmp->next;
        delete tmp;
        tmp = q;
    }
}
bool linkList::headInsertItem(const float& num)//插入元素num(头插法)，成功返回true，失败返回false。
{
    listNode* temp = new listNode;
    if (temp == nullptr) return false;//判断非空指针。
    temp->data = num;//以num作为数据域。
    temp->next = first->next;
    first->next = temp;//插入完毕。
    len++;//单链表元素增加。
    return true;
}
bool linkList::tailInsertItem(const float& num)//插入元素num(尾插法），成功返回true，失败返回false。
{
    listNode* temp = new listNode;
    if (temp == nullptr) return false;//判断非空指针。
    listNode* now = first;
    while (now->next != nullptr)//循环在尾指针停下。
    {
        now = now->next;
    }
    temp->data = num;
    now->next = temp;
    len++;
    return true;
}
int linkList::insertItem(int index, const float& num)//插入元素num，插入元素到index位置，成功返回插入位置，错误返回-1。
{
    listNode* now = first;
    listNode* temp = new listNode;
    if (temp == nullptr)return -1;
    for (int i = 0; i < index; i++)//找到插入的位置。
    {
        now = now->next;
    }
    temp->data = num;//完成数据域。
    temp->next = now->next;
    now->next = temp;//完成指针域。
    len++;
    return index;
}
int linkList::deleteItem(const float& num)//删除元素num,返回删除位置，找不到返回-1。
{
    listNode* now = first;
    listNode* temp;
    for (int i = 0; i < len; i++)
    {
        now = now->next;
        if (now->next->data == num)
        {
            listNode* temp = now->next;
            now->next = temp->next;//将结点从单链表中移出。
            delete temp;//删除结点。
            len--;//单链表元素减一。
            return i + 1;
        }
    }
    return -1;


}
bool linkList::locate(const int& index, float& num)//查找元素（按序号找index）,成功返回true，值放在num中，失败返回false。
{
    if (index >= len)return false;
    listNode* now = first;

    for (int i = 0; i <= index; i++)//用循环查找。
    {
        now = now->next;
    }
    num = now->data;//值放在num里。
    return true;

}


int linkList::locate(const float& num)//查找元素（按值找num）,返回找到位置，找不到返回-1。
{
    
    listNode* now = first;
  
    for (int i = 0; i < len; i++)//用循环查值。
    {
        now = now->next;
        if (now->data == num)
        {
            
            return i;
        }

    }
    return -1;
}
void linkList::ascendingOrder()//递增排序。
{
    if (len <= 1) return;
    float a;
    listNode* temp;
    for (int i = 1; i < len; i++)
    {
        listNode* now = first->next;
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
void linkList::reverse()//倒序排列元素。
{
    for (int i = 0; i < len / 2; i++)//利用循环一分为二头尾交换。
    {
        listNode* p1 = getPtr(i);
        listNode* p2 = getPtr(len - i - 1);
        float temp = p1->data;
        p1->data = p2->data;
        p2->data = temp;
    }
}
void linkList::print()//按序输出元素。
{
    int n = len;
    if (len == 0)return;
    listNode* now = new listNode;
    now = first->next;
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
void merge(linkList& A, linkList& B)//读入A和B两个线性表，将这两个单链表归并为一个按元素值递减次序排列的单链表，利用原来两个单链表的结点存放归并后的单链表,结果存在A线性表中。
{

    listNode* p = A.getPtr(A.len - 1);//获得A的尾指针。
    p->next = B.first->next;//A和B单链表合到A上。
    A.len += B.len;//扩充A的元素个数。
    float a;
    listNode* temp;
    for (int i = 1; i < A.len; i++)//与上文ascendingOrder加上reverse异曲同工。
    {
        listNode* now = A.first->next;
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
