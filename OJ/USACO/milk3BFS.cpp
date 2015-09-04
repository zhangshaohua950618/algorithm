#include<iostream>
#include<queue>
using namespace std ;
struct Node{
	int cupA ;
	int cupB ;
	int cupC ;
	int degree ;
	Node( int a , int b , int c , int d ){
		cupA = a ;
		cupB = b ;
		cupC = c ;
		degree = d ;
	}
} ;
queue<Node> q ;
int container[3] , amount ;
bool record[30] ;
void Input(){
	for( int i = 0 ; i < 3 ; i++ )
	cin >> container[i] ;
}
void Initial(){
	Node node( 0 , 0 , container[2] , 0 ) ;
	q.push(node) ;
}
void Pur( Node node ){

}
void Go(  ){
	
}
void OutPut(){
	for( int i = 0 ; i <= container[2] ; i++ ){
		if( record[i] )
		cout << i  ;
		sum++ ;
		if( sum == amount ){
			cout << endl ;
			exit(0) ;
		}
		else
		cout << " " ;
	}
}
int main(){
	Input() ;
	Initial() ;
	while( !q.empty()){
		Node  node = q.front() ;
		if( node.degree > 15 )
		OutPut() ;
		q.pop() ;
		Pur(node) ;
	}
	return 0 ;
	
	
}
