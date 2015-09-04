/*
ID:		zhangsh35
PROG:	holstein
LANG:	C++
*/
#include<fstream>
#include<string.h>
using namespace std ;
const int MAXN = 25 +10 ;
int totKind , totVitamin , state ;
int limit[MAXN] , current[MAXN] , vitamin[MAXN][MAXN] , minLen = 0x7ffffff , minState , len ;
int result[MAXN] , cnt ;
bool ok ;
ifstream cin("holstein.in") ;
ofstream cout("holstein.out") ;
int main(){
	int i , j ;
	cin >> totKind ;
	for( i = 1 ; i <= totKind ; i++ )
	cin >> limit[i] ;
	cin >> totVitamin ;
	for( i = 0 ; i < totVitamin ; i++ )
	for( j = 1 ; j <= totKind ; j++ )
	cin >> vitamin[i][j] ;
	for( state = 1 ; state <= ( 1 << ( totVitamin + 1) - 1 ) ; state++ ){
		memset( current , 0 ,sizeof(current) ) ;
		len  = 0 ;
		for( i = 0 ; i < totVitamin ; i++ )
			if((state) & ( 1 << i )){
				len++ ;
				for( j = 1 ; j <= totKind ; j++ )
					current[j] += vitamin[i][j] ;
				}
		ok = true ;
		for( i = 1 ; i <= totKind ; i++ ){
			if(current[i] < limit[i])
			ok = false ;
		}
		if((ok) && (len < minLen)){
			minLen = len ;
			minState = state ;
		}
	}
	i = 0 ;
	len = 0 ;
	while(minState){
		if( minState %2 )
		result[len++] = i + 1;
		minState /= 2 ;	
		i++ ;	
	}
	cout << minLen << " " ;
	for( i = 0 ; i < minLen - 1 ; i++ )
	cout << result[i] << " ";
	cout << result[i] << endl ;
	return 0 ;
	
}
