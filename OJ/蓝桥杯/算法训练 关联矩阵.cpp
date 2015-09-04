#include<iostream>
using namespace std;
const int MAXN = 100 + 10 , MAXM = 100000 + 100; 
short matrix[MAXN][MAXM];
int m , n , s , t ;
int main(){
	int i , j;
	cin >> n >> m;
	for(i = 1 ; i <= m ; i++){
		cin >> s >> t;
		matrix[s][i] = 1;
		matrix[t][i] = -1;
	}
	for(i = 1 ; i <= n ; i++){
	for(j = 1 ; j < m ; j++)
	cout << matrix[i][j] << " ";
	cout << matrix[i][j] << endl;
	}
	return 0;
}
