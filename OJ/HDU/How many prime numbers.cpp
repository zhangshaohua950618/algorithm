#include<iostream>
#include<math.h>
using namespace std ;
int n , c  , m ;
bool ok ;
int main(){
	while( cin >> n ){
			c= 0 ;
		for( int i = 0 ; i < n ; i++ ){
			cin >> m ;
			ok = true ;
			for( int i = 2 ; i<= sqrt((double)(m))  ; i++ )
				if(m % i == 0 ){
					ok = false ;
					break ;
				}
			if(ok)
			c++ ;
		}
		cout << c << endl ;
	}
	return 0 ;
}
