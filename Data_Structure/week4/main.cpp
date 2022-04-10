#include"string_array.cpp"
using namespace std;

int main()
{
myStr S("hello TJU!");
myStr T("TJU");
myStr T1("NKU");
myStr T2("future");

int isFind;

isFind=replaceStr(S,8,T1,T2);
cout<<isFind<<endl;//0
isFind=replaceStr(S,1,T, T2);
cout<<isFind<<endl;//1
S.print();//hello future!
isFind=replaceStr(S,1,T1, T2);
cout<<isFind<<endl;//0

myStr matchS("aabaabaabaac");
myStr matchT("aabaac");

isFind=simpleMatch(matchS,matchT);
cout<<isFind<<endl;//7

matchS.kmp_next();
matchS.kmp_nextVal();
matchS.printNext();//012123456789
matchS.printNextVal();//002002002009

matchT.kmp_next();
matchT.kmp_nextVal();
matchT.printNext();//012123
matchT.printNextVal();//002003

isFind=kmpMatch(matchS,matchT);
cout<<isFind<<endl;//7

system("pause");

}