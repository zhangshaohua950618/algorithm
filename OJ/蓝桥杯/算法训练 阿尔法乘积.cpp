#include<iostream>
using namespace std;
string input;
long long num;


long long Get(long long num){
	long long res = 1;
	long long temp;
	while(num){
		temp = num % 10;
		if(temp)
		res *= temp;
		num /= 10;
	}
	return res;
}
int main(){
	int i;
	cin >> input;
	num = 1;
	for(i = 0 ;i < input.length() ; i++)
	if(input[i] != '0')
	num *= input[i] - '0';
	while(num / 10)
		num = Get(num);
	cout << num << endl;
	return 0;
}
