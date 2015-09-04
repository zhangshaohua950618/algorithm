#include<iostream>
#include<string.h>
#include<math.h>
using namespace std ;
const int MAXN = 1001 + 10 ;
int par[MAXN] ;
struct Point{
	int x ;
	int y ;
	bool ok ;
};
double GetDis( Point a ,Point b ){
	return sqrt((double)pow(a.x - b.x,2) + (double)pow(a.y - b.y,2)) ;
}
Point point[MAXN] ;
int totPoint , maxDis ,rank[MAXN];
char command ;
int Find(int x){
	while( par[x] != x )
	x = par[x] ;
	return x ;
}
bool Same(int x , int y){
	return Find(x) == Find(y) ;
}
void Union( int x , int y){
	x = Find(x) ;
	y = Find(y) ;
	if(rank[x] < rank[y]){//short path
		par[x] = y ;
	}
	else{
		par[y] = x ;
		if(rank[x] == rank[y])
		rank[x]++ ;
	}
	
}
void Initial(){
	for( int i = 1 ; i <= totPoint ; i++ ){
		par[i] = i ;
		rank[i] = 1 ; 
	}
}
int main(){
	int i , j , p ,q ; 
	while( cin >> totPoint >> maxDis){
		for( i = 1 ; i <= totPoint ; i++ ){
			cin >> point[i].x >> point[i].y ;
			point[i].ok = false ;
		}
		Initial() ;
		while( cin >> command ){
			switch(command){
				case 'O':{
					cin >> p ;
					point[p].ok = true ;
					for( i = 1 ; i <= totPoint ; i++ ){
						if(point[i].ok && (GetDis(point[i],point[p])) <= maxDis)
						Union( p , i ) ;
					}
					break ;
				}
				case 'S':{
					cin >> p >> q ;
					if(Same(p , q))
					cout << "SUCCESS" << endl ;
					else
					cout << "FAIL" << endl ;
					break ;
				}
			}
		}
	}
}
