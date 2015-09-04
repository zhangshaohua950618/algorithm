/*
ID:		zhangsh35
PROG:	game1
LANG:	C++
*/
//#include<iostream>
#include<fstream>
using namespace std ;
const int MAXN = 200 + 10 ;
#define MIN( a , b ) ((a) < (b) ? (a) : (b))
int num[MAXN] ;
int sum[MAXN][MAXN] ;
int game[MAXN][MAXN] ;
int main(){
	ifstream cin("game1.in") ;
	ofstream cout("game1.out") ;
	int totNumber ;
	int i , j ;
	cin>>totNumber ;
	for( i = 1 ; i <= totNumber ; i++ )
	cin>>num[i] ;
	for( i = 1 ; i <= totNumber ; i++ ){
		sum[i][i] = num[i] ;
		for( j = i + 1 ; j <= totNumber ; j++ )
		sum[i][j] = sum[i][ j - 1 ] + num[j] ;
	}
	game[totNumber][totNumber] = num[totNumber] ;
	for( i = totNumber ; i >= 1 ; i-- )
	for( j = i ; j <= totNumber ; j++ )
	game[i][j] = sum[i][j] - MIN( game[ i + 1 ][j] , game[i][ j - 1 ] ) ;
	cout<<game[1][totNumber]<<" "<<sum[1][totNumber] - game[1][totNumber]<<endl;
	return 0 ;
}
