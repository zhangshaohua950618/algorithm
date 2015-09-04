#include<iostream>
#include<cstdlib>
using namespace std;
int num , res;
int gcd(int a , int b){
	return b?gcd(b,a%b):a;
}
int lcm(int a , int b){
	return a / gcd(a , b) * b;
}
int lcm(int a ,int b , int c){
	return lcm(lcm(a , b) , c);
}
int main(){
	int i;
	for(num = 1 ; num <= 100 ; num++){
		res = 0;
	for(i = 1 ; i <= num - 2 ; i++)
		res = max(res , lcm(i , i + 1 , i + 2));
	cout << num << " "<< res << endl;
	}
	return 0;
}
