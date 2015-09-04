#include<iostream>
#include<string.h>
using namespace std;
const int MAXN=30+10;
void dfs(int num);
int tot;
long count;
int res[MAXN];
int main()
{
	while(cin>>tot)
	{
		memset(res,0,sizeof(res));
		count=0;
		dfs(0);
		cout<<count<<endl;
	}
	
}
void dfs(int num)
{
	if(tot==1)
	{
		count=3;
	}
	else if(num==tot)
	{
		if(res[0]!=res[tot-1])
		{
			count++;
		}
	}
	else
	{
		int i;
		for(i=0;i<3;i++)
		{
			if(num==0)
			{
				res[num]=i;
				dfs(num+1);
			}
			else
			{
				if(i!=res[num-1])
				{
					res[num]=i;
					dfs(num+1);
				}
			}
		}
	}
	
}
