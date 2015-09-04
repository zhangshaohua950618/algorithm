#include<iostream>
#include<string.h>
using namespace std;
string str;
int result;
int main(){
	cin >> str;
	for(int i = 0 ; i < str.length() ; i++)
	if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'){
		result = i + 1;
		break;
	}
	cout << result<< endl;
	return 0;
	
}
