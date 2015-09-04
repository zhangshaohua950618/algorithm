/*
ID: zhangsh35
PROG: fact4 
LANG: C++
*/
#include<stdio.h>
#include<iostream>
using namespace std;
#define LOCAL
int main()
{
	#ifdef LOCAL
	freopen("fact4.in","r",stdin);
	freopen("fact4.out","w",stdout);
	#endif
	int n;
	cin>>n;
	int i,sub=1;
	for(i=1;i<=n;i++)
	{
		sub*=i;
		while(!(sub%10))
		{
			sub/=10;
		}
		sub%=10000;
		cout<<i<<" "<<sub<<endl;
	}
}
