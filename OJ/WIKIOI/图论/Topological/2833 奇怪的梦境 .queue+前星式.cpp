#include<iostream>
#include<queue>
using namespace std ;
struct Node{
	int head ;
	int degree ;
} ;
struct Edge{
	int start ;
	int end ;
	int next ;
} ;
Edge edge[25000 + 10];
Node node[10000 + 10];
int totNode , totEdge , pressedNode ;
queue<int> q ;
void Topological(){
	int n , e ;
	while(!q.empty()){
		n = q.front() ;
		q.pop() ; 
		pressedNode++ ;
		node[n].degree = -1 ;
		for(e = node[n].head ; e ; e = edge[e].next){
			node[edge[e].end].degree-- ;
			if(node[edge[e].end].degree == 0)
			q.push(edge[e].end) ;
		}
	}
}
int main(){
	int  i , j ;
	cin>>totNode>>totEdge ;
	for(i = 1 ; i <= totEdge ; i++){//Input
		cin>>edge[i].start>>edge[i].end ;
		edge[i].next = node[edge[i].start].head ;
		node[edge[i].start].head = i ;
		node[edge[i].end].degree++ ;
	}
	for(i = 1 ; i <= totNode ; i++){//Initial
		if(node[i].degree == 0){
			q.push(i);
		}
	}
	Topological() ;
	if(totNode - pressedNode == 0)
		cout<<"o(n_n)o"<<endl;
	else
		cout<<"T_T"<<endl<<totNode - pressedNode<<endl ;
	return 0;
	
}
