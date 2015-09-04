#include<iostream>
using namespace std;
const int MAXN = 100 + 10;
bool maze[MAXN][MAXN];
int m , n , x , y , k;
char s;
void ChangeDirction(char direction){
	switch(direction){
		case 'R':{
			switch(s){
				case 'U':{s = 'R';break;}
				case 'D':{s = 'L';break;}
				case 'L':{s = 'U';break;}
				case 'R':{s = 'D';break;}
			}
			break;
		}
		case 'L':{
			switch(s){
				case 'U':{s = 'L';break;}
				case 'D':{s = 'R';break;}
				case 'L':{s = 'D';break;}
				case 'R':{s = 'U';break;}
			}
			break;
		}
		
	}
}
void MoveForward(){
	switch(s){
		case 'U':{x--;break;}
		case 'D':{x++;break;}
		case 'L':{y--;break;}
		case 'R':{y++;break;}
	}
	
}
void TurnRight(){
	ChangeDirction('R');
	maze[x][y] = 0;
	MoveForward();
}
void TurnLeft(){
	ChangeDirction('L');
	maze[x][y] = 1;
	MoveForward();
}
int main(){
	int i , j;
	
	
	cin >> m >> n;
	for(i = 0 ; i < m ; i++)
	for(j = 0 ; j < n ; j++)
	cin >> maze[i][j];
	cin >> x >> y >> s >> k;
	
	
	for(i = 1 ; i <= k ; i++)
		maze[x][y] ? TurnRight() :TurnLeft();
		
		
	cout << x << " " << y << endl;
	
		
	return 0;
}
