#include<iostream>
#include<string.h>
#include<string>
#include<queue>
using namespace std ;
const int MAXN = 10 + 10 ;
struct P{
	int x ;
	int y ;
	int l ;
	P( int a , int b , int c ){
		x = a ;
		y = b ;
		l = c ;
	}
	P(){
		
	}
} ;
bool m[MAXN][MAXN] ;
int r ,  c , k , l , x , y  ;
P s , e , t ;
char b ;
string res ;
queue<P> q ;
int main(){
	int i , j ;
	while( cin >> r >> c >> k && r * c * k){
		while(!q.empty())//initial
		q.pop() ;
		for( i = 1 ; i <= r ; i++ )
		for( j = 1 ; j <= c ; j++ ){
			cin >> b ;
			switch(b){
				case 'S':{
					s.x = i ;
					s.y = j ;
					s.l = 0 ;
					m[i][j] = false ;
					break ;
				}
				case 'X':{
					m[i][j] = false ;
					break ;
				}
				case '.':{
					m[i][j] = true ;
					break ;
				}
				case 'D':{
					e.x = i ;
					e.y = j ;
					m[i][j] = true ; 
					break ;
				}
			}
		}
		q.push(s) ;
		while(!q.empty()){
			t= q.front() ;
			q.pop() ;
			x = t.x ;
			y = t.y ;
			l = t.l ;
			if(x == e.x && y == e.y)
			break ;
			if(m[x - 1][y]){
				q.push(P(x - 1 , y, l + 1)) ;
				m[x - 1][y] = false ; 
			}
			if(m[x + 1][y]){
				q.push(P(x + 1 , y, l + 1)) ;
				m[x + 1][y] = false ; 
			}
			if(m[x][y + 1]){
				q.push(P(x , y + 1 , l + 1)) ;
				m[x][y + 1] = false ; 
			}
			if(m[x][y -1]){
				q.push(P(x , y - 1 , l + 1)) ;
				m[x][y - 1] = false ; 
			}
		}
		res = l == k ? "NO" : "YES" ;
		cout << res << endl ;
	}
	return 0 ;
}





		
