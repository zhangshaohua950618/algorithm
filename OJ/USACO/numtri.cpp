/*
ID: zhangsh35
PROG: numtri 
LANG: C++
*/
#include<fstream>
using namespace std ;
ifstream cin("numtri.in") ;
ofstream cout("numtri.out") ;
const int MAXN = 1000 + 10 ;	
int totLayer , numtrix[MAXN] ,result[MAXN] , maxResult ;
#define MAX( a , b ) ((a) > (b) ? (a) : (b) )
int main(){
	int i , j ;
	cin >> totLayer ;
	for( i = 1 ; i <= totLayer ; i++ ){
		for( j = 1 ; j <= i ; j++ )
		cin >> numtrix[j] ;
		for( j = i ; j >= 1 ; j-- )
		result[j] = MAX( result[j] , result[ j - 1])  + numtrix[j] ;
	}
	for( i = 1 ; i <= totLayer ; i++ )
	maxResult = MAX( maxResult , result[i] ) ;
	cout << maxResult << endl ;
	return 0 ;
}
