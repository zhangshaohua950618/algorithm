/*
ID: zhangsh35
PROG: lamps 
LANG: C++
*/
#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
void dfs(int num);
const int MAXN=100+10;
int lamp_on[MAXN];
int lamp_off[MAXN];
bool lamp[MAXN];
bool cc[4];
int tot_lamp;
int tot_cnt;
int temp;
int cnt;
int k1=0,k2=0;
int res[MAXN][MAXN]=0;
int before=-1;
int key;
int sum=0;
#define LOCAL
int main()
{
	#ifdef LOCAL
	freopen("lamps.in","r",stdin);
	freopen("lamps.out","w",stdout);
	#endif
	memset(lamp,true,sizeof(lamp));
	cin>>tot_lamp>>tot_cnt;
	
	while(cin>>temp&&temp!=-1)
	{
		lamp_on[k1++]=temp;
	}
	while(cin>>temp&&temp!=-1)
	{
		lamp_off[k2++]=temp;
	}
	key=tot_cnt;
/*	for(int j=0;j<k2;j++)
	{
		cout<<lamp_off[j]<<" ";
	}*/
/*	cout<<k1<<k2<<endl;*/
		if(!tot_cnt%2)
		tot_cnt=0;
		else
		tot_cnt=1;
	do
	{
		memset(lamp,true,sizeof(lamp));
		memset(cc,false,sizeof(cc));
		dfs(0);
		tot_cnt+=2;
	}while(tot_cnt<=(4>key?key:4));
//	dfs(0);
/*	tot_cnt-=2;
	cout<<tot_cnt<<endl;
	memset(lamp,true,sizeof(lamp));
	memset(cc,false,sizeof(cc));
	dfs(0);*/
//	cout<<res<<endl;
	if(!res)
	cout<<"IMPOSSIBLE"<<endl;
	return 0;
} 
void dfs(int num)
{
//	cout<<tot_cnt<<endl;
//	cout<<num<<endl; 
//	cout<<num<<tot_cnt<<endl;
	if(num==tot_cnt)
	{
	/*		for(int i=1;i<=tot_lamp;i++)
				cout<<lamp[i];
				cout<<endl;*/
		int i=0,j=0,l=0;
		for(i=0;i<k1;i++)
		{
			if(lamp[lamp_on[i]]!=true)
			break;
		}	
		for(j=0;j<k2;j++)
		{
			if(lamp[lamp_off[j]]!=false)
			break;
		}
	/*	for(j=0;j<k2;j++)
		{
			cout<<lamp_off[j]<<" ";
		}
		cout<<endl;
		cout<<k1<<k2<<endl;
		cout<<i<<j<<endl;*/
		if(i==k1&&j==k2)
		{
			
			for(l=1;l<=tot_lamp;l++)
			{
				if(lamp[l])
				res[sum][l]=1;
				else
				res[sum][l]=0;
			}
			sum++;
		}
	}
	else
	{
		int i,j;
		for(i=0;i<4;i++)
		{
			if(num==0)
			before=-1;
		//	cout<<i<<endl;
			if(!cc[i]&&i>before)
			{
			//	cout<<"Yes"<<endl;
				if(i==0)
				{
					for(j=1;j<=tot_lamp;j++)
					{
						lamp[j]=!lamp[j];
					}
				}
				if(i==1)
				{
					for(j=1;j<=tot_lamp;j++)
					{
						if(j%2)
						lamp[j]=!lamp[j];
					}
				}
				if(i==2)
				for(j=1;j<=tot_lamp;j++)
				{
					if(!(j%2))
					lamp[j]=!lamp[j];
				}
				if(i==3)
				for(j=1;j<=tot_lamp;j++)
				{
					if(!((j-1)%3))
					lamp[j]=!lamp[j];
			 }
			
				cc[i]=true;
				before=i;
				temp=before;				
			//	cout<<"i="<<i<<endl;
				dfs(num+1);
				cc[i]=false;
				before=temp;
				if(i==0)
				{
					for(j=1;j<=tot_lamp;j++)
					{
						lamp[j]=!lamp[j];
					}
				}
				if(i==1)
				{
					for(j=1;j<=tot_lamp;j++)
					{
						if(j%2)
						lamp[j]=!lamp[j];
					}
				}
				if(i==2)
				for(j=1;j<=tot_lamp;j++)
				{
					if(!(j%2))
					lamp[j]=!lamp[j];
				}
				if(i==3)
				for(j=1;j<=tot_lamp;j++)
				{
					if(!((j-1)%3))
					lamp[j]=!lamp[j];
				}
			}
		}
		
	}
}
