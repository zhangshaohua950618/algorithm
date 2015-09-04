#include<iostream>
#include<string.h>
#include<string>
using namespace std ;
string str ;
int num ;
int main(){
	int i ;
	while( cin >> str && str !="0" ){
		num = 0 ;
	for( i = 0 ; i < str.length() ; i++ )
	num += str[i] - '0' ;
	if(!(num % 9))
	cout << 9 << endl ;
	else
	cout << num % 9  << endl ;
	
	}
	return 0 ;
}
