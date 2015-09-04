/*
ID:		zhangsh35
PROG:	rockers
LANG:	C++
*/
#include<iostream>
#include<fstream>
using namespace std;
int dp[25][25][25];
int Max( int a , int b ){
	return a > b ? a : b ;
}
int main(){
	ifstream cin("rockers.in") ;
	ofstream cout("rockers.out") ;
	int totSongs , totCds , timeLimit ;
	int songs[25] ; 
	cin>>totSongs>>timeLimit>>totCds ;
	int i , j , k , time ;
	for(i = 1; i <= totSongs; i++){
		cin>>time ;
		for(j = 1; j <= totCds; j++)	
			for( k = 1; k <= timeLimit; k++){
				if(time > k)
				dp[i][j][k] = Max(dp[i - 1][j][k] ,dp[i][j - 1][timeLimit]);
				if(time < k)
				dp[i][j][k] = Max(dp[i - 1][j][k] , dp[i - 1][j][k - time] + 1 );
				if(time == k)
				dp[i][j][k] = Max(dp[i - 1][j][k] , dp[i -1][j - 1 ][timeLimit] + 1);
			}
		}
	cout<<dp[totSongs][totCds][timeLimit]<<endl;
}
