#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<math.h>
#include<string.h>
using namespace std;
typedef long long ll;
const ll MAXN = 2147483647;
const ll MAXL = 1000000 + 10;
ll num[MAXL];
int tot , l , r;
bool is_prime[MAXN] , prime[MAXN];
void Elur(){
	int i , j;
	ll limit = sqrt(MAXN);
	for(i = 2 ; i <=  limit; i++){
		if(is_prime[i])
			prime[tot++] = i;
			for(j = 0 ; j < tot ; j++){
				if(prime[j] * i > limit)
				break;
				is_prime[prime[j] * i] = false;
				if(i % prime[j] == 0)
				break;
			}
	}
}
int main(){
	Elur();
	cin >> l >> r;
	
	
}
