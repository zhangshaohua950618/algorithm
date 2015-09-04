#include<iostream>
using namespace std ;
int gcd( int a , int b ){
	return b ?gcd(b , a % b) : a ;
}
int a , b ;
int main(){
	while( cin >> a >> b ){
		cout << a * b /gcd( a ,b ) << endl ;
	}
	return 0 ;
}
