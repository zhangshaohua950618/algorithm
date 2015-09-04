/*
ID: zhangsh35
PROG: fence 
LANG: C++
*/
#include<stdio.h>
#include<iostream>
#include<set>
using namespace std;
int path[500+10][500+10];
int way[500+10];
int node[500+10];
int max_length=0;
int length=0;
int max_node=0;
void Euler(int node);
#define LOCAL
set<int> s;
set<int>::iterator it;
int main()
{
	#ifdef LOCAL
	freopen("fence.in","r",stdin);
	freopen("fence.out","w",stdout);
	#endif
	cin>>max_length;
	int i;
	int start,end;
	for(i=1;i<=max_length;i++)
	{
		cin>>start>>end;
		s.insert(start);
		s.insert(end);
		path[start][end]++;
		path[end][start]++;	
	}
	for(it=s.begin();it!=s.end();it++)
	node[max_node++]=*it;
	for(i=0;i<max_node;i++)
	{
		length=0;
		way[length++]=(node[i]);
		Euler(node[i]);
	}
	return 0;
}
void Euler(int n)
{
	if(length==max_length+1)
	{
		int i=0;
		for(i=0;i<max_length+1;i++)
		cout<<way[i]<<endl;
		exit(0);
	}
	else
	{
	//	cout<<"else"<<endl;
		int i,j;
		for(i=0;i<max_node;i++)
		{
			if(path[n][node[i]])
			{
				way[length++]=node[i];
				path[n][node[i]]--;
				path[node[i]][n]--;
				Euler(node[i]);
				path[node[i]][n]++;
				path[n][node[i]]++;
				length--;
			}
		}
	}
	
}
