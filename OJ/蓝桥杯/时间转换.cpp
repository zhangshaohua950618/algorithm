#include<iostream>
using namespace std;
int main()
{
	int time;
	while(cin>>time)
	{
		cout<<time/3600<<":";
		time%=3600;
		cout<<time/60<<":";
		time%=60;
		cout<<time<<endl;
	}
}
