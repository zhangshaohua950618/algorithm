#include<iostream>
using namespace std;
const int INF =100000;
int dis[20][20];
int dp[1 << 16][20];
int totCity;
int s ;
int minDis = INF;
#define MIN(a , b) ((a) < (b) ? (a) : (b))
void Floyd(){
	int i , j , k;
	for(k = 0 ; k <= totCity ; k++)
	for(i = 0 ; i <= totCity ; i++)
	for(j = 0 ; j <=  totCity ; j++)
	dis[i][j] = MIN(dis[i][j] , dis[i][k] + dis[k][j]);
};
void Dp(){
	int i , j ;
	dp[1][0] = 0;
	for(s = 3 ; s < 1 << (totCity + 1) ; s+=2)
		for(i = 1 ; i <= totCity ; i++)
			if(s & (1 << i)){
				if((s xor (1 << i)) == 1){
					dp[s][i] = dis[0][i];
					continue;
				}
				dp[s][i] = INF;
				for(j = 1 ; j <= totCity ; j++)
					if(((s) & (1 << j)) && (i != j))
						dp[s][i] = MIN(dp[s][i] , dp[((s) xor (1 << i))][j] + dis[j][i]);
			}
	for(i = 1 ; i <= totCity ; i++)
	minDis = MIN(minDis  ,  dp[(1 << (totCity + 1)) - 1][i] + dis[i][0]);
};
int main(){
	int i , j ;	
	cin>>totCity;
	for(i = 0 ; i <= totCity ; i++)
	for(j = 0 ; j <= totCity ; j++)
		cin>>dis[i][j];
	Floyd();
	Dp();
	cout<<minDis<<endl;
	return 0;
}
