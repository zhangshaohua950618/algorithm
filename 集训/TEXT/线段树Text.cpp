#include<iostream>
#include<string.h>
using namespace std ;
const int MAXN = 100000 + 10 ;
int value[MAXN] ;
int totNum , totQue ;
char command ;
int a , b , c ;
struct  Node{
	int left ;
	int right ;
	int value ;
	Node * leftchild ;
	Node * rightchild ;
} ;
int getValue( int  l ,int r ){//get initial value from l to r 
	return value[r] - value[l - 1] ;	
}
void addValue(Node * root , int a , int b, int value){//add value from a to b
		int mid = ( root->left + root->right) / 2 ;
		if(root->left == a && root->right == b){
		root->value += value ;
		}
		else if(b <= mid)
		addValue(root->leftchild , a , b , value );
		else if(a >= mid)
		addValue(root->rightchild , a, b , value ) ;
		else{
			addValue(root->leftchild, a , mid , value ) ;
			addValue(root->rightchild , b , mid , value ) ;
		}
}
Node * build(int l , int r){//build the tree 
	Node * root = new Node ;
	root->left = l ;
	root->right = r ;
	root->value = getValue(l,r) ;
	if( l + 1 < r ){
		int mid = ( l + r ) / 2 ;
		root->leftchild = build( l , mid ) ;
		root->rightchild = build( mid , r ) ;
	}
	return root ;
}
void initial(){//get initail sum 
	int sum = 0  ;
	for(int i = 1; i <= totNum ; i++ ){
		sum += value[i] ;
		value[i] = sum ;		
	}
}
int countValue(Node * root , int  a ,int b ){1
	int mid = ( root->left + root->right) / 2 ;
	if( a == root->left && b == root->right)
		return root->value ;
	else if(b <= mid)
		return countValue(root->leftchild , a , b );
	else if(a >= mid)
	    return countValue(root->rightchild , a, b  ) ;
	else{
		return 	countValue(root->leftchild, a , mid ) +	countValue(root->rightchild , b , mid  ) ;
	}	
}

int main(){
	
	while( cin >> totNum >> totQue ){
		initial() ;
		memset(value,0,sizeof(value)) ;
		Node * root = build(1,totNum) ;
		for( int i = 1; i <= totNum ;i++ )
		cin >> value[i] ;
		for( int i = 1 ; i <= totQue ; i++ ){
			cin >> command  ;
			switch(command){
				case 'C': {
					cin >> a >> b >> c ;
					addValue(root , a , b , c) ;
					break ;
				}
				case 'Q':{
					cin >> a >> b ;
					cout << countValue(root , a , b) << endl ;
					break ;
				}
			}
		}
		
	}
	return 0 ;
	
}
