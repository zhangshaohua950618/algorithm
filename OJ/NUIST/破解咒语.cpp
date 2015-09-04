#include<iostream>
#include<string.h>
using namespace std ; 
const int MAXN = 255 + 10 ;
char a[MAXN] ;
int main(){
	string str ;
	while( cin >> str ){
		memset(a,0,sizeof(a)) ;
	for( int i = 0 ; i < str.length() ; i++ )
		a[str[i]]++ ;
	for(int i = 'a' ; i <= 'z' ; i++ )
		if(a[i] == 1)
			cout << (char)(i) ;
		cout << endl ;
	}
	return 0 ;
}


