//#include<iostream>
#include<algorithm>
#include<fstream> 
#define MAX 20

using namespace std;
ifstream cin("1.in");
ofstream cout("1.out");
int main(){
	int n = 0 , p ;
	int num[MAX]; 
	int dp[MAX];
	int mark[MAX]; 
	
	while(cin>>num[n]){
		dp[n] = 1;
		mark[n] = 0;
		n++;
	}
	for(int i=1;i< n ;i++){ 
		p = -1 ;
		for(int j=0;j<i;j++){
			if( num[i] <=  num[j] && dp[j] >= dp[i] ){
				p = j ;
				dp[i] = dp[j] ;
			}
		}
		dp[i]++ ;
		if(p != -1 )
		mark[p]++ ;
		
	}
//	cout<<*max_element(dp,dp+n)<<endl;
	int count = 0;
	for(int i=0;i<n;i++){
		cout << dp[i] << " " << mark[i]<< endl ;
		if(mark[i] == 0)
			count++;
	}
//	cout<<count<<endl;
	
	return 0; 
} 

