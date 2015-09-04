#include<iostream>
using namespace std;
const int MAXN = 100 + 10;
int a[MAXN][MAXN] , b[MAXN][MAXN];
int m , n; 
int main(){
	int i , j;
	cin >> m >> n;
	for(i = 1; i  <= m ; i++)
	for(j = 1; j  <= n ; j++)
	cin >> a[i][j];
	for(i = 1; i  <= m ; i++)
	for(j = 1; j  <= n ; j++)
	cin >> b[i][j];
	for(i = 1; i  <= m ; i++){
		for(j = 1; j  <= n ; j++)
			cout << a[i][j] + b[i][j] << " ";
		cout << endl;
	}
	return 0;
}
