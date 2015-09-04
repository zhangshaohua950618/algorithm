#include<iostream>
#include<string.h>
#include<map>
using namespace std;
map<char , int> m;
string num;
long long value = 1 , sum;
void Initial(){
	char i;
	for(i = '0' ; i <= '9' ; i++)
	m[i] = i - '0';
	m['A'] = 10;
	m['B'] = 11;
	m['C'] = 12;
	m['D'] = 13;
	m['E'] = 14;
	m['F'] = 15;
}
int main(){
	int i;
	cin >> num;
	Initial();
	for(i = num.length() - 1 ; i >= 0 ; i--){
		sum += m[num[i]] * value;
		value *= 16;
	}
	cout << sum << endl;
	return 0;
}
