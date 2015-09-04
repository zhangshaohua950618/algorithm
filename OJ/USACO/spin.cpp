/*
ID: zhangsh35
PROG: spin 
LANG: C++
*/
#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;
int speed[5];
int num[5];
int start[25+5];
int width[25+5];
bool spin[5][360];
#define LOCAL
int main()
{
	#ifdef LOCAL
	freopen("spin.in","r",stdin);
	freopen("spin.out","w",stdout);
	#endif
	int time=0;
	int i,j,k=0;
	bool ok;
	for(i=0;i<5;i++)
	{
		cin>>speed[i]>>num[i];
		for(j=0;j<num[i];j++)
		{
		cin>>start[k]>>width[k];//为什么不能写成 cin>>start[k]>>width[k++]
		k++;
		}
	}
/*	for(i=0;i<k;i++)
	cout<<start[i]<<" "<<width[i]<<endl;*/
	long long time_limit=1;//要用long long 可能太大存不下 text4 
	for(i=0;i<5;i++)
	{
		time_limit*=(360/speed[i]+1);
	}
//	cout<<time_limit<<endl;
	while(time<=time_limit)
	{
	//	cout<<"time="<<time<<endl;;
		k=0;
		memset(spin,false,sizeof(spin));
		for(i=0;i<5;i++)
		{
			for(j=0;j<num[i];j++)
			{
			//	cout<<start[k]<<" "<<start[k]+width[k]+speed[i]*time<<endl;
				for(int l=start[k]+speed[i]*time;l<=start[k]+width[k]+speed[i]*time;l++)
				{
					if((!i)||spin[i-1][l%360])//可以加判断用goto优化 
					spin[i][l%360]=true;
				}
				k++;
			}
		/*	for(j=0;j<360;j++)
			{
			if(spin[i][j])
				cout<<j; 
			else
			cout<<" ";
			cout<<" ";
			}
			cout<<endl;*/
		}
		for(i=0;i<360;i++)
		if(spin[4][i])
		{
			cout<<time<<endl;
			return 0;
		}
		time++;
		
	}
	cout<<"none"<<endl;
	return 0;
}
