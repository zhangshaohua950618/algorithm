#include<iostream>
using namespace std ;
int a , b , n , res ;
int main(){
	int i  ;
	while( cin >> n &&  n){
		a = 0 ;
		res = 0 ;
		for( i = 0 ; i < n ; i++ ){
			cin >> b ;
			res += 5 ;
			if( b - a > 0 )
			res += 6 * ( b - a ) ;
			else
			res += 4 * ( a - b ) ;
			a = b ;
		}
		cout << res << endl ;
		
	}
	
}
