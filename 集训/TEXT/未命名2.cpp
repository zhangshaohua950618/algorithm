#include<iostream>
#include<set>
using namespace std ;
int main(){
	set<int> s ;
	s.insert(1) ;
	s.insert(2) ;
	s.insert(3) ;
	set<int>::iterator it = s.begin() ;
	cout<<(*(it+1))<<endl;
}
