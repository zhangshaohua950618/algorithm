#include<iostream>
using namespace std;
int k[100000+10];
struct Question{
	int time;
	int score;
};
int f[100000+10];
#define Min(a,b) ((a)>(b)?(a):(b))
int main(){
	int tot_time , tot_question ;
	Question q[500+10];
	cin>>tot_time>>tot_question;
	int i , j , sum = 0;
	for(i = 0;i < tot_question; i++){
		cin>>q[i].time>>q[i].score;
		sum += q[i].score;
	}
	for(i = 0;i < tot_question ; i++){
		for(j = tot_time ; j >= 0 ;j--){
			if(j >= q[i].time)
			f[j] = Min(f[j], f[j - q[i].time]+q[i].score);
		}
	}
	cout<<sum - f[tot_time]<<endl;
	return 0;
	
}
