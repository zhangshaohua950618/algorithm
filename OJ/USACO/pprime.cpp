/*
ID: zhangsh35
PROG: pprime 
LANG: C++
*/
#include<fstream>
using namespace std ;
ifstream cin("pprime.in") ;
ofstream cout("pprime.out") ;
bool IsPrime( int num ){
	int  i ;
	for( i = 2 ; i * i <= num ; i++ ){
		if( num % i == 0)
		return false ;
	}
	return true ;
}
int prime[100000] ;
int number , start , end , num ;
int main(){
	int i , j , k , l  ;
	for( i = 1 ; i <= 9 ; i++ ){
		number = i ;
		if(IsPrime(number))
		prime[num++] = number ;
	}
	for( i = 1 ; i <= 9 ; i++ ){
		number = i * 10 + i ;
		if(IsPrime(number))
		prime[num++] = number ;
	}
	for( i = 1 ; i <= 9 ; i++ )
	for( j = 0 ; j <= 9 ; j++ ){
		number = i * 100 + j * 10 + i ;
		if(IsPrime(number))
		prime[num++] = number ;
	}
	for( i = 1 ; i <= 9 ; i++ )
	for( j = 0 ; j <= 9 ; j++ ){
		number = i * 1000 + j * 100 + j * 10 + i ;
		if(IsPrime(number))
		prime[num++] = number ;
	}
	for( i = 1 ; i <= 9 ; i++ )
	for( j = 0 ; j <= 9 ; j++ )
	for( k = 0 ; k <= 9 ; k++ ){
		number = i * 10000 + j * 1000 + k * 100 + j * 10 + i ;
		if(IsPrime(number))
		prime[num++] = number ;
	}
	for( i = 1 ; i <= 9 ; i++ )
	for( j = 0 ; j <= 9 ; j++ )
	for( k = 0 ; k <= 9 ; k++ ){
		number = i * 100000 + j * 10000 + k * 1000  + k * 100 + j * 10 + i ;
		if(IsPrime(number))
		prime[num++] = number ;
	}
	for( i = 1 ; i <= 9 ; i++ )
	for( j = 0 ; j <= 9 ; j++ )
	for( k = 0 ; k <= 9 ; k++ )
	for( l = 0 ; l <= 9 ; l++ ){
		number = i * 1000000 + j * 100000 + k * 10000 + l * 1000 + k * 100 + j * 10 + i ;
		if(IsPrime(number))
		prime[num++] = number ;
	}
	for( i = 1 ; i <= 9 ; i++ )
	for( j = 0 ; j <= 9 ; j++ )
	for( k = 0 ; k <= 9 ; k++ )
	for( l = 0 ; l <= 9 ; l++ ){
		number = i * 10000000 + j * 1000000 + k * 100000 + l * 10000 + l * 1000 + k * 100 + j * 10 + i ;
		if(IsPrime(number))
		prime[num++] = number ;
	}
	cin >> start >> end ;
	for( i = 0 ; i < num ; i++ ){
		if(prime[i] > end)
		break ;
		if(prime[i] >= start)
			cout << prime[i] << endl ;
		
	}
	return 0 ;
}
