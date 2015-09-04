#include<iostream>
#include<stack>
#include<string.h>
using namespace std ;
stack<char> s ;
int t ;
string str ;
bool ok ;
int main(){
	cin >> t ;
	while(t--){
		while(!s.empty())
		s.pop() ;
		ok = true ;
		cin >> str ;
		for( int i = 0 ;i < str.length() ; i++ ){
			if(str[i] == '(' || str[i] == '{')
			s.push(str[i]) ;
			else if(str[i] == ')'){
				if(s.top() == '(')
				s.pop() ;
				else{
					ok = false ;
					break ;
				}
			}
			else if(str[i] == '}'){
				if(s.top() == '{')
				s.pop() ;
				else{
					ok = false ;
					break ;
				}
			}
		}
		if(s.empty())
		cout << "Yes" << endl ;
		else if( !s.empty() || !ok )
		cout << "No" << endl ;
	}
	
}
