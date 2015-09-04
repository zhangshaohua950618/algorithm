/*
ID: zhangsh35
PROG: stall4 
LANG: C++
*/
#include<fstream>
#include<string.h>
using namespace std ;
ifstream cin("stall4.in") ;
ofstream cout("stall4.out") ;
const int MAXN = 200 + 20 ;
int match[MAXN] ;
bool mark[MAXN] ;
bool G[MAXN][MAXN] ;
int totCows , totStalls , totPath ; 
bool DFS( int s ){
	for( int i = 1 ; i <= totStalls ; i++ ){
		if( (!mark[i]) && G[s][i] ){
			mark[i] = true ;
			if( match[i] == 0 || DFS( match[i] )){
				match[i] = s ;
				return true ;
			}
		}
	}
	return false ;
}
int main(){
	cin >> totCows >> totStalls ;
	for( int  i = 1 ; i <= totCows ; i++ ){
		int degree ;
		cin >> degree ;
		for( int j = 1 ; j <= degree ; j++ ){
			int stall ;
			cin >> stall ;
			G[i][stall] = true ;
		}
	}
	for( int  i = 1 ; i <= totCows ; i++ ){
		memset( mark , false , sizeof(mark) ) ;
		if( DFS(i) )
		totPath++ ;
	}
	cout << totPath << endl ;
	return 0 ;
}
