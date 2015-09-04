#include<iostream>
using namespace std;
struct Pack{
	int cost;
	int score;
};
#define Max(a,b) ((a)>(b)?(a):(b))
int main(){
	int tot_pack , tot_cost ;
	Pack p[100+10];
	int f[10000+10];
	int i , j;
	cin>>tot_pack>>tot_cost;
	for(i = 0;i < tot_pack; i++)
	cin>>p[i].cost;
	for(i = 0;i < tot_pack; i++)
	cin>>p[i].score;
	for(i = 0;i < tot_pack ;i++)
		for(j = tot_cost ; j >= p[i].cost  ; j--)
		f[j] = Max(f[j] , f[j - p[i].cost] + p[i].score);
	cout<<f[tot_cost]<<endl;
	return 0;
	
}
