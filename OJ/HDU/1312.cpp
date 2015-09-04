#include<iostream>
#include<queue>
#include<string.h>
#include<string>
using namespace std ;
const int MAXN = 20 + 10 ;
struct P{
	int x ;
	int y ;
	P(int xx , int yy){
		x = xx ;
		y = yy ;
	}
	P(){}
} ;
P s,t;
queue<P> q ;
bool m[MAXN][MAXN] ;
int r , c  ,x , y ,sum ;
char k ;
int main(){
	int i , j ;
	while( cin >> c >> r &&  r * c ){
		memset(m , false , sizeof(m)) ;
		for( i = 1 ; i <= r ; i++ )
		for( j = 1 ; j <= c ; j++ ){
			cin >> k ;
			switch(k){
				case '@':{
					s.x = i ;
					s.y = j ;
					m[i][j] = false ;
					break ;
				}
				case '.':{
					m[i][j] = true ;
					break ;
				}
				case '#':{
					m[i][j] = false ;
					break ;
				}
			}
		}
		q.push(s) ;
		sum = 0 ;
		while( !q.empty() ){
			t = q.front() ;
			q.pop() ;
			sum++ ;
			x = t.x ;
			y = t.y ;
			if(m[x - 1][y]){
				q.push(P(x - 1 , y )) ;
				m[x - 1][y] = false ;
			}
			if(m[x + 1][y]){
				q.push(P(x + 1 , y )) ;
				m[x + 1][y] = false ;
			}
			if(m[x][y - 1]){
				q.push(P(x , y - 1 )) ;
				m[x][y - 1] = false ;
			}
			if(m[x][y + 1]){
				q.push(P(x  , y + 1 )) ;
				m[x][y + 1] = false ;
			}
		}
		cout << sum << endl ;
	}
	
}
