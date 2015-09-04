/*
ID: zhangsh35
PROG: sprime 
LANG: C++
*/
#include<fstream>
using namespace std ;
ifstream cin("sprime.in") ;
ofstream cout("sprime.out") ;
const int MAXN = 200 ;
int sprime[10][MAXN] , num[10] , length ;
void Initial(){
	sprime[1][0] = 2 ;
	sprime[1][1] = 3 ;
	sprime[1][2] = 5 ;
	sprime[1][3] = 7 ;
	num[1] = 4 ;
}
bool IsPrime( int num ){
	int i ;
	for( i = 2 ; i * i <= num ; i++ )
	if( num % i == 0)
	return false ;
	return true ;
}
int main(){
	Initial() ;
	int i ,j , k ;
	for( i = 2 ; i <= 8 ; i++ )
	for( j = 0 ; j < num[ i - 1 ] ; j++ ){
		if( IsPrime(sprime[ i - 1 ][j] * 10 + 1 ))
		sprime[i][num[i]++] = sprime[ i - 1 ][j] * 10 + 1 ;
		if( IsPrime(sprime[ i - 1 ][j] * 10 + 3 ))
		sprime[i][num[i]++] = sprime[ i - 1 ][j] * 10 + 3 ;
		if( IsPrime(sprime[ i - 1 ][j] * 10 + 7 ))
		sprime[i][num[i]++] = sprime[ i - 1 ][j] * 10 + 7 ;
		if( IsPrime(sprime[ i - 1 ][j] * 10 + 9 ))
		sprime[i][num[i]++] = sprime[ i - 1 ][j] * 10 + 9 ;
	}
	cin >> length ;
	for( i = 0 ; i < num[length] ; i++ )
	cout << sprime[length][i] << endl ;
	return 0 ;
	
}
