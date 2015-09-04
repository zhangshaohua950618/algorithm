#include<iostream>
#include<string.h>
#include<string>
#include<stack>
using namespace std ;
int n , var['t' + 1] ;
bool ok ;
string str ;
stack<int> s ; 
bool isOperator(char s){
	if(s == 'K' || s == 'A' || s == 'N' || s == 'C' || s == 'E')
	return true ;
	return false ;
}
int calculate(char o){
	int a , b ;
	a = s.top() ; 
	s.pop() ;
	if(o != 'N'){
	b = s.top() ;
	s.pop() ;
	}
	switch(o){
		case 'K': return a && b ;
		case 'A': return a || b ;
		case 'N': return !a ;
		case 'C': return !a|| b ; 
		case 'E': return a == b ;
	}
}
int main(){
	int i , j , temp ;
	while(cin >> str && str	!= "0"){
		ok = true ;
	for(n = 0 ; n <= 31 ; n++){
		while(!s.empty())
		s.pop() ;
		memset(var , 0 , sizeof(var)) ; 
	 	i = 'p' ;
	 	temp = n ;
	 	while(temp){
	 		var[i++] = temp & 1 ;
	 		temp >>= 1 ;
	 	}
		for(i = str.length() - 1 ; i >= 0 ; i--){
			if(isOperator(str[i]))
				s.push(calculate(str[i])) ;
			else
				s.push(var[str[i]]) ;
		}
		if(!s.top()){
			ok = false ;
			break ; 
		}
	}
	if(ok)
	cout << "tautology" << endl ;
	else
	cout << "not" << endl ;
	}
	return 0 ;
}
