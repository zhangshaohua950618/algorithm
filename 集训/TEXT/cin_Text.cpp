#include<iostream>
#include<stdio.h>
#include<time.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	int i=0,begin,end;
	begin=clock();
	int a=123;
	for(i=0;i<100000;i++)
	{
		cout<<a<<endl;
	//	printf("%d\n",a);
	}
	end=clock();
	cout<<"一共用时"<<(end-begin)/CLOCKS_PER_SEC<<"s"<<endl;
	return 0;
}
