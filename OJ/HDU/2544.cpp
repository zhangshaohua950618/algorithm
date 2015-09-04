#include<iostream>
#include<queue>
#define MIN(a,b) ((a) < (b) ? (a) : (b))
using namespace std ;
const int MAXN = 100 + 10 ;
const int INF = 999999 ;
int m , n  , s , t , w , path[MAXN][MAXN];
int dis[MAXN] ;
queue<int> q ;
void Floyd(){
	int i ,j , k ;
	for( k = 1 ; k <= n ; k++ )
	for( i = 1 ; i <= n ; i++ )
	for( j = 1 ; j <= n ; j++ )
	path[i][j]  = MIN( path[i][j] , path[i][k] + path[k][j]) ;
}
int main(){
	int i , j ;
	while( cin >> n >>  m  && m * n ){
		for( i = 1 ; i <= n ; i++ )
		for( j = 1 ; j <= n ; j++ )
		path[i][j] = i == j ? 0 : INF ;
		for( i = 0 ; i < m ; i++ ){
			cin >> s >> t >> w  ;
			path[s][t] = path[t][s]= w ;
		}
		Floyd() ;
		cout << path[1][n] << endl ;
	}
	return 0 ;
	
}
