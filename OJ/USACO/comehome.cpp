/*
ID: zhangsh35
PROG: comehome 
LANG: C++
*/
#include<iostream>
#include<fstream>
#include<map>
using namespace std;
const int MAXN=52+5;
const int INF=0x7fffffff;
#define Min(a,b) ((a)<(b)?(a):(b))
int path[MAXN][MAXN];
int main()
{
	ifstream cin("comehome.in");
	ofstream cout("comehome.out");
	int i,j,k;
	map<char,int> to_int;
	for(i=1;i<=26;i++)
	to_int[i+64]=i;
	for(i=27;i<=52;i++)
	to_int[i+70]=i;
//	cout<<to_int['A']<<endl;
	int tot,dis;//start,end应该是int,简洁点了 
	char start,end;
	cin>>tot;
	for(i=1;i<=52;i++)//C初始化 
	for(j=1;j<=52;j++)
		path[i][j]=path[j][i]=i==j?0:INF;
	for(i=0;i<tot;i++) 
	{
		cin>>start>>end>>dis;
	//	cout<<start<<end<<dis;
	//	cout<<to_int[start]<<" "<<to_int[end]<<endl;
		path[to_int[start]][to_int[end]]=Min(dis,path[to_int[start]][to_int[end]]);
		path[to_int[end]][to_int[start]]=Min(dis,path[to_int[end]][to_int[start]]);
	}
/*	for(i=1;i<=52;i++)
	{
	for(j=1;j<=52;j++)
	{
		cout<<path[i][j]<<" ";
	}
	cout<<endl;
	}*/
	//行从1~52；
	//列从1~52； 
	for(k=1;k<=52;k++)//foryd 
	for(i=1;i<=52;i++)
	for(j=1;j<=52;j++)
	if(path[i][k]!=INF&&path[k][j]!=INF)//不能喝INF相加，会溢出的~~ 
	path[i][j]=Min(path[i][j],path[i][k]+path[k][j]);
	int min_path=path[1][26],min_cow=1;
	for(i=2;i<26;i++)
		if(path[i][26]<min_path)
		{
			min_path=path[i][26];
			min_cow=i;
		}
		cout<<char(min_cow+64)<<" "<<min_path<<endl;
	return 0;
}
