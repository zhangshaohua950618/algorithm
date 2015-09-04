#include<iostream>
using namespace std ;
int f[1005] ;
bool Judge( int num ){
	int a = num - 1 ;
	int b = num ;
	int c = num + 1 ;
	while(c){
		if( a % 10 + b % 10 + c % 10 >= 10 )
		return false ;
		a /= 10 ;
		b /= 10 ;
		c /= 10 ;
	}
	return true ;
}
int main(){
	f[1] = 1 ;
	int i  , n ;
	cin >> n ;
	for( i = 2 ; i <= n ; i++ )
	f[i] = Judge(i) ? f[i - 1] + 1 : f[i - 1] ;
	cout << f[n] << endl ;
	return 0 ;
}
