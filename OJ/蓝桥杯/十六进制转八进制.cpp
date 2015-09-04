#include<iostream>
#include<map>
#include<string.h>
#include<stack>
#include<queue>
using namespace std ;
//ifstream cin("1.in") ;
//ofstream cout("1.out") ;
const int MAXN = 10 + 10 ;
int totText ;
string text[MAXN] ;
map< char , int > m ;
queue<int> q ;
stack<int> s ;
void Initial(){
	int i ;
	for( i = 0 ; i < 10 ; i++ )//Initial
	m[ i + '0' ] = i ;
	m['A'] = 10 ;
	m['B'] = 11 ;
	m['C'] = 12 ;
	m['D'] = 13 ;
	m['E'] = 14 ;
	m['F'] = 15 ;
}
void Push( int num ){
	for( int value = 1 ; value <= 8 ; value *= 2 ){
		if(num & value )
		q.push(1) ;
		else
		q.push(0) ;
	}
}
void OutPut(){
	bool ok = false ;
	while(!s.empty()){
		if( s.top() )
		ok = true ;
		if(ok)
		cout << s.top () ;
		s.pop() ;
	}
	cout << endl ;
	
}
int Translate( string text ){
	int i ;
	int data , value ;
	while(!s.empty())//Initial
	s.pop() ;
	while(!q.empty())
	q.pop() ; 
	for( i = text.length() - 1 ; i >= 0 ; i-- ){
	Push(m[text[i]]) ;
	while(q.size() >= 3){
		data = 0 ;
		for( value = 1 ; value <= 4 ; value *= 2 ){
			if(q.front() == 1)
				data += value ;
				q.pop() ;
		}
			s.push(data) ;
		}
	}
	data = 0 ;
	value = 1 ;
	while( !q.empty() ){
		if( q.front() == 1 )
		data += value  ;
		value *= 2 ;
		q.pop() ;
	}
	s.push(data) ;
}
int main(){
	Initial() ;
	cin >> totText ;
	for( int i = 0 ; i < totText ; i++ ){
		cin >> text[i] ;
		Translate(text[i]) ;
		OutPut() ;
	}
	return 0 ;
}
