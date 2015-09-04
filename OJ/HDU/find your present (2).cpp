#include<stdio.h>
int n , a, r ;
int main(){
	int i ;
	while( ~scanf( "%d" , &n ) && n ){
		r = 0 ;
		for( i = 0 ; i < n ; i++ ){
			scanf( "%d" , &a ) ;
			r ^= a ;
		}
		printf("%d\n" , r ) ;
	}
	return 0 ;
	
}
