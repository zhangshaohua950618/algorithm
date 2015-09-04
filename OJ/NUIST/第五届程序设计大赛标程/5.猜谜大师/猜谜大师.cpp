#include <iostream>
#include <cmath>
using namespace std;

double x0, x1, a[7];

double f(double x)
{
	return a[6]+a[5]*x+a[4]*pow(x, 2)+a[3]*pow(x, 3)+a[2]*pow(x, 4)
			+a[1]*pow(x, 5);
}

double bisearch()
{
	double eps = 1e-6, mid;
	while (x1-x0 >= eps)
	{
		mid = (x0+x1)/2;
		double f_x0 = f(x0), f_mid = f(mid);
		if (fabs(f_x0) < eps)
			return x0;
		if (fabs(f_mid) < eps)
			return mid;
		if (f_x0*f_mid < 0)
			x1 = mid;
		else
			x0 = mid;
	}
	return mid;
}

int main()
{
	while (cin >> a[1])
	{
		for (int i = 2;i <= 6;cin >> a[i], i++);
		cin >> x0 >> x1;
		printf("%.4lf\n", bisearch());
	}
	return 0;
}
