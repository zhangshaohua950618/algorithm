#include <iostream>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int maxi = 0, temp;
		for (int i = 1;i <= n;i++)
		{
			cin >> temp;
			if (temp > maxi)
				maxi = temp;
		}
		cout << temp << endl;
	}
	return 0;
}
