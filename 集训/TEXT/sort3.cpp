/*
ID: zhangsh35
PROG: sort3 
LANG: C++
*/
#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN=1000+10;
int original[MAXN] ;
int sorted[MAXN];
bool is_changed[MAXN];
#define LOCAL
int main()
{
	#ifdef LOCAL
	freopen("sort3.in","r",stdin);
	freopen("sort3.out","w",stdout);
	#endif
	int tot;
	int i=0,j;
	cin>>tot;
	for(i=0;i<tot;i++)
	{
		cin>>original[i];
		sorted[i]=original[i];
	}
	sort(sorted,sorted+tot);
//	for(i=0;i<tot;i++)
//	cout<<sorted[i]<<" ";
	int cnt=0;
	for(i=0;i<tot;i++)
	{
		if(!is_changed[i])
		{
			if(original[i]==sorted[i])//不需要交换 
			{
				is_changed[i]=true;
				continue;
			}
			else
			{
				for(j=i+1;j<tot;j++)
				{
					if(!is_changed[j])
					{
						if(original[i]==sorted[j]&&original[j]==sorted[i])
						{
							is_changed[i]=true;
							is_changed[j]=true;
						//	cout<<"第"<<i<<"列和第"<<j<<"列交换"<<endl; 
							cnt++;//交换 
							break; 
						}
					}
				}
			}
			
		}
	}
	j=0;
	for(i=0;i<tot;i++)
	{
		if(!is_changed[i])
		j++;
	}
//	cout<<j<<endl;
//	if(!(j%3))
	cnt+=2*j/3;
	cout<<cnt<<endl;
	
}
