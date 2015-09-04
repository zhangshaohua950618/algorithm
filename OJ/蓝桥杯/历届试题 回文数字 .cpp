#include<iostream>
using namespace std;
int main()
{
	int a,b,c;
	int num;
	while(cin>>num)
	{
		bool ok=false;
		for(a=1;a<=9;a++)
		for(b=0;b<=9;b++)
		for(c=0;c<=9;c++)
		{
		
		if((a+b+c+b+a)==num)
			{
				ok=true;
				cout<<a<<b<<c<<b<<a<<endl;
			}
		}
		for(a=1;a<=9;a++)
		for(b=0;b<=9;b++)
		for(c=0;c<=9;c++)
		{
		
			if((a+b+c+c+b+a)==num)
			{
					ok=true;
				cout<<a<<b<<c<<c<<b<<a<<endl;
			}
		
		}
	if(!ok)
	cout<<"-1"<<endl;
	}
}
