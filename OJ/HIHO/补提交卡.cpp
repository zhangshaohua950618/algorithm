#include<iostream>
#include<string.h>
using namespace std ;
const int MAXN = 100 + 10 ;
int off[MAXN] , totText , dayOff , cards , maxLength , cur ;
int main(){
	int i , j , k ;
	cin >> totText ;
	for( i = 0 ; i < totText ; i++ ){
		cin >> dayOff >> cards ;
		memset( off , 0 , sizeof(off)) ;
		off[0] = 0 ;
		maxLength = 0 ;
		for( j = 1 ; j <= dayOff ; j++ )
		cin >> off[j] ;
		off[j] = 101 ;
		if(cards >= dayOff){
			cout << "100" << endl ;
			continue ;
		}
		else
		for( j = 0 ; j <= dayOff - cards ; j++ ){
			cur = off[j + cards + 1] - off[j] ;
			if( cur > maxLength )
			maxLength = cur ; 
		}
		cout << maxLength - 1 << endl ;
	}
	
	
}
