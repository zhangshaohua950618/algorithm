/*
ID: zhangsh35
PROG: money
LANG: C++                  
*/
#include<iostream>
#include<string.h>
using namespace std;
const int MAXN=100000;
long long money[MAXN];
int type[MAXN];
int main()
{
int tot;
int kind;
cin>>kind>>tot;
int i,j;
for(i=0;i<kind;i++)
{
cin>>type[i];
}
memset(money,0,sizeof(money));
money[0]=1;
for(i=0;i<kind;i++)
{
	for(j=type[i];j<=tot;j++)
	{
		money[j]+=money[j-type[i]];
	}
} 
cout<<money[tot]<<endl;
return 0;
}
