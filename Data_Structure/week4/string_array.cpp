#include "string_array.h"
#include <iostream>
using namespace std;
myStr::myStr(const char* p)
{
    len=0;

    while(p[len] != '\0') 
       {len++;}

    s = new char[len+2];//s-> loc char
    s[0] = len;//loc length

    for(int i=1 ; i < len + 2; i++) 
       {s[i] = p[i - 1];}
    //mov char*p to s
}


myStr::~myStr()
{
   // delete 作用域
}


void myStr::print()
{
    for(int i = 1; i < len + 1; i++)
    { 
        cout << s[i];
    }//s[0] is length
    cout << endl;
}


void myStr::kmp_next()
{
    int i, j;
    next = new int[len+1];
    i = 1;
    j = 0;
    next[0] = len;
    next[1] = 0;

    //s[0]=length

    while(i < len)
    {
        if(j == 0 || s[i] == s[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else 
           j = next[j];
    }
}



void myStr::printNext()
{
    for(int i = 1; i <= len; i++) 
       cout<<next[i];
    cout << endl;
}




void myStr::kmp_nextVal()
{
    int i, j;
    nextval = new int[len + 1];
    i = 1;
    j = 0;
    nextval[1] = 0;
    while(i < len)
    {
        if(j == 0 || s[i] == s[j]){
            i++;
            j++;

            if(s[i] != s[j])
               nextval[i] = j;
            else 
               nextval[i] = nextval[j];
            //此处为与求next数组不同之处，主要是即使回溯更新
        }
        else j = nextval[j];
    }
}


void myStr::printNextVal()
{
    for(int i = 1; i <= len; i++) 
       cout<<nextval[i];
    cout << endl;
}


int kmpMatch(const myStr& S, const myStr& T){
    int i = 1;
    int j = 1;
    while(i <= S.s[0] && j <= T.s[0])
    {
        if(j == 0 || S.s[i] == T.s[j])
        {
            i++;
            j++;
        }
        else j = S.nextval[j];//应用初始化好的nextval数组
    }

    if(j > T.s[0])
       return i - T.s[0];

    return -1;
}
bool replaceStr(myStr& S, const int& start, const myStr& T, const myStr& V){
    
    int campared=0;
    int ptr=start;
    int m=1;


    for(int n = 1; n <= T.len; n++)
    {
        if(S.s[m] == T.s[n])
        {
            m++;
            campared++;
            if(ptr > S.len)
               break;
            continue;
        }

        if(S.s[m] != T.s[n])
        {
            ptr++;
            m = ptr;
            n = 0;
            campared = 0;
            if(ptr > S.len) 
               break;
            continue;
        }
    }

    if(campared != T.len) 
       return 0;


    int ans = ptr;
    int deltaLenth;
    int tmp = ans;

    if(T.len < V.len)
    {
        deltaLenth = V.len - T.len;

        for(int i = S.len + 1; i >= ans + T.len; i--) 
        {
           S.s[i + deltaLenth] = S.s[i];
        }

        for(int i = 1; i <= V.len; i++)
        {
            S.s[tmp] = V.s[i];
            tmp++;
        }

        S.len = S.len + deltaLenth;
    }

    if(T.len > V.len)
    {
        deltaLenth = T.len - V.len;

        for(int i = 1; i <= V.len; i++)
        {
            S.s[tmp] = V.s[i];
            tmp++;
        }

        for(int i = ans + T.len; i <= S.len + 1; i++)
        {
               S.s[i - deltaLenth] = S.s[i];
        }

        S.len = S.len - deltaLenth;
    }

    if(T.len == V.len)
    {
        for(int i = 1; i <= V.len; i++){
            S.s[tmp] = V.s[i];
            tmp++;
        }
    }

    return 1;
}


int simpleMatch(const myStr& S, const myStr& T){
    int campared(0);//标志量
    int ans(1);
    int i(1);
    for(int j = 1; j <= T.len; j++){
        if(S.s[i] == T.s[j]){
            i++;
            campared++;
        }//相同时标志量增加
        else if(S.s[i] != T.s[j]){
            ans++;
            i = ans;
            j = 0;
            campared = 0;
        }//不同时从下一个重新开始循环
        if(ans > S.len) break;
    }
    if(campared != T.len) return -1;
    return ans;
}
myMatrix::myMatrix(const int& rNum, const int& cNum, const int& nNum, const int* p): rn(rNum), cn(cNum), num(nNum) {
    matrix[0][0] = rn;
    matrix[0][1] = cn;
    matrix[0][2] = num;
    //表头分别存储稀疏矩阵的三个信息
    int j = 1;
    for(int i = 0; i < 3*num; i++){
        if((i + 1) % 3 == 1) matrix[j][0] = p[i];
        else if((i + 1) % 3 == 2) matrix[j][1] = p[i];
        else if((i + 1) % 3 == 0) matrix[j][2] = p[i];
        //根据输入数据的规律用对三取模来将不同列数据分开
        j = (i + 1) / 3 + 1;
    }
}
myMatrix::myMatrix(){
    matrix[0][0] = 0;
    matrix[0][1] = 0;
    matrix[0][2] = 0;//初始化为0
}
myMatrix::~myMatrix(){

}
void myMatrix::printMatrix(){
    for(int i = 0; i <= num; i++)
    for(int j = 0; j < 3; j++){
        if(j == 2) cout << matrix[i][j] <<endl;
        else cout<< matrix[i][j] << ",";//正常的数组输出
    }
}
void myMatrix::FastTransposeSMatrix(myMatrix& T){
    int ans(rn);
    rn = cn;
    cn = ans;
    for(int i = 0; i <= num; i++){
        ans = matrix[i][0];
        matrix[i][0] = matrix[i][1];
        matrix[i][1] = ans;//转置操作
    }
    for(int i = 0; i <= num; i++)
    for(int j = 0; j < 3; j++)
    T.matrix[i][j] = matrix[i][j];
    T.rn = rn;
    T.cn = cn;
    T.num = num;
    //将转置后的数据存到T中
}