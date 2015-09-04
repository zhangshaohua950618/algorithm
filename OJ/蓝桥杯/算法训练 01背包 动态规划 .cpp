#include<iostream>
using namespace std;
int value[30000 + 10] ;
int totPrice , totThing ;
#define MAX( a , b ) ((a) > (b) ? (a) : (b))	
int ZeroOnePack(){
	int i , j , price , weight ;
	for( i = 1 ; i <= totThing ; i++ ){
		cin >> price >> weight ;
		for( j = totPrice ; j >= price ; j-- )
		value[j] = MAX( value[j] , value[j - price] + price * weight ) ;
	}
	return value[totPrice] ;
	
}
int main(){
	cin >> totPrice >> totThing ;
	cout << ZeroOnePack() << endl;
	return 0 ;
}
