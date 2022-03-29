////#include<iostream>
////#include<cmath>
////#include <algorithm>
////using namespace std;
////int main()
////{
////	int n;
////	cin >> n;
////	long long a[1001];
////	int key = 0;
////	for(int i=0;i<n;i++)
////	{ 
////		cin >> a[i];
////	}
////
////	sort(a, a + n);
////
////	for (int i = 0; i < n - 2; i++) {
////		for (int j = i + 1; j < n - 1; j++) {
////			for (int k = j + 1; k < n; k++) {
////				if (a[i] + a[j] == a[k]) {
////					key++;
////				}
////			}
////		}
////	}
////
////	//for (int i = 0; i < n; i++)
////	//{
////	//	for (int j = i + 1; j < n; j++)
////	//	{
////	//		long long sum1 = a[i] + a[j];
////
////	//		for (int x = 0; x < n; x++)
////	//		{
////	//			if(sum1==a[x]&&a[j]!=a[i]){key++;}
////	//		}
////
////	//		//for (int x = i+1; x < j; x++)
////	//		//{
////	//		//	for (int y = i + 2; y < j; y++)
////	//		//	{
////	//		//		long long sum2 = a[x] + a[y];
////
////	//		//		if ((sum1 == sum2)&&x!=y)
////	//		//		{
////	//		//			key++; //cout << a[i] << " " << a[j] << ".." << a[x] << " " << a[y]<<endl;
////	//		//		}
////	//		//	}
////	//		//}
////
////
////
////	//	}
////	//}
////
////	cout << key;
////}
//
//#include<string.h>
//#include<bits/stdc++.h>
//#include<algorithm>
//#include<math.h>
//#define M(a) memset(a,0,sizeof(a))
//using namespace std;
//int a[1002];
//int b[1002];
//int main()
//{
//    int n;
//    memset(b, 0, sizeof(b));
//    scanf("%d", &n);
//    for (int i = 0; i < n; ++i)
//    {
//        scanf("%d", &a[i]);
//    }
//    int num = 0;
//    sort(a, a + n);
//    for (int q = 0; q < n - 2; ++q)
//    {
//        for (int i = q + 1; i < n - 1; ++i)
//        {
//            for (int j = i + 1; j < n; ++j)
//            {
//                if (b[j] == 0 && a[j] == a[q] + a[i])
//                {
//                    ++num;
//                    b[j] = 1;
//                }
//            }
//        }
//    }
//    printf("%d\n", num);
//    return 0;
//}


#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N, a[1001] = { 0 }, x[1001] = { 0 };
    int to = 0;

    cin >> N;
    int n = N;
   while(N--) {
        cin >> a[N];
    }

    sort(a, a + n);


    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                if (a[i] + a[j] == a[k]) {
                    x[k] = 1;
                }
            }
        }
    }

    int key=0;

    for (int i = 0; i < n; i++) {
        to =to+ x[i];
        key = to;
    }
    cout << key << endl;
}
