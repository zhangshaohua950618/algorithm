#include<iostream>
#include<string.h>
using namespace std ;
const int MAXN = 1000 + 10 ;
string sea[MAXN] ;
int color ,rows ,cols ; 
bool flood(int x , int y , int c){
	if(sea[x][y] != '#')
	return false ;
	sea[x][y] = c ;
	if( x - 1 >= 0 )
	flood( x - 1 , y , c ) ;
	if( y - 1 >= 0)
	flood( x , y - 1 , c ) ;
	if( x + 1 < rows)
	flood( x + 1 , y , c ) ;
	if( y + 1 < cols)
	flood( x , y + 1 , c ) ;
	return true ;
}
int main(){
	int i , j ;
	cin >> rows >> cols ;
	for( i = 0 ; i < rows ; i++ )
	cin >> sea[i] ;
	for( i = 0 ; i < rows ; i++ )
	for( j = 0 ; j < cols ; j++ )
	if(flood( i , j , color))
		color++ ;
	cout << "There are " << color<< " ships." ;
	return 0 ;
}
