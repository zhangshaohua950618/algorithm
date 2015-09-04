#include<fstream>
#include<string.h>
#define MAX(a , b) ((a) > (b) ? (a) : (b))
const int MAXN = 20 ;
int dp[MAXN][MAXN][MAXN] , path[MAXN][MAXN] ;
int N  , x , y , p ;
using namespace std ;
ifstream cin("1.in") ;
ofstream cout("1.out") ;
int getMax(int a , int b , int  c, int d){
	return MAX(MAX(MAX(a , b) , c) , d) ;
}
int main(){
	cin >> N;
	memset(dp , 0 , sizeof(dp));
	memset(path , 0 , sizeof(dp));
	while(cin >> x >> y >> p && x && y && p)
		path[x][y] = p ;
	
	
	for(int n = 1 ; n <= N * 2 ; n++)
	for(int i = 1 ; i <= N ; i++)
	for(int j = 1 ; j <= N ; j++)
	dp[n][i][j] = getMax(dp[n - 1][i][j] , dp[n - 1][i - 1][j] , dp[n - 1][i][j - 1] , dp[n - 1][i - 1][j - 1]) + path[i][n - i] + path[j][n - j];


	cout << dp[N * 2][N][N] << endl;	
	return 0 ;		
}

