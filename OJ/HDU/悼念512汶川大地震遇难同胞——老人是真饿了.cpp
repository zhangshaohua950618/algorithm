#include<iostream>
#include<queue>
#include<stdio.h>
using namespace std ;
const int MAXN = 100 + 10 ;
struct P{
	int v ;
	int s ;
	friend bool operator < ( P a ,P b ){
		return a.s > b.s ; 
	}
} ;
P p , t ;
int m , n , s;
double k ;
priority_queue<P> q ;
int main(){
	int i , j , l  ;
	cin >> l;
	while( l-- ){ 
		cin >> m >> n ;
		k = 0.0 , s = 0 ;
		while(!q.empty())
		q.pop() ;
		for( i = 0 ; i < n ; i++ ){
			cin >> p.s >> p.v ;
			q.push(p);
		}
		while(!q.empty()){
			t = q.top() ;
			q.pop() ;
			if( s + t.s * t.v <= m ){
				k += t.v ;
				s += t.s * t.v;
			}
			else{
				k += (double)(m - s) / t.s ;
				break ;
			}
		}
		printf( "%.2lf\n" , k ) ;
	}
	return 0 ;
}
