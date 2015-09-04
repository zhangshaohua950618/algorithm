#include<iostream>
#include<string.h>
using namespace std;
const int MAXN = 100;
bool maze[MAXN][MAXN];
int n , num , leftWhite[MAXN * 2] , rightWhite[MAXN * 2] , leftBlack[MAXN * 2] , rightBlack[MAXN * 2] , rowsWhite[MAXN] , rowsBlack[MAXN];
void print(){
	int i , j;
	for(i = 1 ; i <= n ; i++){
		for(j = 1 ; j <= n ; j++)
		cout << maze[i][j] << " ";
		cout << endl;
	}
}
void dfsBlack(int step){
	int i;
	if(step == n + 1){
		num++;
		return;
	}
	for(i = 1 ; i <= n ; i++){
		if(maze[i][step] && rightBlack[n + step - i] && leftBlack[step + i] && rowsBlack[i]){
		rowsBlack[i] = false;
		maze[i][step] = false;
		rightBlack[n + step - i] = false;
		leftBlack[step + i] = false;
		dfsBlack(step + 1);
		rowsBlack[i] = true;
		maze[i][step] = true;
		rightBlack[n + step - i] = true;
		leftBlack[step + i] = true;
		}
	}
}
void dfsWhite(int step){
	int i;
	if(step == n + 1){
		dfsBlack(1);
//		print();
		return;
	}
	//put queen
	for(i = 1 ; i <= n ; i++)
	if(maze[i][step] && rightWhite[n + step - i] && leftWhite[step + i] && rowsWhite[i]){
		rowsWhite[i] = false;
		maze[i][step] = false;
		rightWhite[n + step - i] = false;
		leftWhite[step + i] = false;
		dfsWhite(step + 1);
		rowsWhite[i] = true;
		maze[i][step] = true;
		rightWhite[n + step - i] = true;
		leftWhite[step + i] = true;
		}
}
int main(){
	int i , j;
	
	memset(rightWhite , true , sizeof(rightWhite));
	memset(leftWhite , true , sizeof(leftWhite));
	memset(rightBlack , true , sizeof(rightBlack));
	memset(leftBlack , true , sizeof(leftBlack));
	memset(rowsWhite , true , sizeof(rowsWhite));
	memset(rowsBlack , true , sizeof(rowsBlack));
	cin >> n;
	for(i = 1 ; i <= n ; i++)
		for(j = 1 ; j <= n ; j++){
		cin >> maze[i][j];
		if(!maze[i][j]){
			rowsWhite[i] = false;
			rowsBlack[i] = false;
		}
	}
	dfsWhite(1);
	cout << num << endl;
	return 0;
}
