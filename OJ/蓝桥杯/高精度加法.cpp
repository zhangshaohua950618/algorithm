#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	string str1;
	string str2;
	int index,temp;
	int st1[100+10];
	int st2[100+10];
	int res[100+10];
	while(cin>>str1>>str2)
	{
		memset(st1,0,sizeof(st1));
		memset(st2,0,sizeof(st2));
		memset(res,0,sizeof(res));
		index=0;
		int i,j;
		int len1=str1.length();
		int len2=str2.length();
		for(i=len1-1;i>=0;i--)
		st1[len1-1-i]=str1[i]-'0';
		for(i=len2-1;i>=0;i--)
		st2[len2-1-i]=str2[i]-'0';
		for(i=0;i<=(len1>len2?len1:len2);i++)
		{
			temp=st1[i]+st2[i]+index;
			res[i]=temp%10;
			index=temp/10;
		}
		int pos=0;
		for(i=(len1>len2?len1:len2);i>=0;i--)
		{
			if(res[i])
			{
				pos=i;
				break;
			}
		}
	//	cout<<pos<<endl;
		for(i=pos;i>=0;i--)
		cout<<res[i];
		cout<<endl;
		
	}
	
	
}
