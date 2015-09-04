#include<iostream>
using namespace std ;
const int MAXN= 3000 + 10 ;
int par[MAXN] , rank[MAXN] ;
int leader , totPerson , personNum ,totStudent , totGroup ;
int Find(int x){
	while( x != par[x] )
	x = par[x] ;
	return x ;
}
bool Same( int x , int y ){
	return Find(x) == Find(y) ;
}
void Union( int x , int y ){
		x = Find(x) ;
		y = Find(y) ;
		par[x] = y ;
		rank[y] += rank[x] ;
}
int main(){
	int i , j ;
	while( cin >> totStudent >> totGroup && totStudent != 0 ){
		for( i = 0 ; i < totStudent ; i++ ){ // Initial
			par[i] = i ;
			rank[i] = 1 ;
		}
		for( i = 0 ; i < totGroup ; i++ ){
			cin >> totPerson ;
			cin >> leader ;
			if( totPerson > 1 )
			for( j = 1 ; j < totPerson ; j++ ){
				cin >> personNum ;
				if( !Same( leader , personNum))
				Union(leader , personNum) ;
			}
		}
		cout << rank[par[0]] << endl ;
	}
}
