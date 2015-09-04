#include<iostream>
#include<stack>
#include<string>
#include<string.h>
using namespace std ;
const string map = "0123456789ABCDEF" ;
stack<int> s ;
int n , m ;
int main(){
	cin >> n >> m ;
	while(n){
		s.push(n % m) ;
		n /= m ;
	}
	while(!s.empty()){
	cout << map[s.top()] ;
	s.pop() ;
	}
	cout << endl ;
	return 0 ;
}
