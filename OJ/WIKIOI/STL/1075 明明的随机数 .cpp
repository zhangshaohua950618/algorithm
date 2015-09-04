#include<iostream>
#include<set>
using namespace std;
int main(){
	int num , temp ; 
	set<int> s ;
	set<int>::iterator it ;
	int i ;
	pair<set<int>::iterator , bool> p ;
	cin>>num ;
	int count = 0;
	for(i = 0 ; i < num ; i++){
		cin>>temp;
		p = s.insert(temp);
		if(p.second)
		count++;
	}
	cout<<count<<endl;
	it = s.begin() ;
	cout<<(*it);
	it++;
	for(    ; it != s.end() ; it++)
	cout<<" "<<(*it);
	cout<<endl;
}
