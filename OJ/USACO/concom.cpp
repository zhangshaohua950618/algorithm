/*
ID:	zhangsh35
PROG:	concom
LANG:	C++
*/
#include<queue>
#include<fstream>
#include<string.h>
using namespace std ;
const int MAXN = 100 + 10 ;
struct Edge{
	int end ;
	int weight ;
} ;
Edge edge[MAXN][MAXN] ;
int path[MAXN][MAXN] ;
int degree[MAXN] ;	
bool inQue[MAXN] ;
int totEdge , start , end , weight , maxNode ;
queue<int> q ;
void Calculate( int s ){
	while(!q.empty())
	q.pop() ;
	memset( inQue , false , sizeof(inQue)) ;
	q.push(s) ;
	inQue[s] = true ;
	int i , j , k , temp , end , weight ;
	while(!q.empty()){
		temp = q.front() ;
		q.pop() ;
		for( i = 0 ; i < degree[temp] ; i++ ){
			end = edge[temp][i].end ;
			weight = edge[temp][i].weight ;
			path[s][end] += weight ;
			if( path[s][end] > 50 && (!inQue[end])){
			q.push(end) ;
			inQue[end] = true ;
			}
		}
	}
}
int main(){
	ifstream cin("concom.in") ;
	ofstream cout("concom.out") ;
	int i , j , k ; 
	cin >> totEdge ;
	for( i = 1 ; i  <= totEdge ; i++ ){
		cin >> start >> end >> weight ;
		edge[start][degree[start]].weight = weight ;
		edge[start][degree[start]].end = end ;
		degree[start]++ ;
		if( start > maxNode )
		maxNode = start ;
		if( end > maxNode )
		maxNode = end ;
	}
	for( i = 1 ; i <= maxNode ; i++ ){
		Calculate(i) ;
		for( j = 1 ; j <= maxNode ; j++ ){
			if(i == j)
			continue ;
			if( path[i][j] > 50 )
				cout << i << " " << j << endl ;
		}
	}
/*	for(i = 1 ; i <= maxNode ; i++ ){
		for( j = 1 ; j <= maxNode ; j++ )
		cout << path[i][j] << " ";
		cout << endl  ;
	}*/
	return 0 ;	
}
