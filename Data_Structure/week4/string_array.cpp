#include "string_array.h"
#include <iostream>
using namespace std;
myStr::myStr(const char* p){
    int ans(0);
    int i;
    while(p[ans] != '\0') ans++;
    len = ans;//真正意义的字符串长度
    s = new char[100000];//动态分配内存
    s[0] = len;//第一个元素存储长度
    for(i = 1; i < len + 2; i++) s[i] = p[i - 1];//将数组元素导入字符串
}
myStr::~myStr(){

}
void myStr::print(){
    for(int i = 1; i < len + 1; i++) cout << s[i];//按序输出
    cout << endl;
}
void myStr::kmp_next(){
    int i, j;
    next = new int[len + 1];
    i = 1;
    j = 0;
    next[1] = 0;
    while(i < s[0]){//判断标志
        if(j == 0 || s[i] == s[j]){
            ++i;
            ++j;
            next[i] = j;
        }
        else j = next[j];
    }
    //标准的求next数组方法
}
void myStr::kmp_nextVal(){
    int i, j;
    nextval = new int[len + 1];//动态分配内存
    i = 1;
    j = 0;
    nextval[1] = 0;
    while(i < s[0]){
        if(j == 0 || s[i] == s[j]){
            ++i;
            ++j;
            if(s[i] != s[j]) nextval[i] = j;
            else nextval[i] = nextval[j];
            //此处为与求next数组不同之处，主要是即使回溯更新
        }
        else j = nextval[j];
    }
}
void myStr::printNext(){
    for(int i = 1; i <= len; i++) cout<<next[i];//普通的输出
    cout << endl;
}
void myStr::printNextVal(){
    for(int i = 1; i <= len; i++) cout<<nextval[i];//普通的输出
    cout << endl;
}
int kmpMatch(const myStr& S, const myStr& T){
    int i = 1;
    int j = 1;
    while(i <= S.s[0] && j <= T.s[0]){
        if(j == 0 || S.s[i] == T.s[j]){
            ++i;
            ++j;
        }
        else j = S.nextval[j];//应用初始化好的nextval数组
    }
    if(j > T.s[0]) return i - T.s[0];
    return -1;
    //标准的找到相同字符串位置的算法
}
bool replaceStr(myStr& S, const int& start, const myStr& T, const myStr& V){
   int flag(0);//标志量
    int a(start);
    int m(1);
    for(int n = 1; n <= T.len; n++){
        if(S.s[m] == T.s[n]){
            m++;
            flag++;
        }//相同时标志量增加
        else if(S.s[m] != T.s[n]){
            a++;
            m = a;
            n = 0;
            flag = 0;
        }//不同时从下一个重新开始循环
        if(a > S.len) break;
    }
    if(flag != T.len) return 0;
    //以上操作为找到相同部分的位置
    int ans = a;
    int l;
    int tmp = ans;
    if(T.len < V.len){
        l = V.len - T.len;
        for(int i = S.len + 1; i >= ans + T.len; i--) S.s[i + l] = S.s[i];
        for(int i = 1; i <= V.len; i++){
            S.s[tmp] = V.s[i];
            tmp++;
        }
        S.len = S.len + l;
    }//替换串长则从后向前替换
    else if(T.len > V.len){
        l = T.len - V.len;
        for(int i = 1; i <= V.len; i++){
            S.s[tmp] = V.s[i];
            tmp++;
        }
        for(int i = ans + T.len; i <= S.len + 1; i++) S.s[i - l] = S.s[i];
        S.len = S.len - l;
    }//替换串短则从前向后替换
    else{
        for(int i = 1; i <= V.len; i++){
            S.s[tmp] = V.s[i];
            tmp++;
        }
    }//同长则正常替换
    return 1;
    //此处为替换字符串部分
}
int simpleMatch(const myStr& S, const myStr& T){
    int flag(0);//标志量
    int ans(1);
    int i(1);
    for(int j = 1; j <= T.len; j++){
        if(S.s[i] == T.s[j]){
            i++;
            flag++;
        }//相同时标志量增加
        else if(S.s[i] != T.s[j]){
            ans++;
            i = ans;
            j = 0;
            flag = 0;
        }//不同时从下一个重新开始循环
        if(ans > S.len) break;
    }
    if(flag != T.len) return -1;
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