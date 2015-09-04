#include<iostream>
using namespace std ;
int n , m ;
int gcd( int a , int b ){
	return b ? gcd(b , a % b) : a ;
}
int main(){
	while( cin >> n >> m && n != -1 ){
		if(gcd( n , m ) == 1 )
		cout << "YES" << endl ;
		else
		cout << "POOR Haha" << endl ; 
	}
	return 0 ;
}
