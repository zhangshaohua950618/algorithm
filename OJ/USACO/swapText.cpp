#include<iostream>
#include<string.h>
using namespace std ;
string input ;
void Swap( char &a , char &b){
	a ^= b ;
	b ^= a ;
	a ^= b ;
}
int main(){
	cin >> input ;
	cout << input << endl ;
	int len = input.length() ;
	Swap( input[0] , input[len - 1]) ;
	cout << input << endl ;
	
}
