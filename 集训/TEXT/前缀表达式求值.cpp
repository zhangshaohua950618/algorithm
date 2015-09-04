#include<iostream>
#include<stack>
#include<string.h>
using namespace std ;
string str ;
stack<int> s ;
int add(int a , int b){
	return a + b ;
}
bool isNum(char sub){
	if(sub >= '0' && sub <= '9')
	return true ;
	return false ; 
}
int main(){
	int i ;
	cin >> str ;
	cout << str ;
	for(i = str.length() - 1  ; i >= 0 ; i--){
		if(isNum(str[i]))		
		s.push(str[i] - '0') ;
		else{
			int a = s.top() ;
			s.pop() ;
			cout << a << endl ;
			int b = s.top() ;
			s.pop() ;
			cout << b << endl ; 
			s.push(add(a , b)) ;
		}
	}
	cout << s.top() << endl ;
	return 0 ;
}
