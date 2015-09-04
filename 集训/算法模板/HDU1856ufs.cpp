#include<iostream>
#define MAX(a,b) ((a) > (b) ? (a) : (b))
using namespace std ;
const int MAXN = 10000000   + 10 ;
int par[MAXN] , rank[MAXN] ;
int totBoys , jack , mike , maxSet ;
void Initial(){
	for( int  i = 1 ; i < MAXN ; i++ ){
		par[i] = i ;
		rank[i] = 1 ;
	}
}
int Find(int x){
	while(x != par[x])
		x = par[x] ;
	return x ;
}
void Union( int x ,int y ){
	x = Find(x) ;
	y = Find(y) ;
	if(rank[x] < rank[y]){
		par[x] = y ;
		rank[y] += rank[x] ;
		maxSet = MAX( rank[y] , maxSet ) ;
	} 
	else{
		par[y] = x ;
		rank[x] += rank[y];
		maxSet = MAX( rank[x] , maxSet ) ;
	}
}
bool Same( int x , int y ){
	return Find(x) == Find(y) ;
}
int main(){
	while( cin >> totBoys ){
		Initial() ;
		maxSet = 1 ;
		for( int  i = 0 ; i < totBoys ; i++ ){
			cin >> jack >> mike ;
			if(!Same(jack,mike)){
				Union(jack,mike) ;
			}
		}
		cout << maxSet << endl ;
	}
	
	
}
