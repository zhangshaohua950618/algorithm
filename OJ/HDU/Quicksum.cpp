#include<iostream>
#include<string.h>
using namespace std ;
const int MAXN = 1000 + 10 ;
char s[MAXN] ;
int n ;
int main(){
	int i ;
	while(gets(s)){
		if(s[0] == '#')
		break ;
		n = 0 ;
		for( i = 0 ; i < strlen(s) ; i++ ){
			if(s[i] >= 'A' && s[i] <= 'Z'){
				n += ( i + 1 ) * (s[i] - 'A' + 1) ;	
			}
		}
		cout << n << endl ;
	}
	return 0 ;
	
}
