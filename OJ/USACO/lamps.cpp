/*
ID: zhangsh35
PROG: lamps 
LANG: C++
*/
#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
using namespace std;
int operate(int num,int lamp);
bool judge(int num);
bool state[5][65];
bool lamp_on[7];
bool lamp_off[7];
int judge_on=0;
int judge_off=0;
int lamps[6];
#define LOCAL
int main()
{
	#ifdef LOCAL
	freopen("lamps.in","r",stdin);
	freopen("lamps.out","w",stdout);
	#endif
	int temp,count,tot,sum=0;
	int i,j,on,off;
	state[0][63]=true;
	cin>>tot>>count;
	if(count%2)//计算循环上限 
	count=4<count?4:count;
	else
	count=3<count?3:count;
	while(cin>>on&&on!=-1)
	{
		on%=6;
		if(on==0)
		on=6;
		if(!lamp_on[on])
		{
		judge_on+=pow(2,6-on);
		lamp_on[on]=true;
		
		}
	}
//	cout<<"judge_on="<<judge_on<<endl;
	while(cin>>off&&off!=-1)
	{
		off%=6;
		if(off==0)
		off=6;
		if(!lamp_off[off])
		{
		judge_off+=pow(2,6-off);
		lamp_off[off]=true;
		}
	}
//	cout<<"judge_off="<<judge_off<<endl;
	for(i=1;i<=count+1;i++)
	{
		for(j=0;j<=63;j++)
		if(state[i-1][j])
		{
	//		cout<<j<<endl;
			state[i][operate(1,j)]=true;
			state[i][operate(2,j)]=true;
			state[i][operate(3,j)]=true;
			state[i][operate(4,j)]=true;
		}
	}
	for(i=0;i<=63;i++)
	{
		
		if(state[count][i]&&judge(i))
		{
	//		cout<<"i="<<i<<endl;
			int k=5,temp=i;
			sum++;
			memset(lamps,0,sizeof(lamps));
			while(temp)
			{
			lamps[k--]=temp%2;
			temp/=2;
			}
	/*		for(j=0;j<6;j++)
			cout<<lamps[j];*/
			k=0;
			for(j=0;j<tot;j++)
			{
				if(k==6)
				k=0;
				cout<<lamps[k++];
				
			}
			cout<<endl;
		}
		
	}
	if(!sum)
	cout<<"IMPOSSIBLE"<<endl;
	
	return 0;
	 
} 
int operate(int num,int lamp)//操作 
{
//	cout<<"num= "<<num<<endl;
	int k;
	if(num==1);
	k=lamp xor 63;
	if(num==2)
	k=lamp xor 42;
	if(num==3)
	k=lamp xor 21;
	if(num==4)
	k=lamp xor 36;
	return k;
}
bool judge(int num)
{
	int k=num&judge_on;
	int l=num&judge_off;
	if(k==judge_on&&l==0)
	return true;
	return false;
}
