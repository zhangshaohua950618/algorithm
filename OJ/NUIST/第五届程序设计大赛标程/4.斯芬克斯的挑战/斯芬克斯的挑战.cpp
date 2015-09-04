#include <iostream>
using namespace std;

int array[1000], n, counter;

void dfs(int rsm, int j)
{
	if (rsm == 0)
	{
		counter++;
		return;
	}
	for (int i = array[j];i <= rsm;i++)
	{
		array[j+1] = i;
		dfs(rsm-i, j+1);
	}
}

int main()
{
	while (cin >> n)
	{
		counter = 0;
		for (int i = 1;i <= (n>>1);i++)
		{
			array[1] = i;
			dfs(n-i, 1);
		}
		cout << counter << endl;
	}
	return 0;
}
