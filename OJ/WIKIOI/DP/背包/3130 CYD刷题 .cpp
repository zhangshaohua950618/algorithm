#include<iostream>
using namespace std;
struct Question{
	int a;
	int b;
	int c;
};
int f[500+10];
#define Max(a,b) ((a)>(b)?(a):(b))
int main(){
	int N , M , Q;
	Question q[100+10];
	cin>>N>>M>>Q;
	int i , j;
	for(i = 0;i < N; i++){
	cin>>q[i].a>>q[i].b>>q[i].c;
	if(q[i].c <= Q){
		for(j = M;j >= q[i].b; j--)
			f[j] = Max(f[j] , f[j - q[i].b] + q[i].a);
		}
	}
	cout<<f[M]<<endl;
	return 0;
}
