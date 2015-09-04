#include<iostream>
using namespace std ;
const int MAXN = 1000 + 10 ;
int c[MAXN] , n ;
int main(){
	int i , j ;
	while( cin >> n ){
		for( i = 0 ; i < n ; i++ )
		cin >> c[i] ;
		for( i = 0 ; i < n ; i++ )
		cout << (char)(c[i]) ;
	//	cout << endl ;
	}
	return 0 ;
	
}
