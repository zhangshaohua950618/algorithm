#include<iostream>
#include<string.h>
using namespace std; 
const int MAXN = 100 + 10;
const int dir[][2] = {{1 , 1} , {1 , -1} , {-1 , -1} , {-1 , 1} , {0 , 1} , {0 , -1} , {1 , 0} , {-1 , 0}}; 
int m , n , number;
bool map[MAXN][MAXN];
char c;
int GetNum(int i , int j){
	int num = 0 ;
	for(int k = 0 ; k < 8 ; k++)
		if(map[i + dir[k][0]][j + dir[k][1]] == 1)
		num++;
	return num;	
}
int main(){
	int i , j;
	while(cin >> n >> m && n){
		memset(map , 0, sizeof(map));
	for(i = 1 ; i <= n ; i++)
		for(j = 1 ; j <= m ; j++){
			cin >> c;
			if(c == '*')
			map[i][j] = 1;
			else if(c == '.')
			map[i][j] = 0;
		}
		
	cout << "Field #" << ++number << ":" << endl;
	for(i = 1 ; i <= n ; i++){
		for(j = 1 ; j <= m ; j++){
			if(map[i][j] == 1)
			cout << '*';
			else
			cout << GetNum(i , j);
		}
		cout << endl;
		}
		cout << endl;
	}
	return 0 ;
}
