/*
ID: zhangsh35
PROG: frac1 
LANG: C++
*/
#include<stdio.h> 
#include<iostream>
#include<algorithm>
using namespace std;
bool is_coprime(int a,int b);
struct Fraction
{
	int mol;
	int den;
	double value; 
};
const int MAXN=10000;
int cmp(Fraction a,Fraction b)
{
	if(a.value<b.value)
	return 1;
	return 0;
}
#define LOCAL
int main()
{
	#ifdef LOCAL
	freopen("frac1.in","r",stdin);
	freopen("frac1.out","w",stdout);
	#endif
	int num;
	int i,j,k=0;
	Fraction fraction[MAXN];
	cin>>num;
	for(i=2;i<=num;i++)
	{
		for(j=1;j<i;j++)
		{
			if(is_coprime(i,j))
			{
				fraction[k].mol=j;
				fraction[k].den=i;
				fraction[k].value=(double)(j)/i;
				k++;
			}
		}
	}
	sort(fraction,fraction+k,cmp);
	cout<<"0/1"<<endl;
	for(i=0;i<k;i++)
	{
		cout<<fraction[i].mol<<"/"<<fraction[i].den<<endl;
	} 
	cout<<"1/1"<<endl;
	
}
bool is_coprime(int a,int b)
{
	int i;
	for(i=2;i<=(a<b?a:b);i++)
	{
		if(a%i==0&&b%i==0)
		return false;
	}
	return true;
} 
