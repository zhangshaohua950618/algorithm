/*
ID: zhangsh35
PROG: transform 
LANG: C++
*/
#include<stdio.h>
#include<iostream>
using namespace std;
const int MAXN=100;
char org[MAXN][MAXN];//原来的矩阵 
char transform[MAXN][MAXN];//变换后的矩阵 
bool judge(char a[][MAXN],char b[][MAXN]);
void revolve(char a[][MAXN]);
void reflex(char a[][MAXN]);
int rows;
#define LOCAL
int main()
{
	#ifdef LOCAL//可以注释掉 
	freopen("transform.in","r",stdin);
	freopen("transform.out","w",stdout);
	#endif
	cin>>rows;
	int i,j;
	for(i=0;i<rows;i++)
	for(j=0;j<rows;j++)
	{
		cin>>org[i][j];
	}
	for(i=0;i<rows;i++)
	for(j=0;j<rows;j++)
	{
		cin>>transform[i][j];
	}
	revolve(org);
	if(judge(org,transform))
	{
	cout<<"1"<<endl;
	return 0;
	}
	revolve(org);
	if(judge(org,transform))
	{
	cout<<"2"<<endl;
	return 0;
	}
	revolve(org);
	if(judge(org,transform))
	{
	cout<<"3"<<endl;
	return 0;
	}
	revolve(org);//转回原来的 
	reflex(org);
	if(judge(org,transform))
	{
	cout<<"4"<<endl;
	return 0;
	}
	revolve(org);
	if(judge(org,transform))
	{
	cout<<"5"<<endl;
	return 0;
	}
	revolve(org);
	if(judge(org,transform))
	{
	cout<<"5"<<endl;
	return 0;
	}
	revolve(org);
	if(judge(org,transform))
	{
	cout<<"5"<<endl;
	return 0;
	}
	revolve(org);
	reflex(org);
	if(judge(org,transform))
	{
	cout<<"6"<<endl;
	return 0;
	}
	cout<<"7"<<endl;
	return 0;
	
/*	for(i=0;i<rows;i++)
	{
		for(j=0;j<rows;j++)
		{
			cout<<org[i][j]<<" ";
		}
		cout<<endl;
	}*/
	
}
bool judge(char a[][MAXN],char b[][MAXN])//判断是否相同 
{
	int i,j;
	for(i=0;i<rows;i++)
	{
		for(j=0;j<rows;j++)
		{
			if(a[i][j]!=b[i][j])
			return false;
		}
	}
	return true;
}
void revolve(char a[][MAXN])//顺时针90度 
{
	int i,j;
	char temp;
	for(i=0;i<rows/2;i++)//先上下对调 
	{
		for(j=0;j<rows;j++)
		{
			temp=a[i][j];
			a[i][j]=a[rows-i-1][j];
			a[rows-i-1][j]=temp;
		}
	} 
	for(i=0;i<rows;i++)//再沿主对角线对调 
	{
		for(j=0;j<i;j++)
		{
			temp=a[i][j];
			a[i][j]=a[j][i];
			a[j][i]=temp;
		}
	}
}
void reflex(char a[][MAXN])//反射函数 
{
	int i,j;
	char temp;
	for(i=0;i<rows;i++)
	{
		for(j=0;j<rows/2;j++)
		{
			temp=a[i][j];
			a[i][j]=a[i][rows-1-j];
			a[i][rows-1-j]=temp;
		}
	}
} 
