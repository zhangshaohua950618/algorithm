#include<iostream>
#include<string.h>
#include<string>
using namespace std;
string strupr(string str);
int main()
{
	string str1,str2;
	while(cin>>str1>>str2)
	{
		if(str1.length()!=str2.length())
		{
			cout<<"1"<<endl;
			continue;
		}
		if(str1==str2)
		{
			cout<<"2"<<endl;
			continue;
		}
		if(strupr(str1)==strupr(str2))
		{
			cout<<"3"<<endl;
			continue;
		}
		cout<<"4"<<endl;
		
	}
}
string strupr(string str)
{
	string temp=str;
	for(int i=0;i<str.length();i++)
	{
		if(temp[i]>='a'&&temp[i]<='z')
		temp[i]=str[i]-'a'+'A';
	} 
	return temp;
} 
