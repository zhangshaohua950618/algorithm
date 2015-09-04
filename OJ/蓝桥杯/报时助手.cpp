#include<iostream>
#include<map>
#include<string.h>
using namespace std;
void translate(int num)
{
	map<int,string> m;
	m[1]="one";
	m[2]="two";
	m[3]="three";
	m[4]="four";
	m[5]="five";
	m[6]="six";
	m[7]="seven";
	m[8]="eight";
	m[9]="nine";
	m[10]="ten";
	m[11]="eleven";
	m[12]="twelve";
	m[13]="thirteen";
	m[14]="fourteen";
	m[15]="fifteen";
	m[16]="sixteen";
	m[17]="seventeen";
	m[18]="eighteen";
	m[19]="nineteen";
	m[20]="twenty";
	m[30]="thirty";
	m[40]="forty";
	m[50]="fifty";
	if(m.find(num)!=m.end())
	cout<<m[num];
	else
	cout<<m[num-num%10]<<" "<<m[num%10];
}
int main()
{
	int hour,min;
	while(cin>>hour>>min)
	{
		if(!hour)
		cout<<"zero";
		else
		translate(hour);
		cout<<" ";
		if(!min)
		cout<<"o'clock";
		else
		translate(min);
		cout<<endl;
	}
}
