/*
ID: zhangsh35
PROG: cowcycle 
LANG: C++
*/
#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int f_num,r_num,f_min,f_max,r_min,r_max;
bool wheel_f[80+10];
bool wheel_r[40+10];
int record[80+10+40+10]; 
double wheel[80+10+40+10];
double dif[80+10+40+10];
double min_var=0x7fffffff;
void dfs_f(int num);
void dfs_r(int num);
bool cmp(double a,double b);
double var=0.0;
#define fabs(a) ((a)>0?(a):(-a))
#define LOCAL
int main()
{
	#ifdef LOCAL
	freopen("cowcycle.in","r",stdin);
//	freopen("cowcycle.out","w",stdout);
	#endif
	cin>>f_num>>r_num;
	cin>>f_min>>f_max>>r_min>>r_max;
//	
	dfs_f(0);
	cout<<123<<endl;
	int i;
	for(i=0;i<f_num-1;i++)
	cout<<record[i]<<" ";
	cout<<record[i]<<endl;
	for(   ;i<r_num-1;i++)
	cout<<record[i]<<" ";
	cout<<record[i]<<endl;
	return 0;
	
}
void dfs_f(int num_f)
{
	if(num_f==f_num)
	{
	//	cout<<"end dfs_f"<<endl;
		dfs_r(0);
	}
	else
	{
		int i;
		for(i=f_min;i<=f_max;i++)
		{
			if(!wheel_f[i])
			{
				wheel_f[i]=true;
				dfs_f(num_f+1);
				wheel_f[i]=false;
			}
		}
	}
}
void dfs_r(int num_r)
{
	if(num_r==r_num)
	{
	//	cout<<"end dfs_r"<<endl;
	int i,j,k=0;
/*	for(i=f_min;i<=f_max;i++)
	if(wheel_f[i])
	cout<<i<<" ";
	for(i=r_min;i<=r_max;i++)
	if(wheel_r[i])
	cout<<i<<" ";
	*/
	double average=0.0;
	for(i=f_min;i<=f_max;i++)
	{
		if(wheel_f[i])
		{
		//	cout<<i<<" ";
			for(j=r_min;j<=r_max;j++)
			{
				if(wheel_r[j])
				{
		//			cout<<j<<" ";
		//			cout<<(double)(i)/j<<" ";
				wheel[k++]=(double)(i)/j;//!!!Ç¿ÖÆ×°»»
				}
			}
		}
	}
	
	sort(wheel,wheel+k,cmp);
//	for(i=0;i<k;i++)
//	cout<<wheel[i]<<endl;
	
//	cout<<wheel[k-1]/wheel[0]<<endl;
	if((wheel[k-1]/wheel[0])>=3)
	{
	for(i=0;i<k-1;i++)
	{
		dif[i]=wheel[i+1]-wheel[i];
	//	cout<<dif[i]<<endl;
		average+=dif[i];
	}
//	;
//	cout<<"average= "<<average<<endl;
	average/=(k-1);
//	cout<<"average= "<<average<<endl;
	var=0.0;
	for(i=0;i<k-1;i++)
	{
//		cout<<(dif[i]-average)*(dif[i]-average)<<" ";
		var+=(dif[i]-average)*(dif[i]-average);
	}
	int cnt=0; 
//	cout<<average<<endl;
//	cout<<var/(k-1)<<endl;
	if(var/(k-1)<min_var)
	{
		for(i=f_min;i<=f_max;i++)
		if(wheel_f[i])
		record[cnt++]=i;
		for(i=r_min;i<=r_max;i++)
		if(wheel_r[i])
		record[cnt++]=i;
	}	
//	for(i=0;i<cnt;i++)
//	cout<<record[i]<<endl;
	}	
	}
	else
	{
		int i;
		for(i=r_min;i<=r_max;i++)
		{
			if(!wheel_r[i])
			{
				wheel_r[i]=true;
				dfs_r(num_r+1);
				wheel_r[i]=false;
			}
		}
	}
}
bool cmp(double a,double b)
{
	return a<b;
}
