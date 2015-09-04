/*
ID: zhangsh35
PROG: fence9 
LANG: C++
*/
#include<iostream>
#include<fstream>
using namespace std ;
int Gcd( int a , int b ){
	int r = a % b ;
	if(!r)
	return b ;
	return Gcd( b , r ) ;
} ;
int Abs( int a ){
	return a > 0 ? a : -a; 
}
int main(){
	ifstream cin("fence9.in") ;
	ofstream cout("fence9.out") ;
	int m , n , p ;
	cin>>n>>m>>p ;
	int pointLeft , pointRight , pointUnder ;
	pointUnder = p - 1 ;
	if( n == 0)
		pointLeft = m - 1 ;
		else 
			pointLeft = ( n - 1 ) * Gcd( m , n) / n ;
	if( n == p)
		pointRight = m - 1 ;
		else{
			int dif = Abs( n -p ) ;
			pointRight = ( dif - 1 ) * Gcd( m , dif )/ dif ;
	}
/*	cout<<pointLeft<<endl;
	cout<<pointRight<<endl;
	cout<<pointUnder<<endl;*/
	cout<<( p * m - pointUnder - pointLeft - pointRight) / 2<<endl;
	
	
}
