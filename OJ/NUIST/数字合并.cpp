#include<iostream>
#include<queue>
#include<string.h>
using namespace std ;
int n ;
string str ;
struct Str{
	string str ;
	friend bool operator < ( Str a , Str b ){
		return a.str < b.str ;
	}
} ;
priority_queue<Str> q ;
using namespace std ;
int  main(){
	while( cin >> n ){
		while( !q.empty() )
		q.pop() ;
		while( n-- ){
			cin >> str ;
			q.push((Str){str}) ;
		}
		while( !q.empty() ){
			cout << q.top().str ;
			q.pop() ;
		}
		cout << endl ;
	}
	
}
