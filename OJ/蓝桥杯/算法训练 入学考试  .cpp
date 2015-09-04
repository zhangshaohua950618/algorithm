#include<iostream>
using namespace std ;
int value[1000 + 10] ;
int totTime , totHerb ;
#define MAX( a , b ) ((a) > (b) ? (a) : (b))
int ZeroOnePack(){
	int i , j , time , herb ;
	for( i = 1 ; i <= totHerb ; i++ ){
		cin >> time >> herb ;
		for( j = totTime ; j >= time ; j-- )
		value[j] = MAX( value[j] , value[j - time] + herb ) ;
	}
	return value[totTime] ;
}
int main(){
	cin >> totTime >> totHerb ;
	cout << ZeroOnePack() << endl ;
	return 0 ;
}
