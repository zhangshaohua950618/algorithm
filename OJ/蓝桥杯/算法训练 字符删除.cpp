#include<iostream>
#include<string.h>
using namespace std;
string str;
char ch;
int main(){
	cin >> str;
	cin >> ch;
	for(int i = 0 ; i < str.length() ; i++){
		if(str[i] == ch)
		continue;
		cout << str[i];
	}
	cout << endl;
	return 0;
}
