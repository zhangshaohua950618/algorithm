#include<iostream>
#include<queue>
#include<string.h>
using namespace std ;
const int MAXN = 100 + 10 ;
const int INF = 99999 ;
int  n , m , s , t , w , path[MAXN][MAXN] , dis[MAXN] ; 
queue<int> q ;
bool inque[MAXN] ;
void spfa(){
	int i , t ;
	while(!q.empty())
	q.pop() ;
	dis[1] = 0 ;
	for(i = 2 ; i <= n ; i++ )
	dis[i] = INF ;
	memset(inque , false , sizeof(inque)) ;
	q.push(1) ;
	while(!q.empty()){
		t= q.front() ;
		q.pop() ;
		inque[t] = false ; 
		for( i = 1 ; i <= n ; i++)
			if(dis[t] + path[t][i] < dis[i]){
				dis[i] = dis[t] + path[t][i] ;
				if(!inque[i]){
					q.push(i) ;
					inque[i] = true ; 
				}
			}
	}
}
int main(){
	int i , j ;
	while( cin >> n >>  m && n * m ){
		for( i = 1 ; i <= n ; i++ )
		for( j = 1 ; j <= n ; j++ )
		path[i][j] = i == j ? 0 : INF ;
		for( i = 0 ; i < m ; i++ ){
			cin >> s >> t >> w ;
			path[s][t] = path[t][s] = w ;
		}
		spfa() ;
		cout << dis[n] << endl ;
	}
}
