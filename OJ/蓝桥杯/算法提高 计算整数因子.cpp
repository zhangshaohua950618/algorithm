#include<iostream>
#include<sstream>
#include<string.h>
#include<set>
using namespace std;
const int MAXN = 10000 + 10;
bool isPrime[MAXN];
set<int> s; 
int prime[MAXN] , tot;
string Translate(int num){
	 ostringstream s1;
	s1 << num;
	return s1.str();
} 
void Elur(){
	int i, j ;
	memset(isPrime , true , sizeof(isPrime));
	for(i = 2 ; i < MAXN ; i++){
		if(isPrime[i])
		prime[tot++] = i;
		for(j = 0 ; j < tot ; j++){
			if(i * prime[j] >= MAXN)
			break;
			isPrime[i * prime[j]] = false;
			if(i % prime[j] == 0)
			break;
		} 
	}
}
int num;
int main(){
	int i , j;
	Elur();
	cin >> num;
	while(num != 1){
	while(num % prime[i] == 0){
		num /= prime[i];
		s.insert(prime[i]);
	}
	i++;
	}
	for(set<int>::iterator it = s.begin() ; it != s.end() ; it++)
	cout << *it << " ";
	return 0;
}
