/*
ID: zhangsh35
PROG: maze1 
LANG: C++
*/
#include<fstream>
#include<string.h>
#include<queue>
using namespace std ;
ifstream cin("maze1.in") ;
ofstream cout("maze1.out") ;
struct Node{
	int x ;
	int y ;
	int length ;
} ;
Node node[(150 * 2 + 10) * (40 * 2 + 10)] ;
queue<Node> q ;
int width , height ;
string input ;
bool maze[150 * 2 + 10][40 * 2 + 10] ;
Node current ;
void Input(){
	int i  , j ;
	cin >> width >> height ;
	getline( cin , input ) ;
	width = width * 2 + 1 ;
	height = height * 2 + 1 ;
	for( i = 1 ; i <= height ; i++ ){
		getline( cin , input ) ;
		for( j = 0 ; j < input.length() ; j++ )
		if( input[j] == ' ')
		maze[i][j + 1] = true ;
	}	
}
void GetStart(){
	int i , j ;
	Node node ;
	while(!q.empty())
	q.pop() ;
	for( i = 1 ; i <= width ; i++ ){
		if(maze[1][i]){
			node.x = 2 ;
			node.y = i ;
			node.length = 1 ;
			q.push(node) ;
		}
		if( maze[height][i]){
			node.x = height - 1  ;
			node.y = i ;
			node.length = 1 ;
			q.push(node) ;
		}	
	}
	for( i = 1 ; i <= height ; i++ ){
		if(maze[i][1]){
			node.x = i ;
			node.y = 2 ;
			node.length = 1 ;
			q.push(node) ;
		}
		if(maze[i][width]){
			node.x = i ;
			node.y = width - 1 ;
			node.length = 1 ;
			q.push(node) ;
		}
	}
}
void GetPathWay( Node previous ){
	int x , y ;
	x = previous.x ;
	y = previous.y ;
	Node next ;
	//Up
	if(maze[x - 1][y] && maze[x - 2][y]){
		maze[x - 1][y] = false ;
		maze[x - 2][y] = false ;
		next.x = x - 2 ;
		next.y = y ;
		next.length = previous.length + 1 ;
		q.push(next) ;
	}
	//down
	if(maze[x + 1][y] && maze[x + 2][y]){
		maze[x + 1][y] = false ;
		maze[x + 2][y] = false ;
		next.x = x + 2 ;
		next.y = y ;
		next.length = previous.length + 1 ;
		q.push(next) ;
	}
	//right 
	if(maze[x][y + 1] && maze[x][y + 2]){
		maze[x][y + 1] = false ;
		maze[x][y + 2] = false ;
		next.x = x ;
		next.y = y + 2 ;
		next.length = previous.length + 1 ;
		q.push(next) ;
	}
	//left
	if(maze[x][y - 1] && maze[x][y - 2]){
		maze[x][y - 1] = false ;
		maze[x][y - 2] = false ;
		next.x = x ;
		next.y = y - 2 ;
		next.length = previous.length + 1 ;
		q.push(next) ;
	}	
}  
int main(){
	Input() ;
	GetStart() ;
	while(!q.empty()){
		current = q.front() ;
		q.pop() ;
		GetPathWay(current) ;
	}
	cout << current.length << endl ;
}
