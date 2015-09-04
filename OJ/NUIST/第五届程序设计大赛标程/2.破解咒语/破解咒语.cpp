#include <iostream>
#include <cstring>
using namespace std;

string s;
int counter['z'+1];

int main()
{
	while (cin >> s)
	{
		for (int i = 'a';i <= 'z';counter[i] = 0, i++);
		int len = s.length();
		for (int i = 0;i < len;counter[s[i]]++, i++);
		for (char i = 'a';i <= 'z';i++)
			if (counter[i] == 1)
				cout << i;
		cout << endl;
	}
	return 0;
}
