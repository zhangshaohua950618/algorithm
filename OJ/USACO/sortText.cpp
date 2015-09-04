#include<iostream>
#include<algorithm>
using namespace std ;
bool cmp( int a , int b ){
	return a > b ;
}
int num[100][100] ;
int main(){
	num[5][6] = 99 ;
	num[2][1] = 100 ; 
	sort( num , num + 100 * 100 , cmp ) ;
	for( int i = 0 ; i < 100 * 100 ; i++ )
	cout << num[i] << endl ;
}
