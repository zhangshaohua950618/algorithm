/*
ID: zhangsh35
PROG: ditch 
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std;
const int INF=0x7fffffff;
const int MAXN=200+10;
#define Min(a,b) ((a)<(b)?(a):(b))
int path[MAXN][MAXN];
int main()
{
	ifstream cin("ditch.in");
	ofstream cout("ditch.out");
	int i,j,k;
	int tot_path,tot_node,start,end,dis;
	cin>>tot_path>>tot_node;
	for(i=1;i<=tot_path;i++)
	{
		cin>>start>>end>>dis;
		path[start][end]+=dis;
	}
	for(k=tot_node;k>=1;k--)
	{	
	cout<<k<<endl;
	for(i=1;i<=tot_node;i++)
	{
	for(j=1;j<=tot_node;j++)
	{
	path[i][j]+=Min(path[i][k],path[k][j]);
	cout<<path[i][j]<<" ";
	}
	cout<<endl;
	}
	cout<<endl;
	}
	cout<<path[1][tot_node]<<endl;
	return 0;
}
