#include<fstream>
#include<cstdlib>
using namespace std ;
ifstream cin("1.in") ;
ofstream cout("1.out") ;
const int MAXN = 100 + 10 ;
const int INF = (1 << 10) ;
int path[MAXN][MAXN] ;
int  m , n ;
void Initial(){
	int i , j ;
	cin >> n  >> m ;
	for(i = 1 ; i <= n ; i++)
		for(j = 1 ; j <= n ; j++)
		path[i][j] = i == j ? 0 : INF ;
}
void Input(){
	int i , u , v , l ;
	for(i = 1 ; i <= m ; i++){
		cin >> u >> v >> l ;
		path[u][v] = path[v][u] = l ;		
	}
}
void Floyd(){
	int i , j , k ;
	for(k = 1 ; k <= n ; k++)
		for(i = 1; i <= n ; i++)
			for(j = 1 ; j <= n ; j++)		
				path[i][j] = min(path[i][j] , path[i][k] + path[k][j]) ;
}
void Output(){
	int  i , j ;
	for(i = 1 ; i <= n ; i++){
		for(j = 1 ; j < n ; j++)
		cout << path[i][j] << " " ;
		cout << path[i][j] << endl ;
	}
}
int main(){
		Initial() ;
		Input() ;
		Floyd() ;
		Output() ;
		return 0 ;	
} 

