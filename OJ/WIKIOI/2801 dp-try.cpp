#include<iostream>
#include<string.h>
#define MAX(a,b) ((a) > (b) ? (a) : (b))
using namespace std ;
const int MAXN = 1500 + 10 ;
char path[MAXN][MAXN] ;
int count[MAXN] ;
int color , row , col , m , count , per ;
string res ;
int main(){
	int i , j ;
	cin >> row >> col >> per ;
	for( i = 1 ; i <= row ; i++ )
	for( j = 1 ; j <= col ; j++ )
	cin >> path[i][j] ;
	for( i = 1 ; i <= row ; i++ )
	for( j = 1 ; j <= col ; j++ )
	
		m = MAX( m ,count ) ;
	}
	res = m * 3 >= per ? "Demacia Win!" : "Demacia Lose!" ;
	cout << res << endl ;
	return 0 ;
}
