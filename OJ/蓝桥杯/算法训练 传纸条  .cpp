#include<iostream>
#include<string.h>
using namespace std ;	
int dis[101][101] ;
int f[105][52][52] ;
int rows , cols , step ;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
int Max( int a , int b , int c , int d){
	a = MAX ( a , b ) ;
	a = MAX ( a , c ) ;
	a = MAX ( a , d ) ;
	return a ;
}
int main(){
	std::ios::sync_with_stdio(false) ;
	int  i  , j  , k ;
	memset( f , 0 , sizeof(f) ) ; 
	memset( dis , 0 , sizeof(dis) ) ; 
	cin >> rows  >> cols ;
	for( i = 1 ; i <= rows ; i++ )
		for( j = 1 ; j <= cols ; j++ )
			cin >> dis[i][j] ;
	step = rows + cols - 2 ;
	f[1][2][1] = f[1][1][2]= dis[1][2] + dis[2][1] ; 
	for( k = 2 ; k <= (step - 1) ; k++ )
		for( i = 1 ; i <= rows ; i++ )
			for( j = 1 ; j <= rows ; j++ )
				if( i != j )
	f[k][i][j] = dis[i][k - i + 2] + dis[j][k - j + 2] + Max( f[k - 1][i - 1][j - 1] , f[k - 1][i - 1][j] , f[k - 1][i][j - 1] , f[k - 1][i][j]) ;
		cout << f[step - 1][rows - 1][rows] << endl ;
	return 0 ;	
	
	
	
}
