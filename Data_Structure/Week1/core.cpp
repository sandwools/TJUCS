#include"linearList.cpp"
#include<stdlib.h>
int main()
{

//Core tested by LiuYuanchi git@github.com:sandwools:Tju_CS_Work
   
float i[3]={ 1.3 , 4.5 , 0.4 };
float val;
sequenceList sl(50, 3, i); //顺序表容量，初始化数组长度，初始化数组值
sl.print(); // 3: 1.3 ,4.5, 0.4
sl.insertItem(3, 5.5);
sl.print(); // 4:1.3,4.5,0.4,5.5
sl.deleteItem(1.3);//返回0
sl.print();// 3: 4.5,0.4,5.5
sl.locate(9,val);//返回false
sl.locate(4.5);//返回0
sl.print();// 3: 4.5,0.4,5.5
sl.reverse();//
sl.print();// 3: 5.5,0.4,4.5
system("pause");

}