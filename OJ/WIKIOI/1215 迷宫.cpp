#include<iostream>
#include<queue>
#include<string.h>
using namespace std;
const int MAXN = 20;
int tot , rows;
bool ok;
char maze[MAXN][MAXN];
struct Node{
	int x;
	int y;
};
queue<Node> q;
void Output(){
	int i, j;
	for(i = 0 ; i < rows ; i++){
		for(j = 0 ; j < rows ; j++)
		cout << maze[i][j] << " ";
		cout << endl;
	}
}
bool Go(int x , int y){
	return maze[x][y] == '#';
}
int main(){
	int i , j , t;
	cin >> tot;
	for(t = 0 ;t < tot ; t++){
		cin >> rows;
		ok = false;
		
		
		while(!q.empty())
		q.pop();
		
		
		for(i = 0 ; i < rows ; i++)
		for(j = 0 ; j < rows ; j++){
			cin >> maze[i][j];
			if(maze[i][j] == 's')
			q.push((Node){i , j});
		}
		while(!q.empty()){
			Node temp = q.front();
			q.pop();
			int x = temp.x;
			int y = temp.y;
			if(maze[x][y] == 'e'){
				cout << "Yes";
				ok = true;
				break;
			}
			 
			if(x - 1 > 0 && Go(x - 1 , y))
			q.push((Node){x - 1 , y});
			
			if(y - 1 > 0 && Go(x , y - 1))
			q.push((Node){x , y - 1});
			
			if(x + 1 < rows && Go(x + 1 , y))
			q.push((Node){x + 1 , y});
			
			if(y + 1 < rows && Go(x , y + 1))
			q.push((Node){x , y + 1});
		
		}
		if(!ok)
		cout << "No";
	}
	
	return 0;
}
