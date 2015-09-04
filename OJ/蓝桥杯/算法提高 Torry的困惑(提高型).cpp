#include<iostream>
#include<string.h>
#include<cstdlib>
using namespace std;
const int MAXN = 2000000;
const int MOD = 50000;
bool isPrime[MAXN];
long long prime[MAXN],res[MAXN], tot , num;
void Elur(){
	int i , j;
	//all the number is prime
	memset(isPrime , true , sizeof(isPrime));
	for(i = 2 ;  i < MAXN ; i++){
		if(isPrime[i])
		prime[tot++] = i;
		for(j = 0 ; j < tot ; j++){
			if(prime[j] * i >= MAXN)
			break;
			isPrime[prime[j] * i] = false;
			if(i % prime[j] == 0)
			break;
		} 
	}
}
int main(){
	int i;
	Elur();
	cin >> num;
	res[0] = 2;
	for(i = 1 ; i < num ; i++)
	res[i] = (res[i - 1] % MOD * prime[i]) % MOD;
	cout << res[num - 1]<< endl;
	return 0;
	
}
