#include<iostream>
#include<string.h>
#include<queue>
using namespace std ;
const int MAXN = 100+ 10 ;
int dir[8][2] = {{ 1 , 0} , {-1 , 0} ,{0 , -1} , {0 , 1} , {1 , 1} , {1 , -1} , {-1 , 1} , { -1 , -1}} ;
struct P{
	int x ;
    int y ;
    int step ;
};
int r , l  , x , y ;
bool m[MAXN][MAXN] ;
void input(){
	char temp ;
	memset(m , false , sizeof(m)) ;
		for(int i = 1 ; i  <= r ; i++){
	     	  getchar() ;
	       for(int j = 1 ; j <= l ; j++){
	          temp = getchar() ;
              m[i][j] = temp == '.' ? true : false  ;
	     }   
       	}
}
int bfs(int x , int y){
	P p ;
	queue<P> q ;
	int  step = 0 ;
	while(!q.empty())
	q.pop() ;
	q.push((P){x , y , 0}) ;
	m[x][y] = false ;
	while(!q.empty()){
		p = q.front() ;
		q.pop() ;
		x = p.x ;
		y = p.y ; 
		step = p.step ;
	  for(int i = 0 ; i < 8 ; i++)
	  	if(m[x + dir[i][0]][y + dir[i][1]]){
	  	     q.push((P){x + dir[i][0] , y + dir[i][1] , step + 1}) ;	
	  	     m[x + dir[i][0]][y + dir[i][1]] = false  ;
		  }
	  	}
	return step ;
	
}
int main(){
	int i , j ;
	while(cin >> l >> r >> x >> y){
       input();
       cout <<	bfs(r - x + 1 , y) << endl ;
	}			
}

