#include<iostream>
#include<string.h>
using namespace std;
string str;
long long data , value = 1;
int main(){
	cin >> str;
	for(int i = str.length() - 1 ; i >= 0 ; i--){
		data += value * (str[i] - '0');
		value *= 2; 
	}
	cout << data << endl;
	return 0;
}
