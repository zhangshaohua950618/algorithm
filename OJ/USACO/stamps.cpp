/*
ID: zhangsh35
PROG: stamps 
LANG: C++
*/
#include<iostream>
using namespace std;
#include<stdio.h>
int stamps[2000000+10];
int a[200+10];
#define LOCAL
int main()
{
	#ifdef LOCAL
	freopen("stamps.in","r",stdin);
	freopen("stamps.out","w",stdout);
	#endif
	int tot,num;
	int i,j;
	cin>>tot>>num;
	for(i=0;i<num;i++)
	cin>>a[i];
	i=0;
	while(stamps[i]<=tot)
	{
		i++;
		stamps[i]=tot+1;
	//	cout<<"i="<<i<<endl;
		for(j=0;j<num;j++)
			if((i-a[j])>=0)//不判定结果就是15，想不通 
		stamps[i]=stamps[i]<(stamps[i-a[j]]+1)?stamps[i]:(stamps[i-a[j]]+1);
	}
	cout<<i-1<<endl;
	
}
