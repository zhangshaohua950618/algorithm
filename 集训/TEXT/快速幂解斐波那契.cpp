#include<iostream>
#include<vector>
using namespace std ;
typedef vector<int> vec ;
typedef vector<vec> mat ;
const int mod = 
mat mul( mat &a ,mat &b ){
	mat c(4 , vec(2)) ;
	int i , j , k  ;
	for( i = 0 ; i < 2 ; i++ )
	for( j = 0 ; j < 2 ; j++ )
	for( k = 0 ; k < 2 ; k++ ){
		c[i][j] += a[i][k] *  b[k][j] ;
		c[i][j] = c[i][j] % 5 ;
	}
	return c ;
}
mat quick( int n , mat a ){
	mat c(4 , vec(2)) ;
	
	
}
int main(){
	
}
