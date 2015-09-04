#include<iostream>
#include<map>
using namespace std ;
const int MAXN = 10 + 2 ;
bool maze[MAXN][MAXN] ;
map< int  , char > m ;
int rows , path[ MAXN * MAXN ] , count , startRows , startCols , step , tempCount , tempStep ;	
void dfs( int startRows , int startCols ){
	if( step == ( rows * rows )){
		for( int i = 0 ; i < count ; i++ )
		cout << m[path[i]] ;
		cout << endl ;
		exit(0) ;
	}
	for( int i = 0 ; i < 4 ; i++ ){
		tempCount = count ;
		tempStep = step ;
		if(  i == 0 ){// Get to East
			if( ( ( startCols + 1 ) <= rows ) && (!maze[startRows][startCols + 1 ])){
				path[count++] = 0 ;
				while( ( startCols + 1  <= rows ) && (!maze[startRows][ startCols + 1 ])){
					startCols++ ;
					step++ ;
				}
					dfs( startRows , startCols ) ;
					count = tempCount ;
					step = tempStep ;
			}
		}
		if(  i == 1 ){// Get to South
			if( ( startRows + 1  <= rows ) && ( !maze[startRows + 1][startCols]) ){
				path[count++] = 1 ;
				while( ( startRows + 1  <= rows ) && ( !maze[startRows + 1][startCols]) ){
					startRows++ ;
					step++ ;
				}
					dfs( startRows , startCols ) ;
					count = tempCount ;
					step = tempStep ;
			}
		}
		if(  i == 2 ){// Get to West
			if( ( startCols - 1   >= 0 ) && ( !maze[startRows][startCols - 1]) ){
				path[count++] = 2 ;
				while( ( startCols - 1   >= 0 ) && ( !maze[startRows][startCols - 1]) ){
					startRows++ ;
					step++ ;
				}
					dfs( startRows , startCols ) ;
					count = tempCount ;
					step = tempStep ;
			}
		}
		if(  i == 3 ){// Get to North
			if( ( startRows - 1   >= 0 ) && ( !maze[startRows - 1][startCols]) ){
				path[count++] = 3 ;
				while( ( startRows - 1   >= 0 ) && ( !maze[startRows - 1][startCols]) ){
					startRows++ ;
					step++ ;
				}
					dfs( startRows , startCols ) ;
					count = tempCount ;
					step = tempStep ;
			}
			
			
		}
	}
}
int main(){
	m[0] = 'E' ;
	m[1] = 'S' ;
	m[2] = 'W' ;
	m[3] = 'N' ;
	cin >> rows ;
	for( int i = 1 ; i <= rows ; i++ )
		for( int j = 1 ; j <= rows ; j++ ){
			cin >> maze[i][j] ;
			if( maze[i][j] )
			step++ ;
		}
	for( int i = 1 ; i <= rows ; i++ )
		for( int j = 1 ; j <= rows ; j++ ){
			if( maze[i][j] ){
				startRows = i ;
				startCols = j ;
				dfs( i , j ) ;
			}
		}
		return 0 ;
}
