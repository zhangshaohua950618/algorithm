/*
ID: zhangsh35
PROG: agrinet 
LANG: C++
*/
#include<stdio.h>
#include<iostream>
using namespace std;
const int MAXN=100+10;
int path[MAXN][MAXN];
int low[MAXN];
bool visited[MAXN];
#define LOCAL
int main()
{
	#ifdef LOCAL
	freopen("agrinet.in","r",stdin);
	freopen("agrinet.out","w",stdout);
	#endif
	int rows,max=0,result=0,min=0;
	int i,j;
	cin>>rows;
	for(i=0;i<rows;i++)
	for(j=0;j<rows;j++)
	{
	cin>>path[i][j];
	if(path[i][j]>max)
	max=path[i][j];
	}
	int pos=0;
	visited[pos]=true;
	for(i=0;i<rows;i++)
	low[i]=path[pos][i];
	for(i=1;i<rows;i++)
	{
		min=max;
		for(j=0;j<rows;j++)
		if(!visited[j]&&low[j]<min)//找出权值最小的数 
		{
			min=low[j];
			pos=j;
		}
	//	cout<<"min="<<min<<endl;
		result+=min;
		visited[pos]=true;
		for(j=0;j<rows;j++)
		{
			if(!visited[j]&&path[pos][j]<low[j])
			low[j]=path[pos][j];
		}
	}
	cout<<result<<endl;
	
	
	
	
} 
