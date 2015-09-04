/*
ID: zhangsh35
PROG: ratios 
LANG: C++
*/
#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int pro[4][3];
int num[3];
#define LOCAL
int main()
{
	#ifdef LOCAL
	freopen("ratios.in","r",stdin);
	freopen("ratios.out","w",stdout);
	#endif
	int i,j,k,tot;
	for(i=0;i<4;i++)
	for(j=0;j<3;j++)
	{
		cin>>pro[i][j];
	}
	for(int tot=1;tot<300;tot++)
	for(i=0;i<=tot;i++)
	for(j=0;j<=tot-i;j++)
	{
		memset(num,0,sizeof(num));
		bool ok=true;
		for(k=0;k<3;k++)
		{
	//	cout<<pro[0][k]<<endl;
		if(!pro[0][k])
		{
		//	cout<<i*pro[1][k]+j*pro[2][k]+(tot-i-j)*pro[3][k]<<endl;
			if(i*pro[1][k]+j*pro[2][k]+(tot-i-j)*pro[3][k])
			{
				ok=false;
				break;
			}
			else
			num[k]=-1;
			
		}
		else
		{
		//	cout<<((i*pro[1][k]+j*pro[2][k]+(tot-i-j)*pro[3][k])%pro[0][k])<<endl;
			if(((i*pro[1][k]+j*pro[2][k]+(tot-i-j)*pro[3][k])%pro[0][k]))
			{
			ok=false;
			break;
			}
			num[k]=(i*pro[1][k]+j*pro[2][k]+(tot-i-j)*pro[3][k])/pro[0][k];			
			}
		}
		if(ok)
		{
		
			bool yes=true;;
			int l;
			for(l=0;l<3;l++)
			{
				if(num[l]==-1||num[(l+1)%3]==-1)
				continue;
				if(num[l]!=num[(l+1)%3])
				yes=false;
			}
	
			if(yes)
			{
		//		cout<<num[0]<<endl;
		//		cout<<num[2]<<endl;
			cout<<i<<" "<<j<<" "<<tot-i-j<<" "<<num[0]<<endl;
			return 0;
			}
		}
	}
	
	
		
	
	cout<<"NONE"<<endl;
	return 0;
	
}
