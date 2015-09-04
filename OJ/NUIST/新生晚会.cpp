#include<iostream>
#define MIN(a,b) ((a) < (b) ? (a) : (b))
using namespace std ;
int t , a , b ;
int gcd( int a , int b ){
	return b ? gcd( b , a % b) :a ;
}
int cal( int a , int b ){
	if( b > a)
	return 0 ;
	int mul = 1 , div = 1, i , t ;
	b = MIN(b,a -b) ;
//	cout << b << endl ;
	for( i = 1 ; i <= b ; i++ ){
		mul *= (a - i + 1) ;
		div *= i ;
	//	cout <<"mul = " << mul << "div = " << div << endl ;
		t = gcd( mul , div ) ;
		mul /= t ;
		div /= t ;
	}
	return mul ;
}
int main(){
	cin >> t ;
	while( t-- ){
		cin >> a >> b ;
		cout << cal( a , b ) << endl ;
	}
	return 0 ;
	
}
