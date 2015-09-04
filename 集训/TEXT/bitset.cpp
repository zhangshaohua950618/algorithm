/*
ID: zhangsh35
PROG: kimbits 
LANG: C++
*/
#include<stdio.h>
#include<iostream>
#include<bitset>
#include<math.h>
#include<string.h>
using namespace std;
#define LOCAL
int main()
{
	#ifdef LOCAL
	freopen("kimbits.in","r",stdin);
	freopen("kimbits.out","w",stdout);
	#endif
	int nuits,num,tot,cnt=0;
	cin>>nuits>>num>>tot;
	int i;
	for(i=0;i<=pow(2,nuits)-1;i++)
	{
		bitset<32> bit(i);
	//	cout<<bit.count()<<endl;
		if(bit.count()<=num)
		cnt++;
		if(cnt==tot)
		{
		cout<<bit.to_string().substr(32-nuits,nuits)<<endl;
		return 0;
		}
	}
	
}
