#include<iostream>
#include<set>
using namespace std;
int main()
{
	set<int> s;
	set<int>::iterator is;
	int first;
	int temp;
	int count=0;
	while(cin>>first&&first!=-1)
	{
		count=0;
		s.clear();
		s.insert(first);
		while(cin>>temp&&temp!=0)
		{
			s.insert(temp);
		}
/*			for(is=s.begin();is!=s.end();is++)
		{
			cout<<(*is)<<endl;
		}*/
		for(is=s.begin();is!=s.end();is++)
		{
			if(s.find(2*(*is))!=s.end())
			{
				count++;
			}
		}
		cout<<count<<endl;
	}
	
}
