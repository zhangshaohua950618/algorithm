/*
ID: zhangsh35
PROG: range 
LANG: C++
*/
#include<fstream>
#include<string.h>
#define MIN( a , b ) ((a) < (b) ? (a) : (b))
using namespace std ;
ifstream cin("range.in") ;
ofstream cout("range.out") ;
const int MAXN = 250 + 10 ;
int result[MAXN] , range[MAXN][MAXN] ;
int maxLength  ;
string  input; 
int main(){
	cin >> maxLength ;
	getline( cin , input ) ;
	for( int i = 1 ; i <= maxLength ; i++ ){
		getline( cin , input ) ;
		for( int  j = 0  ; j < maxLength ; j++ ){
			if(input[j] == '1')
			range[i][j + 1] = MIN( range[i - 1][j + 1] , MIN( range[i][j] , range[i - 1][j] )) + 1 ;
			if(range[i][j + 1] > 1){
				for( int  k = 2 ; k <= range[i][j + 1] ; k++ )
				result[k]++ ;
			}
		}
	}
	for( int i = 2 ; i <= maxLength ; i++ )
	if(result[i])
	cout << i << " " << result[i] << endl ;
	return 0 ;
}
