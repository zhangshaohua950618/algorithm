#include<iostream>
using namespace std;
int a , b;
int GetGcd(int a , int b){
	return b ? GetGcd(b , a % b) : a;
}
int main(){
	cin >> a >> b;
	cout << GetGcd(a , b) << endl;
	return 0;
}
