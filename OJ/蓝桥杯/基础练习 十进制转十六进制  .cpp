#include<iostream>
#include<stack>
#include<string.h>
using namespace std ;
int N ;
stack<int> s ;
int main(){
	string m = "0123456789ABCDEF" ;
	cin >> N ;
	if(!N){
		cout << N << endl ;
		return 0 ;
	}
	while(N){
		s.push(N % 16) ;
		N /= 16 ;
	}
	while(!s.empty()){
		cout << m[s.top()] ;
		s.pop() ;
	}
	cout << endl ;
	return 0 ;
}
