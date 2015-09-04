#include<iostream>
#include<string.h>
using namespace std;
const int MAXN  = 40;
bool is_prime[MAXN] , book[MAXN];
int prime[MAXN] , rs[MAXN];
int tot;
int n;
void print(){
	int i;
	for(i = 0 ; i < n - 1 ; i++)
	cout << rs[i] << " ";
	cout << rs[i] << endl;
}
void euler(){
	memset(is_prime , true , sizeof(is_prime));
	int i , j;
	for(i = 2; i < MAXN ; i++){
		if(is_prime[i])
		prime[tot++] = i;
		for(j = 0 ; j < tot ; j++){
			if(prime[j] * i >= MAXN)
			break;
			is_prime[prime[j] * i] = false;
			if(i % prime[j] == 0)
			break;
		}
	}
}
void dfs(int step){
	if(step == n){
		if(is_prime[rs[step - 1] + rs[0]])
		print();
		return;
	}
	int i;
	for(i = 1 ; i <= n ; i++){
		if(!book[i] && is_prime[i + rs[step - 1]]){
			book[i] = true;
			dfs(step + 1);
			book[i] = false;
		}
	}
	
} 
int main(){
	euler();
	for(int i = 0 ; i < tot ; i++){
		cout << prime[i] << " "; 
	}
	cout << endl;
	cin >> n;
	dfs(0);
	return 0;
}

