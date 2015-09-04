#include<iostream>
using namespace std ;
int n , num , pre , totNum ;
int  lcm( int a , int b){
	int tempA = a ;
	int tempB = b ;
	int r ;
	do{
		r = a % b ;
		a = b ;
		b = r ; 
	}while(r) ;
	return  tempA / a * tempB ;
}
int main(){
		cin >> n ;
		while( n-- ){
			cin >> totNum ;
			cin >> pre ;
			for( int  i = 1 ; i < totNum ; i++ ){
				cin >> num ;
				pre = lcm( num , pre ) ;
			}
			cout << pre  << endl ;
		}
		return 0 ;
}
