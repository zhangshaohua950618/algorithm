#include<iostream>
using namespace std ;
int  x , n , mod ;
int quicklyPow(int x , int n){
	int result = 1 ;
	while(n){
		if(n&1)
		result = result * x % mod;
		x = x * x % mod ;
		n >>= 1 ;
	}
	return result ;
}
int main(){
	while( cin >> x >> n >> mod )
		cout << quicklyPow( x , n ) << endl ;
	return 0 ;
}
