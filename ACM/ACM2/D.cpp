#include<iostream>
#include <algorithm>
//#include<bits/stdc++.h>
using namespace std;



int main()
{
	int n;
	cin >> n;
	int a[1000] = { 0 };
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	sort(a,a + n);

	int key = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			for (int k = j + 1; k < n; k++)
			{
				if (a[i] + a[j] > a[k])key++;

			}
		}
	}

	cout << key;


}
