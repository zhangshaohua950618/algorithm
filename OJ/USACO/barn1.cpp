/*
ID: zhangsh35
PROG: barn1 
LANG: C++
*/
#include<fstream>
#include<algorithm>
using namespace std ;
ifstream cin("barn1.in") ;
ofstream cout("barn1.out") ;
const int MAXN = 200 + 10 ;
int totBoard , totBull , totCow  , minBull = 0x7fffffff , maxBull , nocow , current , cnt , len ;
int freeBull[MAXN] ;
bool cow[MAXN] ;
#define MAX( a , b ) ( (a) > (b) ? (a) : (b))
#define MIN( a , b ) ( (a) < (b) ? (a) : (b))
bool cmp( int a , int b ){
	return a > b ;
}
int main(){
	int  i , j ;
	cin >> totBoard >> totBull >> totCow ;
	for( i = 1 ; i <= totCow ; i++ ){
		cin >> nocow ;
		cow[nocow] =true ;
		minBull = MIN( minBull , nocow ) ;
		maxBull = MAX( maxBull , nocow ) ;
	}
	for( i = minBull ; i <= maxBull ; i++ ){
		if(!cow[i])
		current++ ;
		else{
			freeBull[cnt++] = current ;
			current = 0 ;
		}
	}
	sort( freeBull , freeBull + cnt , cmp ) ;
	len = maxBull - minBull + 1 ;
	for( i = 0 ; i  < totBoard - 1 ; i++ ){
		len -= freeBull[i] ;
	}
	cout << len << endl ;
	return 0 ;
	
	
	
	
}
