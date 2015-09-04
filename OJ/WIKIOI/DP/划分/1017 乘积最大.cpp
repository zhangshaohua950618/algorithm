#include<iostream>
#include<string.h>
#define MAX( a , b ) ( (a) > (b) ? (a) : (b))
using namespace std ;
const int MAXN = 40 + 5 ;
long long g[MAXN][MAXN] , f[MAXN][MAXN] ;
int totLength , totMul ;
string str ;
int main(){
	cin >> totLength >> totMul ;
	cin >> str ;
	for( int  i = 0 ; i < str.length() ; i++ ){
		g[i][i] = str[i] - '0' ;
		for( int j = i + 1 ; j < str.length() ; j++)
		g[i][j] = g[i][j - 1] * 10 + str[j] - '0' ;
	}
	for( int  i = 0 ; i < str.length() ; i++ )
	f[i][0] = g[0][i] ;
	for( int i = 0 ; i < str.length() ; i++ )
	for( int j = 1 ; j <= i  ; j++ )
	for( int k = 0 ; k <= i ; k++ )
	f[i][j] = MAX( f[i][j] , f[k][j - 1] * g[k + 1][i]) ;
	cout << f[totLength - 1][totMul] << endl ;
	return 0 ;	
}
