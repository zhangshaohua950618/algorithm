#include<iostream>
#include<string.h>
#define MAX(a , b) ((a) > (b) ? (a) : (b))
const int MAXN = 20 ;
int dp[MAXN][MAXN][MAXN] , path[MAXN][MAXN] ;
int N  , x , y , p ;
using namespace std ;
int getMax(int a , int b , int  c, int d){
	return MAX(MAX(MAX(a , b) , c) , d) ;
}
int main(){
	cin >> N;
	memset(dp , 0 , sizeof(dp));
	memset(path , 0 , sizeof(path));  
	while(cin >> x >> y >> p && x && y && p)
		path[x][y] = p ;
	dp[1][1][2] = path[1][1] ;
	dp[1][2][1] = path[1][1] ;
	
	for(int n = 2 ; n <= N * 2 - 1 ; n++)
	for(int i = 1 ; i <= N ; i++)
	for(int j = 1 ; j <= N ; j++)
	if(i != j)
	dp[n][i][j] = getMax(dp[n - 1][i][j] , dp[n - 1][i - 1][j] , dp[n - 1][i][j - 1] , dp[n - 1][i - 1][j - 1]) + path[i][n - i] + path[j][n - j];
	dp[N * 2][N][N] = getMax(dp[N * 2 - 1][N][N] , dp[N * 2 - 1][N - 1][N] , dp[N * 2 - 1][N][N - 1] , dp[N * 2 - 1][N - 1][N - 1]) + path[N][N];


	cout << dp[N * 2][N][N] << endl;	
	return 0 ;		
}

