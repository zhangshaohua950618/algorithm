/*
ID: zhangsh35
PROG: pprime 
LANG: C++
*/
#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;
bool is_prime(long long num);
#define LOCAL
int main()
{
	#ifdef LOCAL
	freopen("pprime.in","r",stdin);
	freopen("pprime.out","w",stdout);
	#endif
	int d1,d2,d3,d4,d5;
	long long num;
	vector<long long> v;
	vector<long long>::iterator it;
	for(d1=1;d1<10;d1+=2)//1 
	{
		num=d1*1;
		if(is_prime(num))
		v.push_back(num);
	}
	for(d1=1;d1<10;d1+=2)//2 
	{
		num=d1*10+d1;
		if(is_prime(num))
		v.push_back(num);
	}
	for(d1=1;d1<10;d1+=2)//3 
	for(d2=0;d2<10;d2++)
	{
		num=d1*100+d2*10+d1;
		if(is_prime(num))
		v.push_back(num);
		
	}
	for(d1=1;d1<10;d1+=2)//4 
	for(d2=0;d2<10;d2++)
	{
		num=d1*1000+d2*100+d2*10+d1;
		if(is_prime(num))
		v.push_back(num);	
	}
	for(d1=1;d1<10;d1+=2)//5 
	for(d2=0;d2<10;d2++)
	for(d3=0;d3<10;d3++)
	{
		num=d1*10000+d2*1000+d3*100+d2*10+d1;
		if(is_prime(num))
		v.push_back(num);	
	}
	for(d1=1;d1<10;d1+=2)//6 
	for(d2=0;d2<10;d2++)
	for(d3=0;d3<10;d3++)
	{
		num=d1*100000+d2*10000+d3*1000+d3*100+d2*10+d1;
		if(is_prime(num))
		v.push_back(num);	
	}
	for(d1=1;d1<10;d1+=2)//7 
	for(d2=0;d2<10;d2++)
	for(d3=0;d3<10;d3++)
	for(d4=0;d4<10;d4++)
	{
		num=d1*1000000+d2*100000+d3*10000+d4*1000+d3*100+d2*10+d1;
		if(is_prime(num))
		v.push_back(num);	
	}
	for(d1=1;d1<10;d1+=2)//7 
	for(d2=0;d2<10;d2++)
	for(d3=0;d3<10;d3++)
	for(d4=0;d4<10;d4++)
	{
		num=d1*10000000+d2*1000000+d3*100000+d4*10000+d4*1000+d3*100+d2*10+d1;
		if(is_prime(num))
		v.push_back(num);	
	}
	long long min,max;
	cin>>min>>max;
	for(it=v.begin();(*it)<=max;it++)
	{
		if((*it)>=min&&(*it)<=max)
		{
			cout<<(*it)<<endl;
		}
	}
	return 0;
	
}
bool is_prime(long long num)
{
	int i;
	for(i=2;i*i<=num;i++)
	{
		if(num%i==0)
		return false;
	}
	return true;
}
