/*
ID: zhangsh35
PROG: checker 
LANG: C++
*/
#include<stdio.h>
#include<iostream>
using namespace std;
const int MAXN=100;
bool right_line[MAXN];//���Խ��� 
bool left_line[MAXN];//���Խ��� 
bool rows[MAXN];//�� 
int que[MAXN];//��¼��� 
int  cols;//���� 
int cnt=0;//���� 
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
			if(!rows[i]&&!right_line[num-i+cols]&&!left_line[num+i])//letf��rightҲ�Ǳ�����= = 
			{
				que[num]=i;//right��+cols����Ϊ����������� 
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
