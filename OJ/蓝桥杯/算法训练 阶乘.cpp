#include<iostream>
using namespace std;
const int MOD = 1000000;
long long data = 1 , num;
int main(){
	cin >> num;
	for(int i = 1 ; i <= num ; i++){
		data *= i;
		while(data % 10 == 0)
		data /= 10;
		data %= MOD;
	}
	cout << data % 10 << endl;
	return 0;
}
