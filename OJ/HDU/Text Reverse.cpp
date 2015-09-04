#include<iostream>
#include<string.h>
#include<string>
#include<stack>
using namespace std ;
const int  MAXN = 1000  + 10 ; 
int  n ;
char str[MAXN] ;
stack<char> s;
void print(){
	while(!s.empty()){
		cout << s.top() ;
		s.pop() ;
	}
}
int main(){
	int  i ;
	cin >> n ;
	getchar() ;
	while( n-- ){
		gets(str) ;
		for( i = 0 ; i < strlen(str) ;i++ ){
			if( str[i] != ' ')
				s.push(str[i]) ;
			else{
				print() ;
				cout << " " ;
			}
		}
		print() ;
		cout << endl ;
	}
	return 0 ;
	
}
