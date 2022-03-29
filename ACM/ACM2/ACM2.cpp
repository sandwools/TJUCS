#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		long long num;
		cin >> num;

		int money[8] = { 0 };
		for (int i = 1; i <= 7; i++)
		{
			cin >> money[i];
		}

		int val[8] = { 0,100,50,20,10,5,2,1 };
		long long key = 0;

		for (int i = 1; i <= 7; i++)
		{
			while (num >= val[i] && money[i] > 0)
			{
				num = num - val[i];
				money[i]--;
				key++;
			}
		}

		if (num == 0) { cout << key << endl; }
		else { cout << -1<<endl; }
	}
}

