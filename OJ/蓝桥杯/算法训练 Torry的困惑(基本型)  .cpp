#include<iostream>
#include<string.h>
using namespace std ;
const int MAXN = 100000 + 10 ;
bool isPrime[MAXN] ;
int  prime[MAXN] ;
int totPrime ;
int num , sum = 1 ;
void Euler(){
	int i , j ;
	memset( isPrime , true , sizeof(isPrime) ) ;
	isPrime[0] = false ;
	isPrime[1] = false ;
	for( i = 2 ; i <= MAXN ; i++ ){
		if(isPrime[i])
		prime[totPrime++] = i ;
		if(totPrime == num)
		break ;
		for( j = 0 ; j < totPrime ; j++ ){
			if( i * prime[j] > MAXN)
			break ;
			isPrime[i * prime[j]] = false ;
			if( i % prime[j] == 0)
			break ;
		}
	}
}
int main(){
	int i ;
	Euler() ;
	cin >> num ;
	for( i = 0 ; i < num ; i++ )
	sum = sum * prime[i]  % 50000;
	cout << sum << endl ;
	return 0 ;	
}


