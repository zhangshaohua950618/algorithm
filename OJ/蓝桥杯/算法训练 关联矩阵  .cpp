#include<iostream>
using namespace std ;
const int MAXN = 1000 + 10 ;
int Matrix[MAXN][MAXN] ;
int totNode , totEdge , start , end  ;
int main(){
	int  i , j ;
	cin >> totNode >> totEdge ;
	for(  j = 1 ; j <= totEdge ; j++ ){
		cin >> start >> end ;
		Matrix[start][j] = 1 ;
		Matrix[end][j] = -1 ;
	}
	for(   i = 1 ; i <= totNode ; i++  ){
		for(   j = 1 ; j < totEdge ; j++ )
			cout << Matrix[i][j] << " " ;
			cout << Matrix[i][j] << endl ;
	}	
}
