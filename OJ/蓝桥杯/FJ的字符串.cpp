#include<iostream>
#include<string>
using namespace std;
int main()
{
	int times;
	string str="A";
	string res;
	while(cin>>times)
	{
		
		str="A";
		int i,j;
		for(i=1;i<times;i++)
		{
			res.clear(); 
		//	cout<<"time="<<i<<endl;
			for(j=0;j<str.length();j++)
			{
				if(str[j]!='A')
				{
					str[j]+=1;
					res+=str[j];
			//		cout<<"str[j]="<<str[j]<<endl;
		//			cout<<"res="<<res<<endl;
				}
				else
				res+="ABA";
			}
			str=res;
		
		}
		cout<<str<<endl;
	}
	
	
}
