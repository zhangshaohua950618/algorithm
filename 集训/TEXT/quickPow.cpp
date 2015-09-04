#include<iostream>
using namespace std ;
int  x , n ;
int quicklyPow(int x , int n){
	int result = 1 ;
	while(n){
		if(n&1)
		result *= x ;
		x = x * x  ;
		n >>= 1 ;
	}
	return result ;
}
int main(){
	while( cin >> x >> n )
		cout << quicklyPow( x , n ) << endl ;
	return 0 ;
}
