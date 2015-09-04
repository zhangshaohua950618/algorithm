#include<iostream>
using namespace std;
struct Present{
	int prefer;
	int time;
	int num;
};
int f[10000+10];
# define Min(a,b) ((a)>(b)?(a):(b))
int main(){
	int tot_time = 0,tot_present = 0;
	int i , j , k ;
	Present p[100+10];
	cin>>tot_time>>tot_present;
	for(i = 0;i < tot_present; i++)
	cin>>p[i].time>>p[i].prefer>>p[i].num;
	for(i = 0;i < tot_present; i++)
	for(j = tot_time;j >= 0; j--){
		for( k = 1;k <= p[i].num ; k++){
			if( j - k*p[i].time < 0 )
			break;
			f[j] = Min( f[j] , f[j - k * p[i].time] + k * p[i].prefer);
		}
		
	}
	cout<<f[tot_time]<<endl;
	
}
