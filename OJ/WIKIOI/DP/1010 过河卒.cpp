#include<iostream>
#include<string.h>
using namespace std ;
const int MAXN = 20 ;
const int dir[9][2] = {{0 , 0} ,{1 , 2},{2 , 1},{2 , -1},{1 , -2},{-1 , -2},{-2 , -1},{-2 , 1},{-1 , 2}} ;
int bx , by , hx , hy ;
int  dp[MAXN][MAXN] ;
bool vis[MAXN][MAXN] ;
int ans(){
	dp[0][0] = 1 ;
	for(int i = 0 ; i <= bx ; i++)
	for(int j = 0 ; j <= by ; j++){
		if(vis[i][j]){
		if(i - 1 >= 0)
		dp[i][j] += dp[i - 1][j] ;
		if(j - 1 >= 0)
		dp[i][j] += dp[i][j - 1] ;
		}
	}
	return dp[bx][by] ;
}
int main(){
	cin >> bx >> by >> hx >> hy ;
	
	
	memset(vis , true , sizeof(vis)) ;
	for(int i = 0 ; i  < 9 ; i++)
	vis[hx - dir[i][0]][hy - dir[i][1]] = false ; 
	memset(dp , 0 , sizeof(dp)) ;
	
	
	cout << ans() << endl  ;
	return 0 ;	
} 

