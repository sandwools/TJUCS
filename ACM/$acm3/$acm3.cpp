#include <iostream>
using namespace std;
void core(int n)
{
	head:
	int fin[1000];
	int stack[1000];
	for (int i = 1; i <= n; i++)
	{
		cin >> fin[i];
	}

	{
		//work core
		for (int i = 1; i <= n; i++)
		{

		}
	}


	cin >> n;
	if (n != 0)goto head;
	return;
}

int main()
{
	while (1)
	{
		int n;
		cin >> n;


		if (n == 0)
		{
			return 0;
		}

		core(n);
	}
}


