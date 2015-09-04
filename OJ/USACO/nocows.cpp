/*
ID: zhangsh35
PROG: nocows 
LANG: C++
*/
#include<fstream>
#include<math.h>
#define MIN( a , b ) ((a) < (b) ? (a) : (b))
using namespace std ;
ifstream cin("nocows.in") ;
ofstream cout("nocows.out")  ;
const int MOD = 9901 ;
int f[100 + 10][200 + 10] ;
int height , totNode ;
int main(){
	
	cin >> totNode >> height ;
	for( int  i = 1 ; i <= height ; i++ )
	f[i][1] = 1 ;
	for( int i = 2 ; i <= height ; i++ )
	for( int j = 3 ; j <= MIN( totNode , pow( 2 , i) - 1) ; j += 2)
	for( int k = 1 ; k <= j - 2 ; k+= 2 ){
		f[i][j] += ( f[i -1][k] * f[i - 1][j - k - 1]) % MOD ;
		f[i][j] %= MOD ;
	}
	cout << ( f[height][totNode] - f[height - 1][totNode] + MOD ) % MOD << endl ;
	return 0 ;
	
	
}
