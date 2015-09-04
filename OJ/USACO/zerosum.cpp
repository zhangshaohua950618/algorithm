//ÌâÄ¿Á´½Óhttp://www.nocow.cn/index.php/Translate:USACO/zerosum 
/*
ID: zhangsh35
PROG:  zerosum 
LANG: C++
*/
#include<stdio.h> 
#include<iostream>
using namespace std;
const int MAXN=1000+10;
int num[MAXN];
int symbol[MAXN]={0,1}; 
int calculate();
void display();
void dfs(int cols);
int tot;
int i;
int value[]={0,1,-1};
#define LOCAL
int main()
{
	#ifdef LOCAL
	freopen("zerosum.in","r",stdin);
	freopen("zerosum.out","w",stdout);
	#endif
	cin>>tot;
	for(i=1;i<=tot;i++)
	{
		num[i]=i;
	}
	dfs(2);
/*	symbol[1]=1;
	symbol[2]=1;
	symbol[3]=1;
	symbol[4]=1;
	symbol[5]=1;
	symbol[6]=-1;
	symbol[7]=-1;
	display();
	cout<<"="<<calculate()<<endl;*/
	return 0;
} 
int calculate()
{
	int i;
	int sum=0;
	int index;
	int temp;
	for(i=tot;i>0;i--)
	{
		index=1;
		temp=0;
		while(true)
		{
			temp+=index*num[i];
			index*=10;
			if(symbol[i]!=0)
			break;
			i--;	
		}
	//	cout<<temp<<endl;
		sum+=symbol[i]*temp;
		
	}
	return sum;
}
void display()
{
	cout<<num[1];
	int i;
	for(i=2;i<=tot;i++)
	{
		if(symbol[i]==-1)
		cout<<"-";
		else if(symbol[i]==0)
		cout<<" ";
		else 
		cout<<"+";
		cout<<num[i];
	}
}
void dfs(int cols)
{
	if(cols==tot+1)
	{
		if((calculate()==0))
		{
	//	cout<<calculate()<<endl;
	int j=0;
/*		for(j=1;j<=tot;j++)
		cout<<symbol[j]<<" ";
		cout<<endl;*/
		display();
		cout<<endl;
		}
	}
	else
	{
		int i;
		for(i=0;i<3;i++)
		{
			symbol[cols]=value[i];
			dfs(cols+1);
		}
	}
}
