#include<iostream>
using namespace std;
int prime_table[10001];
bool is_prime(int num)
{
	int i=2;
	for(i=2;i*i<=num;i++)
	{
		if(num%i==0)
		return false;
	}
	return true;
}
int main()
{
	int num=0,begin,end,cnt=0;
	for(num=2;num<=10001;num++)
	{
		if(is_prime[num])
		{
		prime_table[cnt++]=num;
		}
	}
	cin>>begin>>end;
	for(int i=begin;i<=end;i++)
	{
		num=i;
		cout<<num<<"=";
		while(num!=1)
		{
			for(int j=0;j<cnt;j++)
			{
				if(num%prime_table[j]==0)
				{
					cout<<prime_table[j];
					num/=prime_table[j];
					break;
				}
				
			}
			if(num==1)
			{
			cout<<endl;
			break;
			}
			else
			cout<<"*";
		}

	}
	
}

