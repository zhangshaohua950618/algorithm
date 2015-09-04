/*
ID:    zhangsh35
PROG:    fence
LANG:    C++
*/
#include<fstream>
using namespace std ;
ifstream cin("fence.in") ;
ofstream cout("fence.out") ;
const int MAXN = 500 + 10 ;
int fence[MAXN][MAXN] ;
int degree[MAXN] , path[MAXN] ;
int totFence , start , end , maxNode , minNode = MAXN , length ;
int Euler( int startNode ){
	if(degree[startNode]){
		int i  ;
		for( i = minNode ; i  <= maxNode  ; i++ ){
			if(fence[startNode][i]){
				fence[startNode][i]-- ;
				fence[i][startNode]-- ;
				degree[startNode]-- ;
				degree[i]-- ;
				Euler(i) ;
				break ;
			}
		}
	
	}
	path[length++] = startNode ;
	if( length == totFence + 1 ){
		for( int i = totFence ; i >= 0 ; i--){
			cout << path[i] << endl ;
		}
		exit(0);
	}
}
int main(){
	cin >> totFence  ;
	int i , j ;
	for( i = 0 ; i  < totFence ; i++){
		cin >> start >> end ;
		fence[start][end]++ ;
		fence[end][start]++ ;
		degree[start]++ ;
		degree[end]++ ;
		if(start > maxNode)
		maxNode = start ;
		if(end > maxNode)
		maxNode = end ;
		if(start < minNode)
		minNode = start ;
		if(end < minNode)
		minNode = start ;	 
	}
	start = minNode ;
	for( i = minNode ; i <= maxNode ; i++ ){
		if(degree[i] & 0x1){
			start = i ;
			break ;
		}
	}
	Euler(start) ;
}




