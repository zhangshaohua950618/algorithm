#include<iostream>
using namespace std;
struct Kown{
	int time;
	int score;
};
int t[10000+10];
# define Min(a,b) ((a)>(b)?(a):(b))
int main(){
	Kown k[5000+10];
	int tot_time , tot_k ;
	cin>>tot_k>>tot_time;
	int i , j ;
	for(i = 0;i < tot_k; i++){
		cin>>k[i].time>>k[i].score;
	}
	for(i = 0;i < tot_k; i++)
	for(j = tot_time;j >= 0; j--){
		if(j - k[i].time >= 0)
		t[j] = Min(t[j] , t[j - k[i].time] + k[i].score);
	}
	cout<<t[tot_time]<<endl;
	return 0;
	
}
