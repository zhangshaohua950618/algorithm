#include<iostream>
using namespace std ;
const int MAXN = 100 + 10 ;
int f[MAXN][MAXN] ;
int m , n , sum ;
int main(){
	int i , j , k ;
	cin >> m >> n ;
	for( i = 1 ; i < m - 1 ; i++ )
		f[2][i] = m - 2 ;
	
	f[2][0] = 0 ;
	f[2][m - 1] = m - 1 ;
	for( i = 3 ; i <= n ; i++ )
		for( j = 0 ; j < m ; j++ )
			for( k = 0 ; k <= m - 1 ; k++ )
			if((k != j - 1) && (k != j + 1))
				f[i][j] =( f[i][j] + f[i - 1][k] ) % 1000000007;
	for( i = 0 ; i < m ; i++ )
	sum = ( f[n][i] + sum ) % 1000000007 ;
	cout << sum << endl ;
				
	
	
}
