#include<iostream>
#include<algorithm>
using namespace std  ;
const int MAXN = 10+ 10 ;
int t, n , num[MAXN] ; 
int main(){
	int i , j ;
	cin >> t ;
	while( t-- ){
		cin >>  n  ;
		for( i = 0 ; i < n ; i++ )
		cin >> num[i] ;
		sort(num , num + n) ;
		cout << num[1] << endl ;
	}
	
}
