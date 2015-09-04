/*
ID: zhangsh35
PROG: subset 
LANG: C++
*/
#include<stdio.h>
#include<iostream>
using namespace std;
const int MAXN=400;
long long subset[MAXN];//前i个数组成j的方案数目 
bool cc[MAXN];
#define LOCAL
int main()
{
	#ifdef LOCAL
	freopen("subset.in","r",stdin);
	freopen("subset.out","w",stdout);
	#endif
	int max;
	cin>>max;
	int i,j;
	subset[0]=1;
	if(max*(max+1)/2%2)
	{
		cout<<"0"<<endl;
		return 0;
	}
	for(i=1;i<=max;i++)
	for(j=max*(max+1)/4;j>=i;j--)		
		subset[j]+=subset[j-i];

	cout<<subset[max*(max+1)/4]/2<<endl;
	return 0;
}

