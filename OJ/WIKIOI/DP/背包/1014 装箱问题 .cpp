#include<iostream>
using namespace std;
int number[30+10];
int f[20000+10];
int main(){
	int tot_v;
	int num;
	cin>>tot_v>>num;
	int i , j ;
	for(i = 0;i < num; i++){
		cin>>number[i];
		for(j = tot_v ;j >= number[i];j--){
			if(f[j - number[i]] + number[i] > f[j] && f[j - number[i]] + number[i] <= j)
			f[j] = f[j - number[i]] + number[i];
		}
	}
	cout<<tot_v-f[tot_v]<<endl;
}
