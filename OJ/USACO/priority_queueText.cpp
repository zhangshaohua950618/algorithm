#include<iostream>
#include<queue>
using namespace std ;
struct Node{
	int date ;
	int num ;
	friend bool operator < ( Node front , Node rear ){
		if( front.date != rear.date )
		return front.date < rear.date ;
		return front.num > rear.num ;
	}
} ;
Node node1 , node2 , node3 , node[100] ;
priority_queue<Node> q ;
int main(){
	 node1.date = 4 ;
	 node2.date = 5 ;
	 node3.date = 4 ;
	 node1.num = 5 ;
	 node2.num = 4 ;
	 node3.num = 3 ;
	q.push(node1) ;
	q.push(node2) ;
	q.push(node3) ;
		node[50].num = 100 ;
	q.push(node[50]) ;

	while(!q.empty()){
		Node temp ;
		temp = q.top() ;
		q.pop() ;
		cout << temp.date << " " << temp.num << endl ;
	}
	return 0 ;
	
	
	
}
