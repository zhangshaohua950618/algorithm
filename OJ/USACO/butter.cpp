/*
ID: zhangsh35
PROG: butter 
LANG: C++
*/
#include<fstream>
#include<queue>
using namespace std ;
const int INF = 1 << 30 ;
struct Node{
	int end ;
	int weight ;
} ;
int value[800 + 10] ;
int cnt[800 + 10] ;
Node edge[800 + 10][100 + 10] ;
int dis[800 + 10];
bool inQueue[800 + 10] ;
queue<int> q ;
int totCow , totNode , totRoute , minPath = INF ;
int Spfa( int s ){
	int length = 0 ;
	int i , j  ,u ;
	for( i = 1 ; i <= totNode ; i++ )
	dis[i] = i == s ? 0 : INF  ;
	inQueue[s] = true ;
	q.push(s) ;
	while(!q.empty()){
		u = q.front() ;
		q.pop() ;
		inQueue[u] = false ;
		for( i = 0 ; i < cnt[u] ; i++ )
			if( dis[u] + edge[u][i].weight < dis[edge[u][i].end] ){
				dis[edge[u][i].end]  = dis[u] + edge[u][i].weight ;
				q.push(edge[u][i].end) ;
				inQueue[edge[u][i].end] = true ;
			}
	}
	for( i = 1 ; i <= totNode ; i++ )
	length += dis[i] * value[i] ;
	return length ;
}
int main(){
	ifstream cin("butter.in") ;
	ofstream cout("butter.out");
	int  i , j , cow , startNode , endNode , distance;
	cin>>totCow>>totNode>>totRoute ;
	for( i = 1 ; i <= totCow ; i++ ){
		cin>>cow ;
		value[cow]++ ;
	}
	for( i = 1 ; i <= totRoute ; i++ ){
		cin>>startNode>>endNode>>distance ;
		edge[startNode][cnt[startNode]].end = endNode ;
		edge[startNode][cnt[startNode]].weight = distance ;
		cnt[startNode]++ ;
		edge[endNode][cnt[endNode]].end = startNode ;
		edge[endNode][cnt[endNode]].weight = distance ;
		cnt[endNode]++ ;
	}
	for( i = 1 ; i <= totNode ; i++ )
	if( Spfa(i) < minPath )
	minPath = Spfa(i) ;
	cout<<minPath<<endl ;
	return 0;
}
