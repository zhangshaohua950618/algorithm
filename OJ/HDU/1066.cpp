#include<iostream>
using namespace std ;
int n , mul ;
int main(){
	int temp ;
	while( cin >> n ){
		mul = 1 ;
		for( int i = 1 ; i <= n ; i++ ){
			temp = i ;
			while( temp % 5 == 0){
				mul /= 2 ;
				temp /= 5 ;
			}
			mul *= temp ;
			mul %= 10 ; 
		}
		cout << mul << endl ;
	}
	return 0 ;
	
}
