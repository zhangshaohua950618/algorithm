#include<iostream>
#include<string.h>
#include<stack>
#include<stdio.h>
using namespace std ;
string str ;
stack<string> s ;
int main(){
		while(cin >> str ){
			s.push(str) ;
			if(getchar() == '\n')
			break ;
		}
		while(!s.empty()){
			cout << s.top()  ;
			s.pop() ;
			if(s.empty())
			cout << endl ;
			else
			cout << " " ;
		}
		return 0 ;
}
