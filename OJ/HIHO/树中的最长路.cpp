#include<iostream>
#include<vector>
#include<queue>
#include<string.h>
#define MAX( a , b ) ( (a) > (b) ? (a) : (b))
using namespace std ;
const int MAXN = 100000 * 2 + 10 ;
struct Node{
	int s ;
	int degree ;
} ;
vector<int> G[MAXN] ;
int totNode , from , to , maxLength ;
bool inQue[MAXN] ;
int dis[MAXN] ;
queue<Node> q ;
Node BFS( int s ){
	memset( inQue , false , sizeof(inQue)) ;
	Node maxNode  = (Node){ s , 0 };
	while(!q.empty())
	q.pop() ;
	q.push((Node){ s , 0 }) ;
	inQue[s] = true ;
	while(!q.empty()){
		Node cur = q.front() ;
		q.pop() ;
		if(cur.degree > maxNode.degree )
		maxNode = cur ;
		for( int  i = 0 ; i < G[cur.s].size() ; i++ ){
			if(!inQue[G[cur.s][i]]){
				q.push((Node){ G[cur.s][i] , cur.degree + 1 }) ;
				inQue[G[cur.s][i]] = true ;
			}
		}
	}
	return maxNode ;
}
int main(){
	cin >> totNode ;
	for( int  i = 1 ; i <= totNode- 1 ; i++ ){
		cin >> from >> to ;
		G[from].push_back(to) ;
		G[to].push_back(from) ;
	}
	cout << BFS(BFS(1).s).degree << endl ;
}
