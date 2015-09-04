#include<iostream>
#define MAX(a , b) ((a) > (b) ? (a) : (b))
#define MIN(a , b) ((a) < (b) ? (a) : (b))
using namespace std ;
int n , num , maxNum = -99999999 , minNum = 99999999;
int main(){
	int i ;
	cin >> n ;
	for( i = 0 ; i < n ; i ++ ){
		cin >> num ;
		maxNum = MAX(maxNum , num) ;
		minNum = MIN(minNum , num) ;
	}
	cout << minNum << " " << maxNum << endl ;
	return 0 ;
}
