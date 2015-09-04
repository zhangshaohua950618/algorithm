/*
ID: zhangsh35
PROG: transform 
LANG: C++
*/
#include<stdio.h>
#include<iostream>
using namespace std;
const int MAXN=100;
char org[MAXN][MAXN];//ԭ���ľ��� 
char transform[MAXN][MAXN];//�任��ľ��� 
bool judge(char a[][MAXN],char b[][MAXN]);
void revolve(char a[][MAXN]);
void reflex(char a[][MAXN]);
int rows;
#define LOCAL
int main()
{
	#ifdef LOCAL//����ע�͵� 
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
	revolve(org);//ת��ԭ���� 
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
bool judge(char a[][MAXN],char b[][MAXN])//�ж��Ƿ���ͬ 
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
void revolve(char a[][MAXN])//˳ʱ��90�� 
{
	int i,j;
	char temp;
	for(i=0;i<rows/2;i++)//�����¶Ե� 
	{
		for(j=0;j<rows;j++)
		{
			temp=a[i][j];
			a[i][j]=a[rows-i-1][j];
			a[rows-i-1][j]=temp;
		}
	} 
	for(i=0;i<rows;i++)//�������Խ��߶Ե� 
	{
		for(j=0;j<i;j++)
		{
			temp=a[i][j];
			a[i][j]=a[j][i];
			a[j][i]=temp;
		}
	}
}
void reflex(char a[][MAXN])//���亯�� 
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
