#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	int m = a > b ? a:b, n = a < b ? a:b, r;
	while (n != 0)
	{
		r = m%n;
		m = n;
		n = r;
	}
	return m;
}

int main()
{
	int a, b;
	while (cin >> a >> b)
	{
		int GCD = gcd(a, b);
		cout << a/GCD << ' ' << b/GCD << endl;
	}
	return 0;
}
