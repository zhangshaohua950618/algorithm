#include<iostream>
#define MAX( a , b ) ((a) > (b) ? (a) : (b))
using namespace std ;
const int MAXN = 100000 + 50 ;
struct Pack{
	int cost ;
	int value ;
} ;
Pack p[500 + 50] ;
int f[MAXN] , totPack , totCost ;
int main(){
	cin >> totPack >> totCost ;
	for( int i = 0 ; i < totPack ; i++ )
	cin >> p[i].cost >> p[i].value ;
	for( int  i = 0 ; i < totPack ; i++ )
	for( int  j = totCost ; j >= p[i].cost ; j-- ) 
	f[j] = MAX( f[j] , f[j - p[i].cost] + p[i].value) ;
	cout << f[totCost] << endl ;
	return 0 ;
}
