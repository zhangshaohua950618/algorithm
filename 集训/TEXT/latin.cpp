#include<iostream>
using namespace std;
int f[10];
int main()
{
	int n;
	f[2]=1;
	cin>>n;
	for(int i=3;i<=n;i++)
	{
		f[i]=1;
		for(int j=1;j<=i-1;j++)
		f[i]*=j;
		f[i]*=f[i-1];
	}
	cout<<f[n]<<endl;
	return 0;
	
}

