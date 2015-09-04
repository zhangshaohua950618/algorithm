#include<iostream>
#include<queue>
using namespace std ;
const int MAXN = 100 + 10 ;
const int INF = ( 1 << 30 ) ;
int path[MAXN][MAXN] , low[MAXN] , start , end  , rows , totQuestion , question ;
bool inQue[MAXN] ;
queue<int> q ;
void Spfa( int s ){
	while( !q.empty() )
	q.pop() ;
	for( int i = 1 ; i <= rows ; i++ ){
		low[i] = INF ;
		inQue[i] = false ;
	}
	low[s] = 0 ;
	q.push(s) ;
	inQue[s] = true ;
	while( !q.empty() ){
		int current = q.front() ;
		q.pop() ;
		inQue[current] = false ;
		for( int i = 1 ; i <= rows ; i++ ){
			if( low[current] + path[current][i] < low[i] ){
				low[i] = low[current] + path[current][i] ;
				if(!inQue[i]){
					q.push(i) ;
					inQue[i] = true ;
				}
			}	
		}
	}
}
int main(){
	std::ios::sync_with_stdio(false) ;
	cin >> rows ;
	for( int i = 1 ; i <= rows ; i++ )
	for( int j = 1 ; j <= rows ; j++ )
	cin >> path[i][j] ;
	cin >> totQuestion ;
	for( int i = 0 ; i < totQuestion ; i++ ){
		cin >> start >> end  ;
		Spfa( start ) ;
		cout << low[end] << endl ;
	}
	return 0 ;
}
