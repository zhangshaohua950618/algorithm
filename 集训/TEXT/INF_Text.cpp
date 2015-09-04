/*INF_Text*/
#include<iostream>
using namespace std;
int main()
{
	int a[10];
	a[3]=4;
	int i;
	for(i=0;i<10;i++)
	{
		if(a[i]!=INF)
		cout<<a[i]<<endl;
	}
}
