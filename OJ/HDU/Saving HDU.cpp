#include<iostream>
#include<queue>
using namespace std ;
const int MAXN = 100 + 10 ;
struct P{
	int v ;
	int s ;
	friend bool operator < ( P a ,P b ){
		return a.s < b.s ; 
	}
} ;
P p , t ;
int m , n , s , k;
priority_queue<P> q ;
int main(){
	int i , j  ;
	while( cin >> m && m != 0 ){
		cin >> n ;
		k = 0 , s = 0 ;
		while(!q.empty())
		q.pop() ;
		for( i = 0 ; i < n ; i++ ){
			cin >> p.s >> p.v ;
			q.push(p);
		}
		while(!q.empty()){
			t = q.top() ;
			q.pop() ;
			if( k + t.v <= m ){
				k += t.v ;
				s += t.s * t.v;
			}
			else{
				s += (m - k) * t.s ;
				break ;
			}
		}
		cout << s << endl ;
	}
	return 0 ;
}
