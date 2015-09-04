#include<iostream>
#include<string.h>
#include<sstream> 
using namespace std;
const int MAXN = 10000 + 10; 
bool isPrime[MAXN];
int prime[MAXN] , tot , l , h;
string str[MAXN];
string int2str(int num){
	stringstream i;
	i << num;
	return i.str();
}
void Elur(){
	int i , j;
	memset(isPrime , true , sizeof(isPrime));
	for(i =2  ; i < MAXN ; i++){
		if(isPrime[i])
		prime[tot++] = i;
		for(j = 0 ; j < tot ; j++){
			if(prime[j] * i > MAXN)
			break;
			isPrime[prime[j] * i] = false;
			if(i % prime[j] == 0)
			break;
		}
	}
} 
int main(){
	int i , j;
	Elur();
	for(i = 2 ; i < MAXN ; i++){
		if(isPrime[i]){
			str[i] = int2str(i);
		}
		else{
			for(j = 0 ; j < tot; j++){
				if(i % prime[j] == 0){
					str[i] = str[prime[j]] + "*" + str[i / prime[j]];
					break;
				}
			}
		}
	}
	cin >> l >> h;
	for(i = l ; i <= h ; i++)
		cout << i << "=" << str[i] << endl;
	return 0;
}

