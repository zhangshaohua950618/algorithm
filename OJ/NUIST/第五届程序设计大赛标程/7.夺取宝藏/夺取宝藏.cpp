#include <iostream>
using namespace std;

long array[1001][1001], m, n, f[1001][1001];

long maxi(long a, long b)
{
	return a > b ? a:b;
}

long DP()
{
	for (int i = 1;i <= m;i++)
		for (int j = 1;j <= n;j++)
			f[i][j] = maxi(f[i-1][j], f[i][j-1])+array[i][j];
	return f[m][n];
}

int main()
{
	while (cin >> m >> n)
	{
		for (int i = 1;i <= m;i++)
			for (int j = 1;j <= n;cin >> array[i][j],f[i][j] = 0, j++);
		cout << DP() << endl;
	}
	return 0;
}
