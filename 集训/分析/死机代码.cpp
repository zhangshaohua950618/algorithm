#include<iostream>
#include<stack>
#include<map>
using namespace std ;
int radix = 10, number ;
stack<int> s , q ; 
map< int , char > m ; 
bool Judge( int num ){
	int digit ;
	while(!s.empty())
	s.pop() ;
	while(num){
		digit = num % radix ;
		num /= radix ;
		if(s.empty() || digit != s.top())
		s.push(digit) ;
		else
		s.pop() ;
	}
	return s.empty() ? true : false ;
}
char symble = 'A';
int main(){
	int i ;
	for( i = 10 ; i <= 15 ; i++ )
	m[i] = symble++ ;
	for( i = 1 ; i <= 300 ; i++ ){
		number = i * i ;
		if( Judge( number )){
			cout << number << endl ;
		while(number)
			q.push( number % radix ) ;
			number /= radix ;	
		while(!q.empty()){
			if(q.top() >= 10)
			cout<<m[q.top()];
			else
			cout<<q.top() ;
			q.pop() ;
		}
	}
		cout << endl ;
	}
	
}
