#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	long long n;
	cin >> n;
	long long a = 0;
	long long k;
	long long b1 = 0, b2 = 0;
	for (long long i = 0; i < n; i++)
	{
		cin >> k;
		a += k;
	}

	//cout << a<<endl;

	for (long long i = 0; i < n; i++)
	{
		cin >>k;
		if (k > b1 || k>b2) { b1 = max(b1,b2); b2 = k; }

	}
	//cout << b1 << endl << b2 << endl;

	if ((b1 + b2) >= a)cout << "YES" << endl;
	else cout << "NO" << endl;
}