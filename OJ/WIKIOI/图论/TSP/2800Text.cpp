#include<cstdio>
#include<iostream>
using namespace std;
const int MAXN=15;
const int INF=1<<30;

int n;
int d[MAXN+1][MAXN+1];
int f[1<<(MAXN+1)][MAXN+1];
int ans;

int getint(void)
{
	int a;
	scanf("%d",&a);
	return a;
}

int min(int a,int b)
{
	return a<b?a:b;
}

void init(void)
{
	n=getint();
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			d[i][j]=getint();
		}
	}
}

void floyd(void)
{
	for(int k=0;k<=n;k++)
	{
		for(int u=0;u<=n;u++)
		{
			for(int v=0;v<=n;v++)
			{
				d[u][v]=d[u][v]<(d[u][k]+d[k][v])?d[u][v]:(d[u][k]+d[k][v]);
			}
		}
	}
}

void dp(void)
{
	for(int s=0;s<1<<(n+1);s++)
	{
		for(int i=0;i<=n;i++)
		{
			f[s][i]=INF;
		}
	}
	for(int i=0;i<=n;i++)
	{
		f[1<<i][i]=d[0][i];
	}
	for(int s=0;s<1<<(n+1);s++)
	{
		for(int v=0;v<=n;v++)
		{
			for(int u=0;u<=n;u++)
			{
				if(s>>u&1)
				{
					f[s][v]=min(f[s][v],f[s&~(1<<v)][u]+d[u][v]);
					//printf("%d\n",f[s][v]);
				}
			}
		}
	}
}

void solve(void)
{
	floyd();
	int i , j;
	for(i = 0;i <= n ; i++){
		for(j = 0 ; j <= n ; j++)
		cout<<d[i][j]<<" ";
		cout<<endl; 
	}
	dp();
}

void output(void)
{
	ans=INF;
	int s=(1<<(n+1))-1;
	for(int i=1;i<=n;i++)
	{
		ans=ans<(f[s][i]+d[i][0])?ans:(f[s][i]+d[i][0]);
	}
	printf("%d\n",ans);
}

int main()
{
	init();
	solve();
	output();
	return 0;
}

	
