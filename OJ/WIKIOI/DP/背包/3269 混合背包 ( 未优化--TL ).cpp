#include<iostream>
using namespace std;
struct Bag{
	int v;
	int s;
	int n;
};
int f[200000 +10];
#define Max(a,b) ((a)>(b)?(a):(b))
int main(){
	Bag b[200+10];
	int tot_b , tot_v;
	cin>>tot_b>>tot_v;
	int i , j , k ;
	for(i = 0; i < tot_b ; i++)
	cin>>b[i].v>>b[i].s>>b[i].n;
	for(i = 0;i < tot_b ; i++){
		if(b[i].n != -1)
		for(j = tot_v; j>= 0 ; j--)
			for(k = 1; k <= b[i].n ; k++){
				if(j < b[i].v*k)
				break;
			f[j] = Max(f[j] , f[j - k * b[i].v] + k * b[i].s);
		}	
	}
	for(i = 0;i < tot_b; i++){
		if(b[i].n == -1){
			for(j = 0;j <=tot_v; j++)
			if(j >= b[i].v)
			f[j] = Max(f[j] , f[j - b[i].v] +  b[i].s);
			
		}
	}
	cout<<f[tot_v]<<endl;
	
	
}
