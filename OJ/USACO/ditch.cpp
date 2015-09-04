/*
ID: zhangsh35
PROG: ditch 
LANG: C++
*/
#include<fstream>
#include<vector>
#include<string.h>
#define MIN( a , b ) ((a) < (b) ? (a) : (b))
using namespace std ;
ifstream cin("ditch.in") ;
ofstream cout("ditch.out") ;
const int MAXN = 200 + 20 ;
const int INF = ( 1 << 30 ) ;
struct Edge{
	int to ;
	int cap ;
	int rev ;
} ;
bool used[MAXN] ;
vector<Edge> G[MAXN] ; 
int degree[MAXN] , totEdge , sink ;
void AddEdge( int from , int to , int cap ){ 
	G[from].push_back( (Edge){to , cap , G[to].size()}) ;
	G[to].push_back( (Edge){from , 0 , G[from].size() -  1 }) ;
}
int DFS( int v , int f ){
	if( v == sink )
	return f ;
	used[v] = true ;
	for( int i = 0 ; i < G[v].size() ; i++ ){
		Edge &e = G[v][i] ;
		if( !used[e.to] && e.cap > 0 ){
			int dif = DFS( e.to , MIN( f , e.cap)) ;
			if( dif > 0 ){
				e.cap -= dif ;
				G[e.to][e.rev].cap += dif ;
				return dif ;
			}
		}
	}
	return 0  ;
}
int MaxFlow( int s ){
	int flow = 0 ;
	while( true ){
		memset(used , 0 , sizeof(used)) ;
		int f = DFS( s , INF ) ;
		if( f == 0 ) return flow ;
		flow += f ;
	}
}
int main(){
	int from , to , cap ;
	cin >> totEdge >> sink ;
	for( int i = 0 ;i < totEdge ; i++ ){
		cin >>  from >> to >> cap ;
		AddEdge( from , to , cap ) ;
	}
	cout << MaxFlow(1) << endl  ;
	
}
