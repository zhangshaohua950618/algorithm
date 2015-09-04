#include<iostream>
#include<string.h>
using namespace std;
string str;
int num;
int main(){
	cin >> str;
	for(int i = 0; i < str.length() ; i++){
		if(str[i] >= '0' && str[i] <= '9')
		num++;
	}
	cout << num << endl;
	return 0;
}
