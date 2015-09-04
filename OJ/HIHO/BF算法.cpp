#include<iostream>
#include<string.h>
using namespace std ;
int totString ;
string str , subStr ;
int KMP( string subStr , string str , int start ){
	for( int i = 0 ; i < subStr.length() ; i++ ){
		if( subStr[i] != str[start + i])
		return 0 ;
	}
	return 1 ;
}
int Calculate( string subStr , string str ){
	int count = 0 ;
	for( int i = 0 ; i < str.length() ; i++ )
	count += KMP( subStr , str ,  i ) ;
	return count ;
}
int main(){
	cin >> totString ;
	for( int  i = 0 ; i < totString ; i++ ){
		cin >> subStr >> str ;
		cout << Calculate( subStr , str ) << endl ;
	}
	return 0 ;
}
