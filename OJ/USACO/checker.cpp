/*
ID: zhangsh35
PROG: checker 
LANG: C++
*/
#include<stdio.h>
#include<iostream>
using namespace std;
const int MAXN=100;
bool right_line[MAXN];//主对角线 
bool left_line[MAXN];//副对角线 
bool rows[MAXN];//数 
int que[MAXN];//记录结果 
int  cols;//列数 
int cnt=0;//计数 
void dfs(int num); 
#define LOCAL
int main()
{
	#ifdef LOCAL
	freopen("checker.in","r",stdin);
	freopen("checker.out","w",stdout);
	#endif
	cin>>cols;
	dfs(1);
	cout<<cnt<<endl;
	return 0;	
}
void dfs(int num)
{
	if(num==cols+1)
	{
		cnt++;
		if(cnt<=3)
		{
			int i=0;
			for(i=1;i<cols;i++)
			cout<<que[i]<<" ";
			cout<<que[i]<<endl;
		}
	}
	else
	{
		int i,j;
		for(i=1;i<=cols;i++)
		{
			if(!rows[i]&&!right_line[num-i+cols]&&!left_line[num+i])//letf和right也是保留字= = 
			{
				que[num]=i;//right不+cols可能为负数，溢出了 
				rows[i]=true;
				right_line[num-i+cols]=true;
				left_line[num+i]=true;
				dfs(num+1);	
				rows[i]=false;
				right_line[num-i+cols]=false;
				left_line[num+i]=false;
				
			}
		}
	}
}
