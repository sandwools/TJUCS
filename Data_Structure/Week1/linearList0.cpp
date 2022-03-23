#include "linearList.h"
using namespace std;

//顺序表打印
void sequenceList::print()
{
    cout << curNumberOfItem << ":";

    for(int i = 0; i < curNumberOfItem-1; i++)
    {
        cout << myList[i] << ",";
    }

    cout << myList[curNumberOfItem-1] << endl;
}



//链表打印
void linkList::print()
{
    curNode = firstNode;

    cout << listSize << ":";

    while(curNode != lastNode)
    {
        if(curNode->next == lastNode)
            cout << curNode->next->data << endl;
        else
        {
            cout << curNode->next->data << ",";
        }
        
        
        curNode = curNode->next;
    }
}
