#include<iostream>
using namespace std;
int main()
{
	int time;
	int v1,v2,dis,sleep,len,len1,len2,s;
	while(cin>>v1>>v2>>dis>>sleep>>len)
	{
		time=0;
		len1=0;
		len2=0;
		s=0;
		while(time<=(len/v2))
		{
			if(s)
				s--;
			else
			len1+=v1;
			len2+=v2;
			if(!s&&(len1-len2>=dis))
			s=sleep;
			time++;
		//	cout<<"len1= "<<len1<<endl;
		//	cout<<"len = "<<len<<endl;
			if(len1==len2&&len1==len)
			{
				cout<<"D"<<endl<<time<<endl;
				break;
			}
			if(len1==len)
			{
			cout<<"R"<<endl<<time<<endl;	
			break;
			}
			if(len2==len)
			{
				cout<<"T"<<endl<<time<<endl;
				break;
			}
			
		}
	}
}
