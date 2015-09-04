#include<iostream>
#include<string.h>
#include<string>
using namespace std ;
const int MAXN = 1000 + 10 ;
int  n ;
string str[MAXN] ;
void swap( string &a , string &b ){
	string t ;
	t = a ;
	a = b ;
	b = t ;
}
int main(){
	int i , j ;
	while( cin >> n ){
		for(i = 0 ; i < n ; i++ )
		cin >> str[i] ;
		for(i = 0 ; i < n - 1 ; i++ )
		for(j = 0 ; j < n - 1 - i ; j++ )
			if( str[j] + str[j + 1] < str[j + 1] + str[j] )
				swap( str[j] , str[j + 1] ) ;
		for( i = 0 ;i < n ; i++ )
		cout << str[i] ;
		cout << endl ;
	}
	
} 
