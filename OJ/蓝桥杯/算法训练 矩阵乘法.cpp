#include<iostream>
using namespace std;
const int MAXN = 200 + 10;
int a[MAXN][MAXN] , b[MAXN][MAXN] , res[MAXN][MAXN];
int m , n , s;
int GetValue(int row , int col){
	int i;
	int sum = 0;
	for(i = 1 ; i <= s ; i++)
	sum += a[row][i] * b[i][col];
	return sum;
}
void Calulate(){
	int i , j , k;
	for(i = 1 ; i <= m ; i++)
	for(j = 1 ; j <= n ; j++)
	res[i][j] = GetValue(i , j);
}
int main(){
	int i , j;
	
	
	cin >> m >> s >> n;
	for(i = 1 ; i <= m ; i++)
	for(j = 1 ; j <= s ; j++)
	cin >> a[i][j];
	for(i = 1 ; i <= s ; i++)
	for(j = 1 ; j <= n ; j++)
	cin >> b[i][j];
	
	
	Calulate();
	
	
	for(i = 1 ; i <= m ; i++){
		for(j = 1 ; j < n ; j++)
		cout << res[i][j] << " ";
		cout << res[i][j] << endl;
	}
	
	
	return 0;
	
}
