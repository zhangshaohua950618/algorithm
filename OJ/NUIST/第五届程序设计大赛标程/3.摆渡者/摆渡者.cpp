#include <iostream>
using namespace std;
 
int main()
{
	int n;
	while (cin >> n)
	{
		int array[10000], counter = 0;
		for (int i = 1;i <= n;cin >> array[i], i++);
		for (int i = 1;i < n;i++)
		{
			bool flag = false;
			for (int j = 1;j < n;j++)
				if (array[j] > array[j+1])
				{
					int temp = array[j];
					array[j] = array[j+1];
					array[j+1] = temp;
					counter++;
					flag = true;
				}
			if (!flag)
				break;
		}
		cout << counter << endl;
	}
	return 0;
}
