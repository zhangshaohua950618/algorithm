#include<iostream>
using namespace std;
int num;
int fib(int num){
	if(num < 3)
	return num;
	return fib(num - 1) + fib(num - 2);
}
int main(){
	cin >> num;
	cout << fib(num) << endl;
	return 0;
}
