#include<iostream>
#include<string.h>
using namespace std ;
const int MAXN = 26 + 5 ;
struct Node{
	int data ;
	Node * lChild ;
	Node * rChild ;
} ;
char preOrder[26] ;
char inOrder[26] ;
void PostOrderTravel( Node *node ){
	if( node ){
		PostOrderTravel( node->lChild ) ;
		PostOrderTravel( node->lChild ) ;
		cout << node-> data << endl ;
	}
}
Node * TreeRecovery( char preOrder[] , char inOrder[] , int len ){
	
	
}
int main(){
	cin >> preOrder >> inOrder ;
	cout << preOrder << inOrder << endl ;
	
	
	
}
