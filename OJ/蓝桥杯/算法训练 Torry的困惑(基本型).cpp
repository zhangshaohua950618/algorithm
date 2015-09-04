#include<iostream>
#include<string.h>
using namespace std;
const int MAXN = 2000001;
const int MOD = 50000;
int isPrime[MAXN] , prime[MAXN] , value[MAXN] , tot , n;
void Elur(){
	int i , j ;
	memset(isPrime , true , sizeof(isPrime));
	for(i = 2 ; i < MAXN ; i++){
		if(isPrime[i])
			prime[tot++] = i;
			for(j = 0 ; j  < tot ; j++){
				if(prime[j] * i > MAXN)
				break;
				isPrime[prime[j] * i] = false;
				if(i % prime[j] == 0)
				break;
			}
	}
}
int main(){
	int i , j ;
	Elur();
	value[0] = prime[0];
	for(i = 1 ;i < 100000 ; i++)
	value[i] = (value[i - 1] * prime[i]) % MOD;
	while(cin >> n)
	cout << value[n - 1] << endl;
	return 0 ;
}
