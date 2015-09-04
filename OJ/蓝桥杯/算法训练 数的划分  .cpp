#include<iostream>
using namespace std ;
int f[200 + 10][10] ;
int main(){
	int n , k ;
	int i , j ;
	cin >> n >> k; 
	f[0][0] = 1  ;
	for( i = 1 ; i <= n ; i++ )
		for( j = 1 ; j <= ( i  < k ? i : k) ; j++ )
		f[i][j] = f[i - 1][j - 1] + f[i - j][j] ;
	cout << f[n][k] << endl;
	return 0 ;
}
