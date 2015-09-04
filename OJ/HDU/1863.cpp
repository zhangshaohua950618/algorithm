#include<iostream>
#include<queue>
#include<string.h>
#include<string>
using namespace std ;
const int MAXN = 100 + 10 ;
const int INF = 99999 ;
int path[MAXN][MAXN] , low[MAXN] , n , m  ,s , t , w ;
bool vis[MAXN];
bool prim( int s ){
	int i , j, k , min ,pos = s , res= 0  ; 
	memset(low , 0 ,sizeof(low)) ;
	memset(vis , false , sizeof(vis)) ;
	for( i = 1 ; i <= m ; i++ )
		low[i] = path[s][i] ;
	for( k = 1 ; k <= m ; k++ ){
		min = INF ;
		for( i = 1 ; i <= m ; i++ ){
			if(!vis[i] && low[i] < min ){
				pos = i ;
				min = low[i] ;
			}
		}
		if(min == INF )
		break ;
		vis[pos] = true ;
		res += min ;
		for( i = 1 ; i <= m ; i++ )
		if(!vis[i] && path[pos][i] < low[i] )
		low[i] = path[pos][i] ;
	}
	if( k == m + 1){
		cout << res << endl ;
		return true ;
	}else
	return false ;
} 
int main(){
	int i , j ; 
	while( cin >> n >> m && n * m ){
		for( i = 1 ; i <= m ; i++ )
		for( j = 1 ; j <= m ; j++ )
		path[i][j] = path[j][i] = i == j ? 0 : INF ;
		for( i = 0 ; i < n ; i++){
			cin >> s >> t>> w  ;
			path[s][t] = path[t][s] = w ;
		}
		if(!prim(1))
		cout << "?" << endl ;
	}
	return 0 ;
}
