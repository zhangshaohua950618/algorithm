#include<iostream>
const int MAXN=1000+10;
using namespace std;
struct E{
	int t;
	int v;
	int g;
};
int f[MAXN][MAXN];
#define Min(a,b) ((a)>(b)?(a):(b))
int main(){
	E e[MAXN];
	int tot_v , tot_g , tot_e ;
	cin>>tot_v>>tot_g>>tot_e;
	int i , j , k;
	for(i = 0; i < tot_e; i++)
	cin>>e[i].t>>e[i].v>>e[i].g;
	for(i = 0;i < tot_e; i++)
	for(j =tot_v ; j >= 0; j--)
	for(k = tot_g ; k >= 0; k--)
	if(j - e[i].v >= 0 && k - e[i].g >= 0)
	f[j][k] = Min(f[j][k] , f[j - e[i].v][k - e[i].g] + e[i].t);
	cout<<f[tot_v][tot_g]<<endl;
	return 0;
}
