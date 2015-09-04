/*
ID: zhangsh35
PROG: humble 
LANG: C++
*/
#include<stdio.h>
#include<iostream> 
#include<set>
using namespace std;
int prime[100+10]; 
#define LOCAL
int main()
{
	#ifdef LOCAL
	freopen("humble.in","r",stdin);
	freopen("humble.out","w",stdout);
	#endif
	int tot,num;
	cin>>tot>>num;
	for(int i=0;i<tot;i++)
	cin>>prime[i];
	set<int> s;
	s.insert(1);
	int cnt=0;
	for(int i=2;cnt!=num;i++)
	{
		for(int j=0;j<tot;j++)
		{
			if(!(i%prime[j])&&(s.find(i/prime[j])!=s.end()))
			{
				cnt++;	
				if(cnt==num)
				{
					cout<<i<<endl;
					return 0;
				}
				s.insert(i);
				break; 
			} 
		}
	}
}
