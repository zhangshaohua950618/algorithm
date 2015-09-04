#include<iostream>
#include<string.h>
#define MAX( a , b ) ((a) > (b) ? (a) : (b))
using namespace std ;
const int MAXN = 100 + 10 ;
int height[MAXN][MAXN]  , path[MAXN][MAXN] ;
int rows , cols , ans ;
int getHeight( int x , int y ){
	int ans = 1 ;
	if(height[x][y])
	return height[x][y] ;
	if(path[x - 1][y] > path[x][y])
		ans = MAX( ans , getHeight(x - 1 , y) + 1) ;
	if(path[x + 1][y] > path[x][y])
		ans = MAX( ans , getHeight(x + 1 , y) + 1 ) ;
	if(path[x][y - 1] > path[x][y])
		ans = MAX( ans , getHeight(x , y - 1) + 1) ;
	if(path[x][y + 1] > path[x][y])
		ans = MAX( ans , getHeight(x , y + 1) + 1) ;
	return ans ; 
}
int main(){
	int i , j ;
	while(cin >> rows >> cols ){
		ans = 0 ;
		memset(path , 0 , sizeof(path)) ;
		memset(height , 0 , sizeof(height)) ;
		for( i = 1 ; i <= rows ; i++ )
		for( j = 1 ; j <= cols ; j++ )
			cin >> path[i][j] ;
		for( i = 1 ; i <= rows ; i++ )
		for( j = 1 ; j <= cols ; j++ ){
			 height[i][j] = getHeight( i , j ) ;
			 ans = MAX( ans , height[i][j] ) ;
		}
		cout << ans << endl ;
	}
}
