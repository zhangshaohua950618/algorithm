#include<iostream>
#include<string.h>
const int MAXN=100000+10;
char str[MAXN];
char sub[MAXN];
using namespace std;
int main()
{
	int str_length,sub_length;
	int i,j;
	while(cin>>sub>>str)
	{
		bool ok=false;
		str_length=strlen(str);
		sub_length=strlen(sub);
		for(i=0;i<str_length;i++)
		{
			int temp;
			temp=i;
			j=0;
			while(str[temp++]==sub[j++])
			{
				if(j==sub_length)
				{
				ok=true;	
				break;
				}
			}
		}	
		if(ok)
		cout<<"Yes"<<endl;
		else
		cout<<"No"<<endl;
	}
	return 0;
	
	
}
