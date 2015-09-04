#include<iostream>
#include<map>
using namespace std;
const int MAXN=5000+10;
struct Question{
	int time;
	int score;
};
#define Min(a,b) ((a)>(b)?(a):(b))
int f[MAXN];
int main(){
	int zhang , wang , mul;
	int tot_question , tot_kown ,tot_time ;
	int i , j ;
	cin>>zhang>>wang;
	mul = wang / zhang;
	Question q[MAXN];
	map<int , int> t;
	cin>>tot_question>>tot_kown;
	for(i = 1;i <= tot_kown; i++){
		int time;
		cin>>time;
		t[i] = time * mul;
	}
	for(i = 0;i < tot_question; i++){
		int number;
		cin>>number;
		q[i].time = t[number];
		cin>>q[i].score;
	}
	cin>>tot_time;
	for(i = 0;i < tot_question; i++)
	for(j = tot_time;j >= 0; j--){
		if(j >= q[i].time)
		f[j] = Min(f[j] , f[j - q[i].time] + q[i].score);
	}
	cout<<f[tot_time]<<endl;
	return 0;
}
