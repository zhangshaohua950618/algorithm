#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std ;
const int MAXN = 100 + 10 ;
int n ,num1[MAXN] , num2[MAXN] ,c ;
int main(){
	int i  ;
	while( cin >> n && n ){
		memset(num1 , 0 , sizeof(num1)) ;
		memset(num2 , 0 , sizeof(num2)) ;
		c  = 0;
		for( i = 0 ; i < n ; i++ )
		cin >> num1[i] ;
		for( i = 0 ; i < n ; i++ )
		cin >> num2[i] ;
		sort( num1 , num1 + n ) ;
		sort( num2 , num2 + n ) ;
		for( i = 0 ; i < n ; i++ ){
			if(num1[i] > num2[i])
			c += 2 ;
			else if(num1[i] == num2[i])
			c++ ;
		}
		cout << c << " vs " << n * 2 - c << endl ;
	}
	return 0 ; 
	
}
