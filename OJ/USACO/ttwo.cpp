/*
ID: zhangsh35
PROG: ttwo 
LANG: C++
*/
#include<stdio.h>
#include<iostream>
using namespace std;
int path[15][15];
#define LOCAL
int direction_farmer=1;
int direction_cow=1;
void action(int time);
struct location
{
	int x;
	int y;
};
location farmer,cow;
int main()
{
	#ifdef LOCAL
	freopen("ttwo.in","r",stdin);
	freopen("ttwo.out","w",stdout);
	#endif
	int i,j;
	char temp;
	for(i=1;i<=10;i++)//input
	for(j=1;j<=10;j++)
	{
		cin>>temp;
		path[i][j]=temp=='*'?0:1;
		if(temp=='F')
		{
			farmer.x=i;
			farmer.y=j;
		}
		if(temp=='C')
		{
			cow.x=i;
			cow.y=j;
		}
	}
/*	for(i=1;i<=10;i++)
	{
	for(j=1;j<=10;j++)
	{
		cout<<path[i][j];
		
	}
	cout<<endl;
	}*/
	action(0);
	return 0;
}
void action(int time)
{
//	cout<<"Farmer("<<farmer.x<<","<<farmer.y<<")"<<"Cow("<<cow.x<<","<<cow.y<<")"<<endl;
	if(time>160000)
	{
	cout<<"0"<<endl; 
	return;
	}
	else if(farmer.x==cow.x&&farmer.y==cow.y)
	{
	cout<<time<<endl;
	return;
	}
	else//
	{
		if(direction_farmer==1)
		{
		//	cout<<path[farmer.x][farmer.y-1]<<"("<<farmer.x<<","<<farmer.y-1<<")"<<endl;
			if(path[farmer.x-1][farmer.y])
				farmer.x-=1;
			else
				direction_farmer=(direction_farmer+1)%4;
		}
		else if(direction_farmer==2)
		{
			if(path[farmer.x][farmer.y+1])
				farmer.y+=1;
			else
				direction_farmer=(direction_farmer+1)%4;
		}
		else if(direction_farmer==3)
		{
			if(path[farmer.x+1][farmer.y])
				farmer.x+=1;
			else
				direction_farmer=(direction_farmer+1)%4;
		}
		else if(direction_farmer==0)
		{
			if(path[farmer.x][farmer.y-1])
				farmer.y-=1;
			else
				direction_farmer=(direction_farmer+1)%4;
		}
		if(direction_cow==1)
		{
			if(path[cow.x-1][cow.y])
				cow.x-=1;
			else
				direction_cow=(direction_cow+1)%4;
		}
		else if(direction_cow==2)
		{
			if(path[cow.x][cow.y+1])
				cow.y+=1;
			else
				direction_cow=(direction_cow+1)%4;
		}
		else if(direction_cow==3)
		{
			if(path[cow.x+1][cow.y])
				cow.x+=1;
			else
				direction_cow=(direction_cow+1)%4;
		}
		else if(direction_cow==0)
		{
			if(path[cow.x][cow.y-1])
				cow.y-=1;
			else
				direction_cow=(direction_cow+1)%4;
		}
		action(time+1);
	}
	
}
