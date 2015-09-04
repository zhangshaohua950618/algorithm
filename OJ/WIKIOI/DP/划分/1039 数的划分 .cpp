#include<iostream>
using namespace std ;
int plans[200+10][6+10];
int main(){
	int num , tot ;
	cin>>num>>tot;
	int i , j ;
	plans[0][0] = 1;
	for(i = 1 ; i <= num ; i++){
		for(j = 1; j <= tot ; j++){
			if(i >= j)
			plans[i][j] = plans[i - j][j] + plans[i - 1][j - 1];
		}
	}
	cout<<plans[num][tot]<<endl;
}
