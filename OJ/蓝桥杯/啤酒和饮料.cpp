#include<iostream>
using namespace std ;
int main(){
	int y , p ;
	double  m  = 0.0 ; 
	double eps = 1e-5 ;
	for( p = 0 ; m -82.3 > eps ; p++ )
	for( y = p + 1 ;m -82.3 > eps ;y++ ){
		m = p * 2.3 + y * 1.9 ;
		//cout << m << endl ;
		if(m -82.3 < eps){
			cout << p << endl ;
			return 0 ;
		}
	}
	
}
