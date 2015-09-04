#include<iostream>
using namespace std ;
const int MAXN = 30000 + 10 ;
int totCommand ,father , son  ;
int root[MAXN] ,leaf[MAXN] , rank[MAXN] ; 
char command ;
void Initial(){
	for( int i = 1 ; i < MAXN ; i++ ){
		root[i] = i ;
		leaf[i] = i ;
		rank[i] = 1; 
	}
	
}
int FindRoot(int x){
	while(root[x] != x )
	x = root[x] ;
	return x ;
}
int FindLeaf( int x){
	while(leaf[x] != x)
	x  = leaf[x] ;
	return x ;
}
void Union( int x , int y){
	int rootX = FindRoot(x) ;
	int leafY = FindLeaf(y) ;
	root[rootX] =  leafY;
	leaf[leafY] =  rootX;
}
int GetRank(int x){
	int count = 0 ;
	while(x != root[x]){
	//	cout << x << endl ;
		x = root[x] ;
		count++ ;
	}
	return count ;
}
int main(){
	while( cin >> totCommand ){
		Initial() ;
		for( int i = 0 ; i < totCommand ; i++ ){
			cin >> command ;
			switch(command){
				case 'M':{
					cin >> son >> father ;
					Union(son , father) ;
					break ;
				}
				case 'C':{
					cin >> son ;
					cout << GetRank(son) << endl  ;
					break ;
				}
			}
		}
	}
}
