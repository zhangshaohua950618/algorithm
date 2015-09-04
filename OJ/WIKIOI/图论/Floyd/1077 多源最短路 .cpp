#include<iostream>
using namespace std;
const int MAXN = 100+10 ;
int dis[MAXN][MAXN] ;
int totPoint ;
#define MIN(a , b) ((a) < (b) ? (a) : (b))
int main(){
	std::ios::sync_with_stdio(false) ;
	int i , j , k ;
	int startPoint , endPoint , totQuestion ;
	cin>>totPoint ;
	for(i = 1 ; i <=totPoint ; i++)
		for(j = 1 ; j <=totPoint ; j++)
			cin>>dis[i][j] ;
	for(k = 1 ; k  <=totPoint ; k++)
		for(i = 1 ; i <= totPoint ; i++)
			for(j = 1 ; j<= totPoint ; j++)
			dis[i][j] = MIN(dis[i][j] , dis[i][k] + dis[k][j]);
	cin>>totQuestion;
	for(i = 1 ;i <= totQuestion ; i++){
		cin>>startPoint>>endPoint;
		cout<<dis[startPoint][endPoint]<<endl;
	}
	return 0;			
}
