#include<iostream>
using namespace std ;
int countOne , countTwo ;
int gcdOne( int a , int b){
	countOne++ ;
	return b?gcdOne(b,a%b):a ;
}
int gcdTwo( int a , int b ){
	int r = 0 ;
	do{
		r = a % b ;
		a = b ;
		b = r ;
		countTwo++ ;
	}while(r != 0) ;
	return a ;
}
int main(){
	cout << gcdOne(1001,21) << endl ;	
	cout << gcdTwo(1001,21) << endl ;
	cout << countOne << endl ;
	cout << countTwo << endl ;
	return 0 ;
}
