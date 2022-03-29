
//#include <iostream>
// 
// 
//#include<string>
//#include <stdlib.h> 
//using namespace std;
//int main()
//{
//	long long n;
//	cin >> n;
//	while (n--)
//	{
//		string dat;
//		cin >> dat;
//		long long nu = atoi(dat.c_str());
//		int num = (int)(dat[dat.length()-1])-'0';//num ¸öÎ»Î²Êý
//		//cout << num << endl << nu<<endl;
//		int times = nu % 4;
//
//
//
//		
//		 if(num==1){cout << 1<<endl; }
//
//		 if (num == 2) {if (times == 1)cout << 2 << endl;
//			            if (times == 2)cout << 4 << endl;
//				        if (times == 3)cout << 8 << endl;
//				        if (times == 0)cout << 6 << endl;}
//
//		 if (num == 3) {if (times == 1)  cout << 3 << endl;
//			            if (times == 2)cout << 9 << endl;
//			            if (times == 3)cout << 7 << endl;
//			            if (times == 0)cout << 1 << endl; }
//
//		 if (num == 4)  {int c = nu % 2;
//			            if (c == 0)cout << 6 << endl;
//			            if (c == 1)cout << 4 << endl; }
//
//		 if (num == 5) {cout << 5 << endl; }
//		 if (num == 6) {cout << 6 << endl; }
//
//		 if (num == 7) {if (times == 1) cout << 7 << endl;
//						if (times == 2)cout << 9 << endl;
//						if (times == 3)cout << 3 << endl;
//						if (times == 0)cout << 1 << endl; }
//
//		 if (num == 8) { if (times == 1)  cout << 8 << endl;
//						 if (times == 2)cout << 4 << endl;
//						 if (times == 3)cout << 2 << endl;
//						 if (times == 0)cout << 6 << endl; }
//
//		 if (num == 9) {int c = nu % 2;
//			            if (c == 0)cout << 9 << endl;
//			            if (c == 1)cout << 1 << endl; }
//
//		 if (num == 0) {cout << 0 << endl;}
//		 
//		 
//		}
//	
//
//}

#include <iostream>

long long res(long long a, long long b) {
    if (b == 1) { return a; }

    long long s = res(a, b / 2);

    if (b % 2 == 0) { return (s * s) % 10; }
    if (b%2 !=0) { return (s * s * a) % 10; }
}

int main() {
    int N;
    std::cin >> N;
    while (N--) {
        long long a;
       std:: cin >> a;
       std:: cout << res(a, a) << std::endl;
    }
    return 0;
}




//
//int main() {
//    int N;
//    cin >> N;
//    while (N--) {
//        long long a;
//        cin >> a;
//        cout << res(a) << endl;
//    }
//    return 0;
//}
//}////