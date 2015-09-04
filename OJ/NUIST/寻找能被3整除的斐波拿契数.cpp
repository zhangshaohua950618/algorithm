#include<iostream>
#include<vector>
using namespace std ;
long long num ;
typedef vector<int> vec ;
typedef vector<vec> mat ;
mat mul(mat &a , mat &b){
	int i , j , k ;
	mat c(a.size() , vec(b[0].size())) ;
	for( i = 0 ; i < 2 ; i++ )
	for( j = 0 ; j < 2 ; j++ )
	for( k = 0 ; k < 2 ; k++ )
	c[i][j] = (a[i][k] * b[k][j]) % 3 ;
	return c ;
}
mat quick(mat a , int n ){
	int i ;
	mat b(a.size() , vec(b[0].size())) ;
	for( i = 0 ; i < 2 ; i++) 
	b[i][i] = 1 ;
	while(n){
		if( n & 1)
		b = mul( b , a ) ;
		n >>= 1 ;
	}
	return b ;
}
int main(){
	mat a(4 , vec(2)) ;
	 while( cin >> num ){
	 	a = quick( a , num) ;
	 	cout << (a[1][0] * 7) % 3 << endl ;
	 }
	
}
