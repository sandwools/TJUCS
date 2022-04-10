#include <iostream>
using namespace std;
#ifndef STRING_LIST
#define STRING_LIST
class myStr{
public:
int len;
char* s;
int* next;
int* nextval;
myStr(const char*);//字符串初始化。
~myStr();//字符串销毁。

void print();//字符串输出。
void kmp_next();//kmp辅助数组next的计算。
void kmp_nextVal();//kmp辅助数组nextVal的计算。

void printNext();//kmp辅助数组next的输出。
void printNextVal();//kmp辅助数组nextVal的输出。

friend bool replaceStr(myStr& S, const int& start, const myStr& T, const myStr& V);
//串的替换，即要求在主串S中，从位置start开始查找是否存在子串T，若主串S中存在子串T，则用子串V替换子串T，且函数返回1；
//若主串S中不存在子串T，则函数返回0， start取值从1开始。


friend int simpleMatch(const myStr& S, const myStr& T);
//简单字符串匹配算法，目标串S和模式串T，求T在S中的位置。匹配失败返回-1，匹配成功返回匹配位置（字符串的位置从1开始）。


friend int kmpMatch(const myStr& S, const myStr& T);
//改进KMP算法的字符串匹配算法，目标串S和模式串T，求T在S中的位置。
//匹配失败返回-1，匹配成功返回匹配位置（字符串的位置从1开始）。

};
#endif
#ifndef MATRIX_LIST
#define MATRIX_LIST

class myMatrix{
public:
int rn, cn, num;
int matrix[10000][3];
myMatrix (const int& rNum, const int& cNum, const int& nNum, const int*);
//初始化稀疏矩阵,参数依次为行数、列数、三元组元素个数、三元组初始化数据，
//数组元素为3的倍数，每3个数一组，分别为（row，col，value）。


myMatrix();//初始化稀疏矩阵。
~ myMatrix();//销毁稀疏矩阵。

void FastTransposeSMatrix(myMatrix& T);//实现快速转置算法。
void printMatrix();

};
#endif

