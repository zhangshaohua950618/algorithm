#include<iostream>
using namespace std ;
int a , b , l ;
int gcd( int a , int b ){
	return b ? gcd( b , a % b ) : a ;
}
int lcm( int a , int b ){
	return a / gcd( a ,b )  * b;
}
int main(){
	while( cin >> a >> b ){
		if( a * b == 0 ){
			cout << a + b << endl ;
			continue ;
		}
		l = lcm( a , b ) ;
		cout << ( a + b  ) - l / lcm( l / a , l / b ) << endl ;
	}
	return 0 ;
}
