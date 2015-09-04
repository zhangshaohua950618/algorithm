#include<iostream>
#define Max(a,b)((a)>(b)?(a):(b))
using namespace std;
struct Pack{
	int cost;
	int score;
	int num;
};
int tot_p , tot_cost ;
int f[200000+10];
Pack p[200+10];
void ZeroOnePack(int cost , int  score){
	int i;
	for(i = tot_cost ; i >= cost ; i--)
	f[i] = Max(f[i] , f[i - cost] + score);
}
void CompletePack(int cost , int score){
	int i ;
	for(i = cost ; i <= tot_cost; i++)
	f[i] = Max(f[i] , f[i - cost] + score);
}
void MultiPack(int cost , int score , int num){
	int k = 1 ;
	if(cost * num >= tot_cost){
		CompletePack(cost , score);
		return ;
	}
	while(k < num){
		ZeroOnePack(cost * k , score * k);
		num -= k;
		k *= 2;
	}
	ZeroOnePack(num * cost , num * score );
}
int main(){
	cin>>tot_p>>tot_cost;
	int i ;
	for(i = 0;i < tot_p ; i++){
		cin>>p[i].cost>>p[i].score>>p[i].num;
		switch(p[i].num){
			case 1:ZeroOnePack(p[i].cost , p[i].score);break;
			case -1:CompletePack(p[i].cost , p[i].score);break;
			default :MultiPack(p[i].cost , p[i].score , p[i].num);break;
		}
	}
	cout<<f[tot_cost]<<endl;
	return 0;
	
}
