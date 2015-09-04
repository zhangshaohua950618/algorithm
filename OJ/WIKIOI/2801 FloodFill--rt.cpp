#include<iostream>
#include<string.h>
#define MAX(a,b) ((a) > (b) ? (a) : (b))
using namespace std ;
const int MAXN = 1500 + 10 ;
char path[MAXN][MAXN] ;
int color , row , col , m , count , per ;
string res ;
int fill( int x , int y ,int c){
	int count = 0 ;
	if(path[x][y] == '*'){
		path[x][y] = c ;
		count++ ;
		if(path[x - 1][y] == '*')
		count += fill(x - 1 , y , c) ;
		if(path[x + 1][y] == '*')
		count += fill(x + 1 , y , c) ;
		if(path[x][y + 1] == '*')
		count += fill(x , y + 1 , c) ;
		if(path[x][y - 1] == '*')
		count += fill(x , y - 1 , c) ;
	}
	return count ;
}
int main(){
	int i , j ;
	cin >> row >> col >> per ;
	for( i = 1 ; i <= row ; i++ )
	for( j = 1 ; j <= col ; j++ )
	cin >> path[i][j] ;
	for( i = 1 ; i <= row ; i++ )
	for( j = 1 ; j <= col ; j++ )
	if(path[i][j] == '*'){
		count = fill( i , j , color) ;
		if( count == 0)
		color++ ;
		else
		m = MAX( m ,count ) ;
	}
	res = m * 3 >= per ? "Demacia Win!" : "Demacia Lose!" ;
	cout << res << endl ;
	return 0 ;
}
