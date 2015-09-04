#include<iostream>
using namespace std ;
int n ,  num , sum ;
int main(){
	int i ;
	cin >> n ;
	for( i = 0 ; i < n ; i ++ ){
		cin >> num ;
		sum += num ;
	}
	cout << sum << endl ;
	return 0 ;
}
