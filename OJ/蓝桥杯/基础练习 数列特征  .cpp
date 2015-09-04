#include<iostream>
#include<cstdlib>
using namespace std ;
int N , num , maxNum =-(1 << 30) , sum , minNum = (1 << 30) ;
int main(){
	int i ; 
	cin >> N ;
	for(i = 0 ; i < N ; i++){
		cin >> num ;
		maxNum = max(num , maxNum) ;
		minNum = min(num , minNum) ;
		sum += num ;
	}
	cout << maxNum << endl << minNum << endl<< sum << endl ;
	return 0 ;
}
