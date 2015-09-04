#include<iostream>
using namespace std ;
int t  , n , s  ;
int main(){
	int  i ;
	cin >> t ;
	while( t-- ){
		cin >> n ;
		s = 0 ;
		for( i = 1 ; i <= n / 2 ; i++ )
		if(n % i == 0)
		s += i ;
		cout << s << endl ;
	}
	
}
