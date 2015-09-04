#include<iostream>
#include<string.h>
using namespace std ;
string str , sub ;
bool ok ;
int main(){
	int i , j ;
	cin >> str >> sub ;
	for( i = 0 ; i < str.length() ; i ++ ){
		if( str[i] == sub[0]){
			ok = true ;
			for( j = 1 ; j < sub.length() ; j ++ )
			if( str[i + j] != sub[j] )
			ok = false ;
			if(ok){
			cout << i + 1 << endl ;
			return 0 ;
			}
		}
	}
}
