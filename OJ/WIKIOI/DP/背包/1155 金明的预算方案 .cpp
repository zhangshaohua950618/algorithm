#include<iostream>
using namespace std;
int cost[60+5][3] , score[60+5][3];
int f[32000+10];
#define Max(a,b) ((a)>(b)?(a):(b))
int main(){
	int M , N;
	cin>>M>>N;
	int i , j;
	int c , s , n;
	for(i = 1;i <= N; i++){
		cin>>c>>s>>n;
		if(n){
			if(cost[n][1]){
				cost[n][2] = c;
				score[n][2] = s;
			}
			else{
			cost[n][1] = c;
			score[n][1] = s;
			}
 		}
 		else{
 			cost[i][0] = c;
 			score[i][0] = s;
		 }
	}
	for(i = 1;i <= N;i++){
		if(cost[i][0]){
			for(j = M ;j >= cost[i][0] ;j--){
				f[j] = Max(f[j] , f[j - cost[i][0]] + cost[i][0] * score[i][0]);
				if(cost[i][1] && j >=(cost[i][0] + cost[i][1]))
				f[j] = Max(f[j] , f[j - cost[i][0] - cost[i][1]] + cost[i][0] * score[i][0] + cost[i][1] * score[i][1]);
				if(cost[i][2] && j >=(cost[i][0] + cost[i][2]))
				f[j] = Max(f[j] , f[j - cost[i][0] - cost[i][2]] + cost[i][0] * score[i][0] + cost[i][2] * score[i][2]);
				if(cost[i][2] && j >=(cost[i][0] + cost[i][1] + cost[i][2]))
				f[j] = Max(f[j] , f[j - cost[i][0] - cost[i][1] - cost[i][2]] + cost[i][0] * score[i][0] + cost[i][1] * score[i][1] +cost[i][2] * score[i][2]);	
			}
		}
	}
	cout<<f[M]<<endl;
	
}
