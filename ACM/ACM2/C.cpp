#include <iostream>
using namespace std;
int group;
int n;
int day[10005] = { 0 };


bool check(int mid) 
{
	int lg = 1;
	int sum = 0;
	for (int i = 1; i <= n; ++i)
	{
		if (sum + day[i] <= mid) { sum = sum + day[i]; }
		else { lg++; sum = day[i]; }
	}

	return (lg <= group);

};
int main()
{
	
	cin >> n >> group;
	
	int low = 0;
	long long high = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> day[i];
		if (day[i] > low) { low = day[i]; }

	}

	for (int i = 1; i <= n; i++)
	{
		high += day[i];
	}

	int mid = high;

	while (low != high)
	{
		mid = (low + high) / 2;
		if (check(mid)) { high = mid; }
		else { low = mid+1; }
	}

	cout << low;

}
