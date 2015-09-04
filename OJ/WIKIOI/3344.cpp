#include<iostream>
#include<string.h>
#include<queue>
using namespace std ;
const int MAXN = 200 ;
int row , col ;
struct Point{
	int x ;
	int y ;
	int setp ;
} ;
Point p[MAXN] ;
int path[MAXN][MAXN] ;
bool vis[MAXN][MANX] ;
queue<Point> q ;
void intial(){
	memset(path , 0 , sizeof(path)) ;
	int i , j ; 
	cin >> row >> col ;
	for( i = 1 ; i <= row ; i++)
	for( j = 1 ; j <= col ; j++)
	cin >> path[i][j] ;
}
int main(){
	
}
